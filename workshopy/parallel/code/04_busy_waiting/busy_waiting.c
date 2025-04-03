// compile: gcc -o busy_waiting busy_waiting.c -lpthread

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

// A single mutex to protect shared resources
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* producer(void* arg) {
    for (int i = 0; i < 10; ++i) {
        // Busy-wait until there's room in the buffer
        while (1) {
            pthread_mutex_lock(&mutex);
            if (count < BUFFER_SIZE) {
                // There's space, so produce
                buffer[in] = i;
                printf("Produced: %d\n", i);
                in = (in + 1) % BUFFER_SIZE;
                count++;
                pthread_mutex_unlock(&mutex);
                break;  // stop spinning, produced successfully
            }
            pthread_mutex_unlock(&mutex);
            // If the buffer was full, spin (do nothing) and try again
        }

        // Simulate production time
        usleep(PRODUCE_TIME);
    }

    return NULL;
}

void* consumer(void* arg) {
    for (int i = 0; i < 10; ++i) {
        // Busy-wait until there’s something in the buffer
        while (1) {
            pthread_mutex_lock(&mutex);
            if (count > 0) {
                // There's an item, so consume
                int item = buffer[out];
                printf("Consumed: %d\n", item);
                out = (out + 1) % BUFFER_SIZE;
                count--;
                pthread_mutex_unlock(&mutex);
                break;  // stop spinning, consumed successfully
            }
            pthread_mutex_unlock(&mutex);
            // If the buffer was empty, spin (do nothing) and try again
        }

        // Simulate consumption time
        usleep(CONSUME_TIME);
    }

    return NULL;
}

int main() {
    pthread_t producer_thread, consumer_thread;

    // Create the producer and consumer threads
    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);

    // Wait for both threads to finish
    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    return 0;
}
