// compile with: gcc -o fibonacci_pthread fibonacci_pthread.c -lpthread

#include <stdio.h>
#include <time.h>
#include <pthread.h>

#define ITERATIONS 100
#define FIBONACCI_INPUT 40
#define NUM_THREADS 4

typedef unsigned long long ull;

typedef struct {
    int start_idx;
    int end_idx;
} ThreadArgs;

ull fib(int n) {
    if (n <= 1) {
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}

void *worker(void *arg) {
    ThreadArgs *args = (ThreadArgs *) arg;

    for (int i = args->start_idx; i < args->end_idx; ++i) {
        ull result = fib(FIBONACCI_INPUT);
        printf("%d: %llu\n", i, result); // Unsafe, but fast
    }

    return NULL;
}

double time_diff_sec(struct timespec start, struct timespec end) {
    return (end.tv_sec - start.tv_sec) +
           (end.tv_nsec - start.tv_nsec) / 1e9;
}

int main() {
    pthread_t threads[NUM_THREADS];
    ThreadArgs thread_args[NUM_THREADS];

    int base_work = ITERATIONS / NUM_THREADS;
    int remainder = ITERATIONS % NUM_THREADS;

    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    int offset = 0;
    for (int i = 0; i < NUM_THREADS; ++i) {
        int work = base_work + (i < remainder ? 1 : 0);
        thread_args[i].start_idx = offset;
        thread_args[i].end_idx = offset + work;
        offset += work;

        pthread_create(&threads[i], NULL, worker, &thread_args[i]);
    }

    for (int i = 0; i < NUM_THREADS; ++i) {
        pthread_join(threads[i], NULL);
    }

    clock_gettime(CLOCK_MONOTONIC, &end);

    double elapsed = time_diff_sec(start, end);
    printf("Elapsed time: %f\n", elapsed);

    return 0;
}