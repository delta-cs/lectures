#include <stdio.h>
#include <stdlib.h>
//#include <pthread.h>
#include <omp.h>
#include <time.h>

#define THREADS 4
#define THREAD_JOB_ROWS 150

// define matrix structure
typedef struct {
    int rows;
    int cols;
    int **data;
} Matrix;
// struct for queue data containing row number ans pointer to matrix a and matrix b
typedef struct {
    int rowStart;
    int rowEnd;
    Matrix *a;
    Matrix *b;
    Matrix *c;
} QueueData;

// dynamic array struct for QueueData
typedef struct {
    QueueData **data;
    int size;
    int capacity;
} QueueDataArray;

QueueDataArray queue;

// add one element to global data structure named queue
void add_to_queue_data_array(QueueData *data) {

    if (queue.size == queue.capacity) {
        queue.capacity *= 2;
        queue.data = (QueueData **) realloc(queue.data, queue.capacity * sizeof(QueueData *));
    }

    queue.data[queue.size++] = data;
}

// init matrix
Matrix *init_matrix(int rows, int cols) {
    Matrix *matrix = (Matrix *) malloc(sizeof(Matrix));
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->data = (int **) malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix->data[i] = (int *) malloc(cols * sizeof(int));
    }
    return matrix;
}

// standard O(n^3) matrix multiplication
Matrix *matrix_multiply(Matrix *a, Matrix *b) {
    Matrix *c = init_matrix(a->rows, b->cols);

    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < b->cols; j++) {
            int sum = 0;
            for (int k = 0; k < b->rows; k++) {
                sum += a->data[i][k] * b->data[k][j];
            }
            c->data[i][j] = sum;
        }
    }

    return c;
}

// matrix_multiply_parallel_thread using global queue and mutex
// doing partial matrix multiplication (using only one row from matrix a)
// and all columns from matrix b, writing result to matrix c
// wait for mutex, dequeue, unlock mutex, but when queue is empty, return
// elimitate possible deadlocks, use busy waiting, ensure, that all threads finish
// use mutext to lock queue, but also ensure, that no deadlock can happen (e.g. when
// one thread is waiting for mutex, but other threads are waiting for this mutex, but
// no job will be added to queue)
void matrix_multiply_parallel_thread(QueueData job) {
    int rowStart = job.rowStart;
    int rowEnd = job.rowEnd;
    Matrix *a = job.a;
    Matrix *b = job.b;
    Matrix *c = job.c;

    for (int i = rowStart; i < rowEnd; i++) {
        for (int j = 0; j < b->cols; j++) {
            int sum = 0;
            for (int k = 0; k < b->rows; k++) {
                sum += a->data[i][k] * b->data[k][j];
            }
            c->data[i][j] = sum;
        }
    }
}

// parallel matrix multiplication using multiple threads and queue data structure
Matrix *matrix_multiply_parallel(Matrix *a, Matrix *b) {
    Matrix *c = init_matrix(a->rows, b->cols);

    // enqueue all jobs (all rows from matrix a)
    // each job should contain 5 rows from matrix a to process
    int i = 0;
    for (; i + THREAD_JOB_ROWS < a->rows; i += THREAD_JOB_ROWS) {
        QueueData *data = (QueueData *) malloc(sizeof(QueueData));
        data->rowStart = i;
        data->rowEnd = i + THREAD_JOB_ROWS;
        data->a = a;
        data->b = b;
        data->c = c;
        add_to_queue_data_array(data);
    }

    // handle remaining rows (if rows is not multiple of 5)
    // i will be strictly higher after the last for loop iteration
    if (i + THREAD_JOB_ROWS > a->rows) {
        QueueData *data = (QueueData *) malloc(sizeof(QueueData));
        data->rowStart = i - THREAD_JOB_ROWS;
        data->rowEnd = a->rows;
        data->a = a;
        data->b = b;
        data->c = c;
        add_to_queue_data_array(data);
    }

    // print quue size
    printf("Queue size: %d\n", queue.size);

    #pragma omp parallel for num_threads(THREADS) schedule(dynamic) default(none) shared(queue)
    for (int j = 0; j < queue.size; j++) {
        printf("Thread %d processing job %d\n", omp_get_thread_num(), j);
        QueueData job = *queue.data[j];
        matrix_multiply_parallel_thread(job);
    }

    return c;
}

// function that generates a random matrix of size n x m
Matrix *generate_matrix(int n, int m) {
    Matrix *matrix = init_matrix(n, m);
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            matrix->data[i][j] = rand() % 10;
        }
    }
    return matrix;
}

// print matrix
void print_matrix(Matrix matrix) {
    printf("Matrix: \n");
    for (int i = 0; i < matrix.rows; i++) {
        printf("[");
        for (int j = 0; j < matrix.cols; j++) {
            printf("%d ", matrix.data[i][j]);
        }
        printf("]\n");
    }
}

int compare_matrices(Matrix *a, Matrix *b) {
    if (a->rows != b->rows || a->cols != b->cols) {
        return 0;
    }

    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < a->cols; j++) {
            if (a->data[i][j] != b->data[i][j]) {
                return 0;
            }
        }
    }

    return 1;
}

int main() {
    Matrix *a = generate_matrix(2000, 2000);
    Matrix *b = generate_matrix(2000, 2000);

    // call classic matrix multiplication

//    struct timespec start, finish;
//    long seconds, nanoseconds;
//    double elapsed;
//
//    clock_gettime(CLOCK_MONOTONIC, &start);
//    Matrix *c = matrix_multiply(a, b);
//    clock_gettime(CLOCK_MONOTONIC, &finish);
//
//    seconds = finish.tv_sec - start.tv_sec;
//    nanoseconds = finish.tv_nsec - start.tv_nsec;
//    elapsed = seconds + nanoseconds * 1e-9;

    // call parallel matrix multiplication

    struct timespec startp, finishp;
    long secondsp, nanosecondsp;
    double elapsedp;

    clock_gettime(CLOCK_MONOTONIC, &startp);
    Matrix *cp = matrix_multiply_parallel(a, b);
    clock_gettime(CLOCK_MONOTONIC, &finishp);

    secondsp = finishp.tv_sec - startp.tv_sec;
    nanosecondsp = finishp.tv_nsec - startp.tv_nsec;
    elapsedp = secondsp + nanosecondsp * 1e-9;

//    printf("Sequential Time: \t%f\n", elapsed);
    printf("Parallel Time: \t\t%f\n", elapsedp);

    // check results matrices
//    if (compare_matrices(c, cp)) {
//        printf("Matrices are equal\n");
//    } else {
//        printf("Matrices are not equal\n");
//    }

    return 0;
}
