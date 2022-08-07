#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  pid_t pid = getpid();
  pid_t sid = setsid();
  pid_t sid2, sid3;

  if (sid < 0) {
    printf("setsid error: %d\n", sid);
  } else {
    printf("setsid ok. sid = %d, pid = %d\n", sid, pid);
  }

  sid2 = getsid(pid);
  if (sid2 < 0) {
    printf("getsid(%d) error: %d\n", pid, sid2);
  } else {
    printf("getsid(%d) ok. sid = %d\n", pid, sid2);
  }

  sid3 = getsid(0);
  if (sid3 < 0) {
    printf("getsid(0) error: %d\n", sid3);
  } else {
    printf("getsid(0) ok. sid = %d\n", sid3);
  }

  return 0;
}
