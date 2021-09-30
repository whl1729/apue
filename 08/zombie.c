#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    pid_t pid;
    pid_t result;
    int i;
    int status = 0;

    if ((pid = fork()) < 0) {
        printf("fork error! pid = %d\n", pid);
        return 1;
    }

    if (pid == 0) {
        printf("child: pid = %d, ppid = %d. Bye~Bye~\n", getpid(), getppid());
        exit(1);
    } else {
        printf("parent: pid = %d, child = %d\n", getpid(), pid);

        for (i = 0; i < 15; i++) {
            sleep(1);
            printf("parent: sleeping %d seconds\n", i+1);
        }

        printf("parent: sleep enough. Bye~Bye~\n");
        if ((result = waitpid(pid, &status, 0)) != pid) {
            printf("waitpid error! result = %d, status = %d\n", result, status);
        } else {
            printf("waitpid(%d) ok! status = %d\n", pid, status);
        }
    }

    return 0;
}
