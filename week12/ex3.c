#include <linux/input.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

#define KEY_PRESSED 1
#define KEY_RELEASED 0
#define KEY_HOLD 2

int hks = 3;

int hk[3][4] = {
        {18,25, -1, -1},
        {25,30,46, -1},
        {18, 23, 32, -1}
};

size_t hklen[3] = {
        2, 3, 3
};

char *msg[3];


int* buf;
int ptr = 0;

void check_hotkey() {

    for (int i = 0; i < hks; i++) {
        int cur_ptr = ptr;
        int cnt = 0;
        int converges = 1;
        while (cnt < hklen[i]) {
            if (buf[cur_ptr] != hk[i][cnt]) {
                converges = 0;
                break;
            }
            cur_ptr--;
            if (cur_ptr < 0)
                cur_ptr = 7;
            cnt++;
        }
        if (converges == 1)
            printf("%s\n", msg[i]);
    }
}

int main() {
    int fd = open("/dev/input/by-path/platform-i8042-serio-0-event-kbd", O_RDONLY);

    buf = malloc(sizeof(int) * 8);
    memset(buf, 0, 8);
    msg[0] = "I passed the Exam!";
    msg[1] = "Get some cappuccino!";
    msg[2] = "I commit a suicide!";

    struct input_event ev[64];


    while (1) {
        int rb = read(fd, ev, sizeof(ev));

        for (int i = 0; i < (int) (rb / sizeof(struct input_event)); i++) {
            if (ev[i].type != EV_KEY || ev[i].value != KEY_RELEASED)
                continue;
            buf[ptr] = ev[i].code;
            check_hotkey();
            ptr++;
            if (ptr == 8)
                ptr = 0;

        }

    }
    return 0;
}


