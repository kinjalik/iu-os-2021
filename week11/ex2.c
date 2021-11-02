#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
typedef struct dirent dirent;
int main() {
    DIR *d;
    dirent *dir;
    d = opendir("/");
    while ((dir = readdir(d)) != NULL) {
        printf("%s\n", dir->d_name);
    }
    closedir(d);
    return 0;
}
    
