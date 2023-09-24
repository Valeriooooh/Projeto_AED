#include "stack.h"
#include <stdio.h>
int main() {
  Stack *s = newStack();
  Coordinates c[4] = {{1, 0}, {0, 1}, {0, 0}, {1, 1}};
  for (int i = 0; i < 4; i++) {
    push(s, c[i]);
  }
  for (int i = 0; i < 4; i++) {
    Coordinates cord = pop(s);
    printf("coords -> {%i , %i}\n", cord.row, cord.col);
  }

  return 0;
}
