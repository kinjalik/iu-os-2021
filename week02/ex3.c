#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    char* number = argv[1];
    int n;
    sscanf(number, "%d", &n);

    int width = 2 * n - 1;

    char* current = (char*) malloc(sizeof(char) * width);
    for (int i = 0; i < width; i++)
        current[i] = ' ';

    for (int i = 0; i < n; i++) {
        current[n - i] = '*';
        current[n + i] = '*';
        printf("%s\n", current);
    }


    free(current);
    return 0;
}

