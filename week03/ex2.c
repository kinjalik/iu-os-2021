#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void bubble_sort(int* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
        }
    }
}

int main() {
    int test[9] = {1, 9, 2, 8, 3, 7, 4, 6, 5};
    int size = 9;
    bubble_sort(test, size);
    for (int i = 0; i < size; i++)
        printf("%d ", test[i]);

    return 0;
}

