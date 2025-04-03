// compile: gcc -o fibonacci_openmp fibonacci_openmp.c -fopenmp

#include <stdio.h>
#include <time.h>
#include <omp.h>

#define ITERATIONS 100
#define FIBONACCI_INPUT 40
#define NUM_THREADS 4

typedef unsigned long long ull;

ull fib(int n) {
    if (n <= 1) {
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}

double time_diff_sec(struct timespec start, struct timespec end) {
    return (end.tv_sec - start.tv_sec) +
           (end.tv_nsec - start.tv_nsec) / 1e9;
}

int main() {
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    #pragma omp parallel for num_threads(NUM_THREADS)
    for (int i = 0; i < ITERATIONS; i++) {
        printf("%d: %llu\n", i, fib(FIBONACCI_INPUT));
    }

    clock_gettime(CLOCK_MONOTONIC, &end);

    double elapsed = time_diff_sec(start, end);
    printf("Elapsed time: %f\n", elapsed);

    return 0;
}