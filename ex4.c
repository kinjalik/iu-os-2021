#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int main() {
    int a, b;

    printf("Input two integers: \n");
    scanf("%d %d", &a, &b);

    swap(&a, &b);

    printf("%d %d", a, b);
    return 0;
}


