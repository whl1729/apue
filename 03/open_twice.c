#include "apue.h"
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd1, fd2;
    char filename[] = "/tmp/open_twice_log.txt";

    if ((fd1 = open(filename, O_WRONLY | O_CREAT, 0644)) < 0) {
        err_sys("open error! fd1 = %d\n", fd1);
        return 1;
    }

    printf("fd1 = %d\n", fd1);

    if ((fd2 = open(filename, O_WRONLY | O_CREAT, 0644)) < 0) {
        err_sys("open error! fd2 = %d\n", fd2);
        return 1;
    }

    printf("fd2 = %d\n", fd2);

    return 0;
}
