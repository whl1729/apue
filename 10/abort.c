#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("Hello ");
  abort();
  printf("world");
  return 0;
}
