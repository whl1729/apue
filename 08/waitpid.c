#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>

void pr_exit(int status);

int main() {
    pid_t child, pid, result;
    int i, status;

    if ((pid = fork()) < 0) {
        printf("waitpid error! pid = %d\n", pid);
    } else if (pid == 0) {
        child = getpid();
        printf("child: pid = %d, ppid = %d\n", child, getppid());

        for (i = 0; i < 10; i++) {
            printf("child %d sleeping %d seconds\n", child, i+1);
        }

        printf("child %d exit\n", child);
        exit(0);
    } else {
        if ((result = waitpid(pid, &status, WNOHANG)) < 0) {
            printf("waitpid error! result = %d\n", result);
        } else if (result == 0) {
            printf("child %d has not yet changed state\n", pid);
        } else if (result == pid) {
            printf("child %d has changed state\n", pid);
            pr_exit(status);
        }
    }

    return 0;
}

void pr_exit(int status) {
    if (WIFEXITED(status)) {
        printf("normal termination, exit status = %d\n", WEXITSTATUS(status));
    } else if (WIFSIGNALED(status)) {
        printf("abnormal termination, signal number = %d%s\n", WTERMSIG(status),
#ifdef WCOREDUMP
                WCOREDUMP(status)? " (core file generated)": "");
#else
                "");
#endif
    } else if (WIFSTOPPED(status)) {
        printf("child stopped, signal number = %d\n", WSTOPSIG(status));
    }
}
