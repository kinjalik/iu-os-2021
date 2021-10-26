#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>

typedef struct {
    char names[100][255];
    int size;
    int inode;
} linked_file;

int main() {
    linked_file* files = malloc(100 * sizeof(linked_file));
    DIR* dir = opendir("tmp");
    struct dirent* cur;

    for (int i = 0; i < 100; i++) {
        linked_file file;
        file.inode = -1;
        files[i] = file;
    }

    cur = readdir(dir);
    while (cur != NULL) {
        struct stat cur_stat;
        char full_path[255] = "tmp/";
        stat(strcat(full_path, cur->d_name), &cur_stat);

        if (cur_stat.st_nlink <= 1)
            continue;
        
        int found = 0;
        for (int i = 0; i < 100; i++) {
            if (files[i].inode == cur_stat.st_ino) {
                found = 1;
                strcat(files[i].names[files[i].size], cur->d_name);
                files[i].size++;
                break;
            }
        }

        if (found == 0) {
            for (int i = 0; i < 100; i++) {
                if (files[i].inode != -1)
                    continue;
                linked_file new;
                new.inode = cur_stat.st_ino;
                new.size = 1;

                files[i] = new;
                strcat(files[i].names[files[i].size], cur->d_name);
                break;
            }
        }
    }

    for (int i =0 ; i < 100; i++) {
        if (files[i].inode == -1)
            continue;

        for (int j = 0; j < files[i].size; j++) {
            printf("%s\n", files[i].names[j]);
        }
        printf("\n");
    }

    closedir(dir);
    return 0;
}


    

    

