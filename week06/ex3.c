#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
 
    int* arrival = (int*) malloc(sizeof(int) * n);
    int* burst = (int*) malloc(sizeof(int) * n);
    int* lastStop = (int*) calloc(sizeof(int) * n, -1);
    int* waitingTime = (int*) calloc(sizeof(int) * n, 0);
    int* startTime = (int*) calloc(sizeof(int) * n, -1);

    for (int i = 0; i < n; i++) {
        scanf("%d %d", arrival + i, burst + i);
    }

    int completed = 0;
    int t = 0;
    
    int lastI = 0;
    while (completed != n) {
        int id = -1;
        for (int i = 0; i < n; i++) {
            int cur = (lastI + i) % n;
            if (arrival[i] > t || arrival[i] == -1)
                continue;
            id = i;
            break;
        }
        if (id == -1) {
            printf("[T = %d] Waiting for process..\n", t);
            t++;
            continue;
        }

        lastI = id;

        printf("[T = %d] Starting to execute process %d..", t, id);
        if (lastStop[id] != -1) {
            waitingTime += t - lastStop[id];
        }
        if (startTime[id] == -1)
            startTime[id] = t;
        if (burst[id] > q) {
            burst[id] -= q;
            t += q;
            printf("[T = %d] Stopped process %d due to exceeding the quantum.", t, id);
        } else  {
            t += burst[id];
            arrival[id] = burst[id] = -1;
            printf("[T = %d] Process %d has been executed.", t, id);
            completed++;
        }
        lastStop[id] = t;
    }
    int waitSum = 0;
    int turnSum = 0;
    for (int i = 0; i < n; i++) {
        int turntime = lastStop[i] - startTime[i];
        int waittime = waitingTime[i];
        printf("[PID = %d] Waiting time: %d, turnaround time: %d", i, turntime, waittime);
        waitSum += waittime;
        turnSum += turntime;
    }

    printf("Completeion time: %d\n", t);
    printf("Average turnaround time: %f\n", 1.0 * turnSum / n);
    printf("Average waiting time: %f\n", 1.0 * waitSum / n);
    return 0;
}
