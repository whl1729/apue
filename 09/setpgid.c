#include <stdio.h>
#include <unistd.h>

int main() {
  pid_t pid = getpid();
  pid_t pgid = pid + 17;
  int result;

  result = setpgid(pid, pid);
  if (result != 0) {
    printf("setpgid(%d, %d) error: %d\n", pid, pid, result);
    return result;
  } else {
    printf("setpgid(%d, %d) ok\n", pid, pid);
  }

  result = setpgid(pid, pgid);
  if (result != 0) {
    printf("setpgid(%d, %d) error: %d\n", pid, pgid, result);
    return result;
  } else {
    printf("setpgid(%d, %d) ok\n", pid, pgid);
  }

  return 0;
}
