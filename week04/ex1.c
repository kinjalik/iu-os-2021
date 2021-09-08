#include <stdio.h>
#include <unistd.h>

int n;

void childProcedure() {
    printf("Hello from child %d\n", getpid() - n);
}

void parentProcedure() {
    printf("Hello from parent %d\n", getpid() - n);
}
int main() {
    int forkResult = fork();
    if (forkResult == 0)
        childProcedure();
    else
        parentProcedure();
}
