#include <signal.h>
#include <stdio.h>

int main() {
  for (int i = 1; i <= 32; i++) {
    psignal(i, "signal message:");
  }

  return 0;
}
