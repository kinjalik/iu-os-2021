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
    printf("%d\n", cur->data);
}

void delete_node(struct List* lst, struct Node* node) {
    struct Node* cur = lst->head;
    while (cur->next != node) {
        cur = cur->next;
    }
    cur->next = cur->next->next;
}

void insert_node(struct List* lst, struct Node* node) {
    struct Node* cur = lst->head;
    if (cur == NULL) {
        lst->head = node;
        return;
    }
    while (cur->next != NULL)
        cur = cur->next;
    cur->next = node;
}

int main() {
    struct List lst;
    lst.head = NULL;

    int test_data[5] = {9, 2, 4, 7, 1};
    struct Node* forClearance[5];
    for (int i = 0; i < 5; i++) {
        forClearance[i] = (struct Node*) malloc(sizeof(struct Node));
        struct Node* cur = forClearance[i];
        cur->data = test_data[i];
        cur->next = NULL;
        insert_node(&lst, cur);
    }
    print_list(&lst);
    delete_node(&lst, forClearance[2]);
    print_list(&lst);

    for (int i = 0; i < 5; i++)
        free(forClearance[i]);

    return 0;
}


