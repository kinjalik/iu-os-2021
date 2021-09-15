#include <pthread.h>
#include <stdio.h>
#include <malloc.h>

void* function_in_thread(void* param) {
    pthread_exit(0);
}

int main () {

    int n = 10;
    for (int i = 0; i < n; i++) {
        char* ns = calloc(42 * sizeof(char), 0);
        sprintf(ns, "%d", i);
        pthread_t tid;
        pthread_create(&tid, NULL, function_in_thread, &ns);
        printf("Thread %d created.\n", i);
        pthread_join(tid, NULL); // Add in order to execute threads consequently
    }
}

