#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int false = 0;
int true = 1;

int capacity = 5;
int count = 0;

int data[5];

void* producer(void* arg) {
    while (true) {
        while (count >= capacity) {};
        data[count] = rand();
        count++;
    }
}

void* consumer(void* arg) {
    while (true) {
        while (count <= 0) {};
        data[count] = rand();
        count--;
    }
}

int main() {
    pthread_t rproducer, rconsumer;
    pthread_create(&rconsumer, NULL, consumer, NULL);
    pthread_create(&rproducer, NULL, consumer, NULL);

    pthread_join(rproducer, NULL);
    pthread_join(rconsumer, NULL);
    
    return 0;
}
