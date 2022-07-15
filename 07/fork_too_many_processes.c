#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  int i;
  pid_t pid;

  // setbuf(stdout, NULL);

  for (i = 1; i < 65536; i++) {
    if ((pid = fork()) < 0) {
      printf("%d. fork error\n", i);
      return pid;
    } else if (pid == 0) {
      return 0;
    } else {
      printf("%d. fork ok: pid = %d\n", i, pid);
    }
  }

  return 0;
}
