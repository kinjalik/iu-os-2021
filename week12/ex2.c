#include <linux/input.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

#define KEY_PRESSED 1
#define KEY_RELEASED 0
#define KEY_HOLD 2

void prtcode(int codes) {
    printf("%d\n", codes);

}

int main() {
    int fd = open("/dev/input/by-path/platform-i8042-serio-0-event-kbd", O_RDONLY);

    struct input_event ev[64];

    while (1) {
        int rb = read(fd, ev, sizeof(ev));
        for (int i = 0; i < (int) (rb / sizeof(struct input_event)); i++) {
            if (ev[i].type != EV_KEY || ev[i].value == KEY_HOLD)
                continue;
            if (ev[i].value == KEY_PRESSED) {
                printf("PRESSED 0x%x (%d)\n", ev[i].code, ev[i].code);
            } else {
                printf("RELEASED 0x%x (%d)\n", ev[i].code, ev[i].code);
            }
        }

    }
    return 0;
}
