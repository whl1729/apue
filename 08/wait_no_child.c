#include <sys/types.h>
#include <stdio.h>
#include <wait.h>

int main() {
    pid_t pid;
    int status = 0;

    if ((pid = wait(&status)) < 0) {
        printf("wait error! pid = %d\n", pid);
    }

    return 0;
}
