#include <stdio.h>
#include <unistd.h>

int main() {
  pid_t pid = getpid();
  printf("pid: %d\n", pid);

  pid_t pgid = tcgetpgrp(0);
  if (pgid < 0) {
    printf("tcgetpgrp(0) error: %d\n", pgid);
  } else {
    printf("tcgetpgrp(0) ok: pgid = %d\n", pgid);
  }
}
