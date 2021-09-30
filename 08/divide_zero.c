#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>

void display_status(int status);

int main() {
    pid_t pid;
    pid_t result;
    int status = 0;

    if ((pid = fork()) < 0) {
        printf("fork error! pid = %d\n", pid);
        return 1;
    }

    if (pid == 0) {
        printf("pid: %d, ppid: %d, divide\n", getpid(), getppid());
        printf("pid/status = %d\n", pid/status);
    } else {
        printf("pid: %d, ppid: %d, waitpid: %d\n", getpid(), getppid(), pid);

        if ((result = waitpid(pid, &status, 0)) != pid) {
            printf("waitpid(%d) error! result = %d\n", pid, result);
        }

        display_status(status);
    }

    return 0;
}

void display_status(int status) {
    printf("status: %d\n", status);

    if (WIFEXITED(status)) {
        printf("terminated normally.\n");
    } else if (WIFSIGNALED(status)) {
        printf("terminated abnormally. signal: %d\n", WTERMSIG(status));
    } else if (WIFSTOPPED(status)) {
        printf("stopped. signal: %d\n", WSTOPSIG(status));
    } else if (WIFCONTINUED(status)) {
        printf("continued.\n");
    } else {
        printf("unknown status.\n");
    }
}
