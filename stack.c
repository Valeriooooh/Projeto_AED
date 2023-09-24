#include "distiling.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
  Coordinates cords;
  struct Stack *next;
  struct Stack *bottom;
} Stack;

int is_empty(struct Stack *stack) { return (stack->bottom == NULL); }

Stack *newStack(Coordinates c) {
  Stack *s = (Stack *)malloc(sizeof(Stack));
  s->cords = c;
  return s;
}

Coordinates pop(Stack *stack) {
  if (is_empty(stack)) {
    Coordinates c = {-1, -1};
    return c;
  }
  Stack *s = stack->bottom;
  while (s->next != NULL) {
    if (s->next->next != NULL) {
      s = s->next;
    } else {
      Coordinates c = {s->next->cords.row, s->next->cords.col};
      Stack *tmp = s->next;
      s->next = NULL;
      free(tmp);
      return c;
    }
  }
  Stack *sb = stack->bottom;
  Stack *tmp = sb->bottom;
  Coordinates c = {sb->cords.row, sb->cords.col};
  sb->bottom = NULL;
  free(tmp);
  return c;
}

void push(struct Stack *stack, Coordinates value) {
  if (stack->bottom == NULL) {
    Stack *s = stack->bottom = newStack(value);
  } else {
    Stack *s = stack->bottom;
    while (s->next != NULL) {
      s = s->next;
    }
    s->next = newStack(value);
  }
}
