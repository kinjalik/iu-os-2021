#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    int n = 10;
    for (int i = 0; i < n; i++) {
        void* t = malloc(10 * 1024 * 1024);
        t = memset(t, 0, 10 * 1024 * 1024);
        sleep(1);
    }
    return 0;
}

