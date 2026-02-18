#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next_node;
} node_s;

node_s *__head = NULL; 
node_s *__tail = NULL;

int init(int data) {

    if (__head) {
        printf("Queue is already initialised\n");
        return -1;
    }

    __head = malloc(sizeof(node_s));
    if (!__head) {
        printf("Memory Allocation failed\n");
        return -2;
    }

    __head->data = data;
    __head->next_node = __head;   // circular

    __tail = __head;

    return 0;
}

int add(int data) {

    if (__head == NULL)
        return init(data);

    node_s *n = malloc(sizeof(node_s));
    if (!n) {
        printf("Memory Allocation failed\n");
        return -1;
    }

    n->data = data;
    n->next_node = __head;        // new node points to head

    __tail->next_node = n;        // old tail links to new node
    __tail = n;                   // update tail

    return 0;
}

int fetch(void) {

    if (__head == NULL) {
        printf("Queue empty\n");
        return -1;
    }

    int value = __head->data;

    if (__head == __tail) {
        free(__head);
        __head = NULL;
        __tail = NULL;
        return value;
    }

    node_s *temp = __head;
    __head = __head->next_node;
    __tail->next_node = __head;   // maintain circular link

    free(temp);

    return value;
}
void traverse(void) {

    if (__head == NULL) {
        printf("NULL\n");
        return;
    }

    node_s *cursor;

    for (cursor = __head; ; cursor = cursor->next_node) {

        printf("%d --> ", cursor->data);

        if (cursor->next_node == __head)
            break;
    }

    printf("(back to %d)\n", __head->data);
}


int main() {

    init(102);

    for (int i = 0; i < 5; i++) {
        add(i);
    }

    traverse();

    printf("Fetched: %d\n", fetch());
    traverse();

    return 0;
}
