#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>


int main() {
    while (1) {
        printf("$ ");
        char buf[100];
        scanf("%s", buf);

        // Pipe the output
        int p[2];
        if (pipe(p) == -1)
            exit(1);

        int pid = fork();
        if (pid == 0) {


            char* binary[100+5];
            strcat(binary, "/bin/");
            strcat(binary, buf);
            char* argv[2] = {binary};

            close(p[0]);
            dup2(p[1], 1);
            dup2(p[1], 2);
            close(p[1]);
            execve(binary, argv, NULL);

            exit(0);
        } else {
            wait(NULL);
            close(p[1]);

            char output[1024];
            while (read(p[0], output, sizeof(output)) != 0)
                printf(output);

            close(p[0]);

        }
    }
}
