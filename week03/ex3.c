#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    int data;
    struct Node* next;
};

typedef struct List {
    struct Node* head;
};

void print_list(struct List* lst) {
    struct Node* cur = lst-> head;
    while (cur->next != NULL) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

void insert_node(struct List* lst, struct Node* node) {
    struct Node* cur = lst->head;
    while (cur->next != NULL)
        cur = cur->next;
    cur->next = node;
}

int main() {
    struct List lst;
    lst.head = NULL;

    int test_data[5] = {9, 2, 4, 7, 1};
    for (int i = 0; i < 5; i++) {
        struct Node cur;
        cur.data = test_data[i];
        cur.next = NULL;
        insert_node(&lst, &cur);
    }

    print_list(&lst);
    return 0;
}

