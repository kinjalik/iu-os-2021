#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>n
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>


int main() {
    int input_size = 100;
    while (1) {
        printf("$ ");

        char* line = NULL;
        size_t len = 0;
        ssize_t lineSize = 0;
        lineSize = getline(&line, &len, stdin);
        line[lineSize - 1] = 0;
        lineSize--;

        int components = 0;
        for (int i = 0; i < lineSize; i++) {
            if (line[i] == ' ')
                components++;
            while (line[i] == ' ')
                i++;
        }
        components++;

        char** argv = malloc((components + 1) * sizeof(char*));
        int argn = 0;
        for (int i = 0; i < lineSize; i++) {
            if (line[i] == ' ')
                continue;
            argv[argn] = calloc(100 * sizeof(char), 0);
            int bufLen = 0;
            while (line[i] != ' ' && line[i] != 0) {
                argv[argn][bufLen] = line[i];
                bufLen++;
                i++;
            }
            argn++;
        }
        argv[argn] = NULL;

        char* binary = calloc(5 + strlen(argv[0]), 0);
        strcat(binary, "/bin/");
        strcat(binary, argv[0]);

        // Pipe the output
        int p[2];
        if (pipe(p) == -1)
            exit(1);

        int pid = fork();
        int is_background = 0;
        if (strcmp(argv[argn - 1], "&") == 0)
            is_background = 1;

        if (pid == 0) {

            close(p[0]);
            dup2(p[1], 1);
            dup2(p[1], 2);
            close(p[1]);
            execve(binary, argv, NULL);

            exit(0);
        } else {
            if (is_background == 1) {
                close (p[1]);
                close(p[0]);
            } else {
                waitpid(pid, NULL, WUNTRACED);
                close(p[1]);

                char output[1024] = "";
                while (read(p[0], output, sizeof(output)) != 0)
                    printf(output);

                if (output[strlen(output) - 1] != '\n')
                    printf("\n");
                close(p[0]);
            }

        }
        for (int i = 0; i < argn; i++)
            free(argv[i]);
        free(argv);
        free(binary);
        free(line);
    }
}
