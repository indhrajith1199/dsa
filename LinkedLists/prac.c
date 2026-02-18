#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node {
    char data[40];
    struct node *next_node;
}node_s ;

node_s *__head = NULL;

int init(char *data) {
    printf("Address of head : %p\n", __head);
    printf("Size of struct : %ld\n", sizeof(node_s));

    __head = malloc(sizeof(node_s));
    if(!__head) {
        printf("Mmeory Allocation Failed\n");
        return -1;
    }
    printf("Address of head : %p\n", __head);
    __head->next_node = NULL;
    memcpy(__head->data, data, strlen(data));

    printf("Data: %s\n", __head->data);
    

    return 0;
}

int main() {
   
    init("Hello");

    return 0;
}