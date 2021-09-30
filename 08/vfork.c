#include "apue.h"

int globvar = 6;  /* external variable in initialized data */
char buf[] = "a write to stdout\n";

int main() {
    int var;  /* automatic variable on the stack */
    pid_t pid;

    var = 88;

    printf("before vfork\n");

    if ((pid = vfork()) < 0) {
        err_sys("vfork error");
    } else if (pid == 0) {
        globvar++;
        var++;
        _exit(0);
    }

    printf("pid = %ld, glob = %d, var = %d\n", (long)getpid(), globvar, var);
    exit(0);
}
