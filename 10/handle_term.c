#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void handle_signal(int signal_num) {
  printf("receive signal: %d\n", signal_num);
}

int main() {
  signal(SIGINT, handle_signal);
  signal(SIGQUIT, handle_signal);
  signal(SIGTSTP, handle_signal);

  // Wait for terminal signal
  for (int i = 0; i < 100; i++) {
    sleep(10);
    printf("%d\n", i);
  }

  return 0;
}
