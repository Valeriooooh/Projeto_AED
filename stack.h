#include <stdio.h>
#ifndef stack_h_
#define stack_h_
#include "distiling.h"

typedef struct Stack {
  Coordinates cords;
  struct Stack *next;
  struct Stack *bottom;
} Stack;

Stack *newStack();
Coordinates pop(Stack *stack);
void push(Stack *stack, Coordinates value);
int is_empty(Stack *stack);

#endif
