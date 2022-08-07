#include <stdio.h>
#include <unistd.h>

int main() {
  pid_t pid = getpid();
  pid_t pgid = getpgrp();

  printf("current pid: %d, pgid: %d\n", pid, pgid);
  return 0;
}
