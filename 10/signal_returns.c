#include <signal.h>
#include <stdio.h>

typedef void (*Handler)(int);

void print_handler(Handler *handler) {
  printf("handler addr: %p\n", handler);
  printf("handler points to: %p\n", *handler);
}

void my_handler(int signo) { printf("receive signal: %d\n", signo); }

int main() {
  printf("my_handler: %p\n", my_handler);
  Handler handler = signal(SIGTERM, my_handler);
  print_handler(&handler);
  handler = signal(SIGTERM, my_handler);
  print_handler(&handler);
  return 0;
}
