#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
 
    int* arrival = (int*) malloc(sizeof(int) * n);
    int* burst = (int*) malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) {
        scanf("%d %d", arrival + i, burst + i);
    }

    int completed = 0;
    int t = 0;
    while (completed != n) {
        int minArrival = INT_MAX;
        int minId = -1;
        for (int i = 0; i < n; i++) {
            if (arrival[i] == -1)
                continue;
            if (arrival[i] < minArrival) {
                minArrival = arrival[i];
                minId = i;
            }
        }
        if (minId == -1) {
            printf("[T = %d] No processes to execute...\n", t);
            t++;
            continue;
        }

        printf("[T = %d] Executing process %d...\n", t, minId);
        t += burst[minId];
        printf("[T = %d] Process %d has been executed.\n", t, minId);
        burst[minId] = arrival[minId] = -1;
        completed++;
    }
    printf("Completeion time: %d\n", t);
    return 0;
}
