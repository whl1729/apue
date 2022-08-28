#include <stdio.h>
#include <string.h>

int main() {
  for (int i = 1; i <= 32; i++) {
    printf("signal %d: %s\n", i, strsignal(i));
  }

  return 0;
}
