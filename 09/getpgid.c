#include <stdio.h>
#include <unistd.h>

int main() {
  pid_t pid = getpid();
  pid_t pgid;
  pid_t i;

  for (i = pid - 100; i <= pid; i++) {
    pgid = getpgid(i);
    printf("pid: %d, pgid: %d\n", i, pgid);
  }

  return 0;
}
