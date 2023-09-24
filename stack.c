#include <stdlib.h>
#include <stdio.h>
#include "distiling.h"

struct Stack {
    struct Coordinates array[100];
    int top;
};

struct Stack *newStack()
{
    struct Stack *ptr = (struct Stack *) malloc(sizeof(struct Stack));

    ptr->top = -1;
 
    return ptr;
}

struct Coordinates pop(struct Stack * stack) {
    return stack->array[stack->top--];
}

void push(struct Stack * stack, struct Coordinates value) {
    stack->array[stack->top++] = value;
}

int empty(struct Stack * stack) {
    return (stack->top == -1);
}