#include "apue.h"
#include <fcntl.h>
#include <stdlib.h>

/* flags are file status flags to turn on */
void set_fl(int fd, int flags) {
    int val;

    if ((val = fcntl(fd, F_GETFL, 0)) < 0) {
        err_sys("fcntl F_GETFL error");
    }

    val |= flags;

    if (fcntl(fd, F_SETFL, val) < 0) {
        err_sys("fcntl F_SETFL error");
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        err_quit("usage: a.out fd flags");
    }

    set_fl(atoi(argv[1]), atoi(argv[2]));

    return 0;
}
