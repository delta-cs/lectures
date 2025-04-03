// compile with: gcc -o matrix matrix.c -lpthread

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ~30s to compute
#define N 2000

double time_diff_sec(struct timespec start, struct timespec end) {
    return (end.tv_sec - start.tv_sec) +
           (end.tv_nsec - start.tv_nsec) / 1e9;
}

// -- MODIFY HERE start --

void multiply_matrices(double *a, double *b, double *c, size_t n) {
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            c[i * n + j] = 0.0;
            for (size_t k = 0; k < n; ++k) {
                c[i * n + j] += a[i * n + k] * b[k * n + j];
            }
        }
    }
}

// -- MODIFY HERE end --

int main() {
    // Allocate memory for matrices
    double *a = malloc(N * N * sizeof(double));
    double *b = malloc(N * N * sizeof(double));
    double *c = malloc(N * N * sizeof(double));

    if (!a || !b || !c) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Initialize matrices a and b with random values
    srand(time(NULL));
    for (size_t i = 0; i < N * N; ++i) {
        a[i] = rand() / (double)RAND_MAX;
        b[i] = rand() / (double)RAND_MAX;
        c[i] = 0.0;
    }

    printf("Starting matrix multiplication...\n");

    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    // Perform matrix multiplication
    multiply_matrices(a, b, c, N);

    clock_gettime(CLOCK_MONOTONIC, &end);
    double elapsed = time_diff_sec(start, end);

    printf("Multiplication completed in %.2f seconds\n", elapsed);

    // Clean up
    free(a);
    free(b);
    free(c);
    return 0;
}
