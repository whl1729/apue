#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void sig_abort(int signo) { printf("receive signal: %d\n", signo); }

int main() {
  if (signal(SIGABRT, sig_abort) == SIG_ERR) {
    printf("fail to install handler for SIGABRT\n");
    return 1;
  }

  abort();

  int sum = 0;
  for (int i = 0; i < 1000; i++) {
    for (int j = 0; j < 1000; j++) {
      for (int k = 0; k < 1000; k++) {
        sum += i * j * k;
      }
    }
    printf("%d. sum = %d\n", i, sum);
  }

  return 0;
}
