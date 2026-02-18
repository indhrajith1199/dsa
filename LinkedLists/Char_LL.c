#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node {
    char data[40];
    struct node *next_node;
}node_s;

node_s *__head = NULL;

int init(char *data) {
    if(__head) {
        printf("List is already initialised\n");   //if they call init function multiple times
        return -1;
    }

    //Allocate memory assign address to __head
    __head = malloc(sizeof(node_s));
    if(!__head) {
        printf("Memory Allocation failed\n");
        return -2;
    }
    __head->next_node = NULL;

    //populate the data
    memcpy(__head->data, data, strlen(data));
    printf("Data: %s\n", __head->data);
    return 0;
}

int add(char *data) {
    if(!data) {
        printf("Invalid data\n");
        return -1;
    }

    //Allocate memory for this node. So take a local pointer

    node_s *n = malloc(sizeof(node_s));
    if(!n) {
        printf("Memory Allocation failed\n");
        return -2;
    }

    n->next_node = __head;
    //populate the data
    memcpy(n->data, data, strlen(data));
    __head = n;
    return 0;
}

void traverse(void) {
    for (node_s *cursor = __head; cursor != NULL; cursor = cursor->next_node) {
        printf("%s\n", cursor->data);

    }
}

int main() {
    init("Im Indhrajith");
    add("Hello");   //adding at front.
    add("I am a SWE");

    traverse();
    return 0;
}
