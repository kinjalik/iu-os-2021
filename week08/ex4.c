#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>

int main() {
    int *ptr = NULL;
    const int mb = 1024 * 1024;

    for (int i = 0; i < 10; i++) {
        ptr = malloc(10 * mb);
        memset(ptr, 0, 10 * mb);

        struct rusage usage;
        getrusage(RUSAGE_SELF, &usage);
        printf("Memory of process: %ld", usage.ru_maxrss);
        sleep(1);
    }
    free(ptr);
    return 0;
}
