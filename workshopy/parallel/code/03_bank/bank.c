// compile with: gcc -o bank bank.c -lpthread

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

typedef struct {
    int id;
    int balance;
    pthread_mutex_t lock;
} Account;

Account accountA = {
        .id = 0,
        .balance = 1000,
        .lock = PTHREAD_MUTEX_INITIALIZER
};

Account accountB = {
        .id = 1,
        .balance = 1000,
        .lock = PTHREAD_MUTEX_INITIALIZER
};

void transfer(Account *from, Account *to, int amount) {
    pthread_mutex_lock(&from->lock);
    printf("Locked source account id=%d\n", from->id);

    // Simulate some processing time
    sleep(1);

    pthread_mutex_lock(&to->lock);
    printf("Locked destination account id=%d\n", to->id);

    from->balance -= amount;
    to->balance += amount;

    printf("Transferred %d from account id=%d to account id=%d\n",
           amount, from->id, to->id);

    pthread_mutex_unlock(&to->lock);
    pthread_mutex_unlock(&from->lock);
}

void *thread_func1(void *arg) {
    transfer(&accountA, &accountB, 100);
    return NULL;
}

void *thread_func2(void *arg) {
    transfer(&accountB, &accountA, 50);
    return NULL;
}

int main() {
    pthread_t t1, t2;

    pthread_create(&t1, NULL, thread_func1, NULL);
    pthread_create(&t2, NULL, thread_func2, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}
