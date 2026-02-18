#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next_node;
} __attribute__((packed)) node_s;

node_s *__head = NULL;

int init(int data) {
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
    __head->data =data;
    return 0;
}

int add(int data) {

    //Allocate memory for this node. So take a local pointer

    node_s *n = malloc(sizeof(node_s));
    if(!n) {
        printf("Memory Allocation failed\n");
        return -1;
    }

    n->next_node = __head;
    //populate the data
    n->data = data;
    __head = n;
    return 0;
}

int add_End(int data) {
    node_s *cur;
    node_s *n = malloc(sizeof(node_s));
    if(!n) {
        printf("Memory Allocation failed\n");
        return -1;
    }
    n->next_node = NULL;
    n->data = data;

    for ( cur = __head; cur->next_node != NULL; cur = cur->next_node) {

    }

    cur->next_node = n; 
    return 0;

}

int insert(int key, int data) {
    node_s *k, *n;

    for(k = __head;
        k != NULL;
        k = k->next_node) {
            if(k->data == key) {
                break;
            }
        }

        if (!k) {
            printf("Key not found\n");
            return 0;
        }

        n = malloc(sizeof(node_s));
        if(!n) {
            printf("Memory allocation failed\n");
            return -1;
        }

        n->data = data;
        n->next_node = k-> next_node;

        k->next_node = n;

        return 0;
}


int delete(int data) {
    for( node_s *p=NULL, *c=__head; c != NULL; p = c, c = c-> next_node) {
        if(c->data == data) {
            p->next_node = c->next_node;
            free(c);
            printf("deleted: %d\n", data);
            return 1;
        }
    }
    return 0;
}

int exists(int data) {
    for (node_s *cur = __head; cur != NULL; cur = cur->next_node)
    {
        if(cur->data == data) {
            return 1;
        }
    }
    return 0;
}



void traverse(void) {
    for (node_s *cursor = __head; 
        cursor != NULL; 
        cursor = cursor->next_node) {
        printf("%d ", cursor->data);

    }
    printf("\n");
}

int main() {
    init(102);
    for(int i=0; i<10;i++) {
        add(i);
    }

    for(int i=0; i<10;i++) {
        add_End(i);
    }

    // add(100);
    // add_End(103);
    // add_End(104);
    traverse();
    printf("Is 102 exists - %d\n", exists(102));
    
    delete(5);
    traverse();

    delete(102);
    traverse();

    insert(0, 102);
    traverse();

    insert(103, 1011);
    traverse();

    return 0;
}
