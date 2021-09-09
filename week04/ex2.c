#include <unistd.h>

int main() {
    for (int i = 0; i < 3; ++i) {
        int pid = fork();
    }
    sleep(5);
}

