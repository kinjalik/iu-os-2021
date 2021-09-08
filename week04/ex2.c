#include <unistd.h>

int main() {
    for (int i = 0; i < 3; ++i) {
        int pid = fork();
        if (pid == 0)
            break;
    }
    sleep(5);
}

