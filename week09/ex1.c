#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/*
 * Results:
 * N=10: 8 hits, 992 misses, ratio 0.008065
 * N=50: 50 hits, 950 misses, ratio 0.052632
 * N=100: 93 hits, 907 misses, ration 0.102536
 */

typedef struct table_entry {
    int page_number;
    unsigned int counters;
} table_entry;


int main() {
    int n;
    printf("Enter the N: ");
    scanf("%d", &n);

    FILE *file = fopen("input.txt", "r");

    table_entry* table = malloc(n * sizeof(table_entry));

    // Fill the memory with empty table
    for (int i = 0; i < n; i++) {
        table_entry cur;
        cur.page_number = -1;
        cur.counters = 0u;
        table[i] = cur;
    }

    int cur_requested;
    unsigned int hit_counter = 0;
    unsigned int miss_counter = 0;

    while (fscanf(file, "%d", &cur_requested) == 1) {
        int page_found = 0;

        for (int i = 0; i < n; i++) {
            if (table[i].page_number == cur_requested) {
                page_found = 1;
                break;
            }
        }

        if (page_found)
            hit_counter++;
        else
            miss_counter++;

        if (!page_found) {
            // 1. Find free space
            int free_space_found = 0;
            for (int i = 0; i < n; i++) {
                if (table[i].page_number == -1) {
                    table_entry page;
                    page.page_number = cur_requested;
                    page.counters = 0;
                    table[i] = page;
                    free_space_found = 1;
                    break;
                }
            }

            if (free_space_found)
                continue;

            unsigned int min_counter = INT_MAX;
            unsigned int index = -1;
            for (int i = 0; i < n; i++) {
                if (min_counter > table[i].counters) {
                    min_counter = table[i].counters;
                    index = i;
                }
            }

            table_entry page;
            page.page_number = cur_requested;
            page.counters = 0;
            table[index] = page;
        }

        for (int i = 0; i < n; i++) {
            table[i].counters >>= 1;

            if (page_found && cur_requested == table[i].page_number)
                table[i].counters |= 1 << 31;
        }
    }

    printf("Hits:\t%d\n", hit_counter);
    printf("Misses:\t%d\n", miss_counter);
    printf("Ratio:\t%f\n", (float) hit_counter / (float) miss_counter);

    free(table);
    fclose(file);

    return 0;
}

