#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  signal(SIGABRT, SIG_IGN);
  printf("Hello ");
  abort();
  printf("world\n");
  return 0;
}
