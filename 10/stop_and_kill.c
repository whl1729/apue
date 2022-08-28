#include <signal.h>
#include <stdio.h>

void sig_stop(int signo) { printf("receive SIGSTOP(%d) signal\n", signo); }

void sig_kill(int signo) { printf("receive SIGKILL(%d) signal\n", signo); }

int main() {
  if (signal(SIGSTOP, sig_stop) == SIG_ERR) {
    printf("fail to install handler for SIGSTOP\n");
    return 1;
  }

  if (signal(SIGKILL, sig_kill) == SIG_ERR) {
    printf("fail to install handler for SIGKILL\n");
    return 1;
  }

  int sum = 0;
  for (int i = 0; i < 10000; i++) {
    for (int j = 0; j < 10000; j++) {
      for (int k = 0; k < 10000; k++) {
        sum += i * j * k;
      }
    }
    printf("%d\n", i);
  }

  return 0;
}
