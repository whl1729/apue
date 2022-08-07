#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  pid_t parent = getpid();
  pid_t pid;

  if ((pid = fork()) == 0) {
    pid = getpid();
    printf("I\'m child. My pid is %d\n", pid);
    int result = setpgid(pid, parent);
    if (result != 0) {
      printf("child setpgid error: %d\n", result);
      return result;
    } else {
      pid_t pgid = getpgid(pid);
      printf("child setpgid(%d, %d) ok: pgid = %d\n", pid, parent, pgid);
      return 0;
    }
  } else {
    printf("I\'m parent. My pid is %d. My Child is %d\n", parent, pid);
  }
}
