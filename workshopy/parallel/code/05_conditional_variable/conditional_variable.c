// compile: gcc -o conditional_variable conditional_variable.c -lpthread

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define BUFFER_SIZE 5
#define PRODUCE_TIME 5000000 // (5s)
#define CONSUME_TIME 250000 // (250 ms)

int buffer[BUFFER_SIZE];
int count = 0;
int in = 0;
int out = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t not_full  = PTHREAD_COND_INITIALIZER;
pthread_cond_t not_empty = PTHREAD_COND_INITIALIZER;

void* producer(void* arg) {
    for (int i = 0; i < 10; ++i) {
        pthread_mutex_lock(&mutex);

        // Wait until buffer is not full
        while (count == BUFFER_SIZE) {
            pthread_cond_wait(&not_full, &mutex);
        }

        // Produce an item
        buffer[in] = i;
        printf("Produced: %d\n", i);
        in = (in + 1) % BUFFER_SIZE;
        count++;

        // Signal that buffer is not empty
        pthread_cond_signal(&not_empty);
        pthread_mutex_unlock(&mutex);

        // Simulate production time
        usleep(PRODUCE_TIME);
    }

    return NULL;
}

void* consumer(void* arg) {
    for (int i = 0; i < 10; ++i) {
        pthread_mutex_lock(&mutex);

        // Wait until buffer is not empty
        while (count == 0) {
            pthread_cond_wait(&not_empty, &mutex);
        }

        // Consume an item
        int item = buffer[out];
        printf("Consumed: %d\n", item);
        out = (out + 1) % BUFFER_SIZE;
        count--;

        // Signal that buffer is not full
        pthread_cond_signal(&not_full);
        pthread_mutex_unlock(&mutex);

        // Simulate consumption time
        usleep(CONSUME_TIME);
    }

    return NULL;
}

int main() {
    pthread_t producer_thread, consumer_thread;

    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);

    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    return 0;
}
