#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    pid_t pid;
    int i;

    if ((pid = fork()) < 0) {
        printf("fork error! pid = %d\n", pid);
        return 1;
    }

    if (pid == 0) {
        printf("child: pid = %d, ppid = %d\n", getpid(), getppid());
        for (i = 0; i < 15; i++) {
            sleep(1);
            printf("child: pid = %d, ppid = %d, sleeping %d seconds\n", getpid(), getppid(), i+1);
        }

        printf("sleep enough. bye~bye~\n");
        exit(0);
    } else {
        printf("parent: pid = %d, child = %d\n", getpid(), pid);
    }

    return 0;
}
