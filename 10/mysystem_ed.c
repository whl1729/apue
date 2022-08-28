#include "apue.h"
#include <errno.h>
#include <sys/wait.h>

static void sig_int(int signo) { printf("caught SIGINT\n"); }

static void sig_chld(int signo) { printf("caught SIGCHLD\n"); }

/* version without signal handling */
int mysystem(const char *cmdstring);

int main() {
  if (signal(SIGINT, sig_int) == SIG_ERR) {
    err_sys("signal(SIGINT) error");
  }

  if (signal(SIGCHLD, sig_chld) == SIG_ERR) {
    err_sys("signal(SIGCHLD) error");
  }

  if (mysystem("/bin/ed") < 0) {
    err_sys("mysystem() error");
  }

  exit(0);
}

int mysystem(const char *cmdstring) {
  pid_t pid;
  int status;

  if (cmdstring == NULL) {
    return 1; /* always a command processor with UNIX */
  }

  if ((pid = fork()) < 0) {
    status = -1; /* probably out of processes */
  } else if (pid == 0) {
    execl("/bin/sh", "sh", "-c", cmdstring, (char *)0);
    _exit(127); /* parent */
  } else {
    while (waitpid(pid, &status, 0) < 0) {
      if (errno != EINTR) {
        status = -1; /* error other than EINTR from waitpid() */
        break;
      }
    }
  }

  return status;
}
