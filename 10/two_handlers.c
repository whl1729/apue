#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void handler1(int signo) { printf("handler1 receive signal: %d\n", signo); }
void handler2(int signo) { printf("handler2 receive signal: %d\n", signo); }

int main() {
  signal(SIGINT, handler1);
  signal(SIGINT, handler2);

  for (;;) {
    pause();
  }

  return 0;
}
