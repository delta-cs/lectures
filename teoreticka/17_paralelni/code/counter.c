// compile: gcc -o counter counter.c -lpthread
// run: ./counter

#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>

int counter = 0;
pthread_mutex_t lock;

void *my_thread(void *arg) {
    char* threadName = (char *) arg;

    printf("%s: begin\n", threadName);
    int sum = 0;
    for (int i = 0; i < 1000000000; i += 1) {
        sum = sum + 1;
    }

    pthread_mutex_lock(&lock);
    counter = counter + sum;
    pthread_mutex_unlock(&lock);

    printf("%s: done\n", threadName);

    return NULL;
}

int main(int argc, char *argv[]) {
    pthread_t p1, p2;
    pthread_mutex_init(&lock, NULL);

    printf("main: begin (counter = %d)\n", counter);

    // start timer
    //clock_t start = clock();

    // create threads
    //
    // int pthread_create(
    //      pthread_t *restrict thread,
    //      const pthread_attr_t *restrict attr,
    //      void *(*start_routine)(void *),
    //      void *restrict arg
    // );
    pthread_create(&p1, NULL, my_thread, "A");
    pthread_create(&p2, NULL, my_thread, "B");

    // join waits for the threads to finish
    //
    // int pthread_join(pthread_t thread, void **retval);
    //
    pthread_join(p1, NULL);
    pthread_join(p2, NULL);

    printf("main: done with both (counter = %d)\n", counter);

    pthread_mutex_destroy(&lock);
    return 0;
}
