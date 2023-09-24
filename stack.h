#include <stdio.h>
#ifndef stack_h_
#define stack_h_
#include "distiling.h"

struct Stack {
    struct Coordinates array[100];
    int top;
};

struct Stack * newStack();
struct Coordinates pop(struct Stack * stack);
void push(struct Stack * stack, struct Coordinates value);
int empty(struct Stack * stack);

#endif
