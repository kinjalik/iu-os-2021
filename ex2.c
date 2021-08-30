#include <stdio.h>
#include <stdlib.h>

int main() {
    int buff_size = 100;
    char* buff;

    buff = (char*) malloc(buff_size * sizeof(char));
    getline(&buff, &buff_size, stdin);
    printf("%s", buff);
    return 0;
}

