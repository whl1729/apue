#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void on_recv(int signal_num) { printf("receive signal: %d\n", signal_num); }

int main() {
  signal(SIGABRT, on_recv);
  printf("Hello ");
  abort();
  printf("world\n");
  return 0;
}
