#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next_node;
} __attribute__((packed)) node_s;


node_s *__head = NULL; 
node_s *__tail = NULL;

int init(int data) {
    if(__head) {
        printf("Queue is already initialised\n");   //if they call init function multiple times
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
    __head->data =data;
    
    //tail and head point to the same location
    __tail = __head;

    return 0;
}

int add(int data) {
    node_s *cur;

    node_s *n = malloc(sizeof(node_s));
    if(!n) {
        printf("Memory Allocation failed\n");
        return -1;
    }
    n->next_node = NULL;
    n->data = data;

    __tail->next_node = n;
    __tail = n;


    return 0;

}

int fetch(void) {
    
}

void traverse(void) {
    for (node_s *cursor = __head; 
        cursor != NULL; 
        cursor = cursor->next_node) {
        printf("%d --> ", cursor->data);

    }
    printf("NULL \n");
}

int main() {
    init(102);

    for(int i=0; i<10;i++) {
        add(i);
    }

    traverse();
    return 0;
}