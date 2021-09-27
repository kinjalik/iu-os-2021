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
    
    int averageT = 0;
    int averageWaiting = 0;
    while (completed != n) {
        int minJobTime = INT_MAX;
        int id = -1;
        for (int i = 0; i < n; i++) {
            if (arrival[i] > t)
                continue;
            if (burst[i] < minJobTime) {
                minJobTime = burst[i];
                id = i;
            }
        }

        if (id == -1) {
            printf("[T = %d] No processes to execute...\n", t);
            t++;
            continue;
        }

        int waitingTime = t - arrival[id];

        printf("[T = %d] Executing process %d...\n", t, id);
        t += burst[id];
        printf("[T = %d] Process %d has been executed.\n", t, id);
        burst[id] = arrival[id] = -1;
        completed++;

        int turnaround = t - arrival[id];
        printf("Process %d: turnaround time is %d, waiting time is %d", id, turnaround, waitingTime);
        averageT += turnaround;
        averageWaiting += waitingTime;
    }
    printf("Completeion time: %d\n", t);
    printf("Average turnaround time: %f\n", 1.0 * averageT / n);
    printf("Average waiting time: %f\n", 1.0 * averageWaiting / n);
    return 0;
}
