#include <stdio.h>

#define MAX_SIZE 5

int __queue[MAX_SIZE];

int __head = -1;   // front
int __tail = -1;   // rear


int init(int data)
{
    if (__head != -1) {
        printf("Queue already initialised\n");
        return -1;
    }

    __head = 0;
    __tail = 0;
    __queue[__tail] = data;

    return 0;
}


int isEmpty(void)
{
    return (__head == -1);
}


int isFull(void)
{
    return ((__tail + 1) % MAX_SIZE == __head);
}


int add(int data)
{
    if (isFull()) {
        printf("Queue Overflow\n");
        return -1;
    }

    if (isEmpty()) {
        return init(data);
    }

    __tail = (__tail + 1) % MAX_SIZE;
    __queue[__tail] = data;

    return 0;
}


int fetch(void)
{
    if (isEmpty()) {
        printf("Queue Underflow\n");
        return -1;
    }

    int value = __queue[__head];

    if (__head == __tail) {
        __head = -1;
        __tail = -1;
    }
    else {
        __head = (__head + 1) % MAX_SIZE;
    }

    return value;
}


void traverse(void)
{
    if (isEmpty()) {
        printf("NULL\n");
        return;
    }

    int i;

    printf("Queue: ");

    for (i = __head; ; i = (i + 1) % MAX_SIZE) {

        printf("%d --> ", __queue[i]);

        if (i == __tail)
            break;
    }

    printf("NULL\n");
}


int main(void)
{
    init(102);

    add(1);
    add(2);
    add(3);
    add(4);

    traverse();

    printf("Fetched: %d\n", fetch());
    traverse();

    return 0;
}
