// compile with: gcc -o counter_fixed counter_fixed.c -lpthread

#include <stdio.h>
#include <time.h>
#include <pthread.h>

#define ITERATIONS 100000
#define NUM_THREADS 4

typedef unsigned long long ull;

typedef struct {
    int start_idx;
    int end_idx;
} ThreadArgs;

ull counter = 0;
pthread_mutex_t counter_mutex = PTHREAD_MUTEX_INITIALIZER;

void *worker(void *arg) {
    ThreadArgs *args = (ThreadArgs *) arg;

    for (int i = args->start_idx; i < args->end_idx; ++i) {
        pthread_mutex_lock(&counter_mutex);
        counter++;
        pthread_mutex_unlock(&counter_mutex);
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

    printf("Counter: %llu, expected: %d\n", counter, ITERATIONS);

    double elapsed = time_diff_sec(start, end);
    printf("Elapsed time: %f\n", elapsed);

    return 0;
}
