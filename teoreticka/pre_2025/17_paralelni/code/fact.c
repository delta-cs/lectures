#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

typedef unsigned long long ull;

typedef struct {
    int resultId;
    int from;
    int to;
} ThreadArguments;

//#define THREADS 1
//#define THREADS 2
//#define THREADS 5
//#define THREADS 10
#define THREADS 20

ull results[THREADS];

ull fact(int n) {
    ull fact = 1;
    for (int i = 1; i <= n; i++) {
        fact = fact * i;
    }
    return fact;
}

ull fact_ft(int from, int to) {
    ull fact = 1;
    for (int i = from; i <= to; i++) {
        fact = fact * i;
    }
    return fact;
}

void *fact_ft_parallel(void *args) {
    ThreadArguments *thread_args = (ThreadArguments *) args;
    results[thread_args->resultId] = fact_ft(thread_args->from, thread_args->to);
    return NULL;
}

ull fact_parallel(int n) {
    ThreadArguments args[THREADS];
    pthread_t thread_id[THREADS];

    for (int i = 0; i < n/10; i++) {
        // calculate from and to
        int from = i * (n / THREADS) + 1;
        int to = (i + 1) * (n / THREADS);
        if (i == THREADS - 1) {
            to = n;
        }

        // create thread arguments
        args[i].resultId = i;
        args[i].from = from;
        args[i].to = to;

        // create thread
        pthread_create(&thread_id[i], NULL, fact_ft_parallel, &args[i]);
    }

    for (int j = 0; j < THREADS; j++) {
        pthread_join(thread_id[j], NULL);
    }

    ull result = 1;
    for (int k = 0; k < THREADS; k++) {
        result = result * results[k];
    }

    return result;
}

int main(int argc, char **argv) {
    // result will not be correct
    int n = 60;

    // call sequential fact

    struct timespec start, finish;
    long seconds, nanoseconds;
    double elapsed;

    clock_gettime(CLOCK_MONOTONIC, &start);
    printf("fact(%d) = \t\t%llu\n", n, fact(n));
    clock_gettime(CLOCK_MONOTONIC, &finish);

    seconds = finish.tv_sec - start.tv_sec;
    nanoseconds = finish.tv_nsec - start.tv_nsec;
    elapsed = seconds + nanoseconds * 1e-9;

    // call parallel fact

    struct timespec startp, finishp;
    long secondsp, nanosecondsp;
    double elapsedp;

    clock_gettime(CLOCK_MONOTONIC, &startp);
    printf("fact_parallel(%d) = \t%llu\n", n, fact_parallel(n));
    clock_gettime(CLOCK_MONOTONIC, &finishp);

    secondsp = finishp.tv_sec - startp.tv_sec;
    nanosecondsp = finishp.tv_nsec - startp.tv_nsec;
    elapsedp = secondsp + nanosecondsp * 1e-9;

    printf("Sequential Time: \t%f\n", elapsed);
    printf("Parallel Time: \t\t%f\n", elapsedp);

    return 0;
}