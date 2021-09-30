#include "apue.h"
#include <fcntl.h>

char buf[] = "helloworld";

int main() {
    int i;
    int fd;
    int result;

    if ((fd = open("file.nohole", O_WRONLY | O_CREAT)) < 0) {
        err_sys("open file error");
    }

    for (i = 0; i < 1639; i++) {
        if ((result = write(fd, buf, 10)) < 0) {
            err_sys("write error");
        }
    }

    if ((result = write(fd, buf, 4)) < 0) {
        err_sys("write error");
    }

    exit(0);
}
