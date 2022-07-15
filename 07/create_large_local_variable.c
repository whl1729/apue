#include <stdio.h>

#define MAX_STACK_SIZE (8376000)

int main() {
  char str[MAX_STACK_SIZE] = {0};
  str[MAX_STACK_SIZE - 1] = 'h';
  printf("%c\n", str[MAX_STACK_SIZE - 1]);
  return 0;
}
