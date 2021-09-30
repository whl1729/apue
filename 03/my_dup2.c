#include "apue.h"
#include <unistd.h>
#include <stdlib.h>

int my_dup2(int fd, int fd2);

int main(int argc, char *argv[]) {
    int result, fd, i;
    char buf[] = "hello world\n";

    if (argc < 2) {
        printf("usage: a.out fd\n");
        return 1;
    }

    fd = atoi(argv[1]);

    if ((result = my_dup2(STDOUT_FILENO, fd)) < 0) {
        printf("my_dup2 error! result = %d\n", result);
        return 1;
    }

    for (i = 0; i < 100; i++) {
        if ((result = write(fd, buf, strlen(buf))) < strlen(buf)) {
            printf("write error! result = %d\n", result);
            return 1;
        }
    }

    return 0;
}

int my_dup2(int fd, int fd2) {
    int min_fd, result, i;

    if (fd < 0 || fd > FOPEN_MAX || fd2 < 0 || fd2 > FOPEN_MAX) {
        printf("invalid input! fd = %d, fd2 = %d\n", fd, fd2);
        return -1;
    }

    if (fd == fd2) {
        return fd2;
    }

    if ((min_fd = dup(fd)) < 0) {
        printf("dup error! min_fd = %d\n", min_fd);
        return -1;
    }

    if (min_fd == fd2) {
        return fd2;
    }

    if (min_fd > fd2) {
        if ((result = close(fd2)) != 0) {
            printf("close error! result = %d\n", result);
            return -1;
        }

        if ((result = dup(fd)) != fd2) {
            printf("dup error! result = %d\n", result);
            return -1;
        }

        return fd2;
    }

    for (i = min_fd + 1; i <= fd2; i++) {
        if ((result = dup(fd)) != i) {
            printf("dup error! result = %d\n", result);
            return -1;
        }
    }

    for (i = min_fd; i < fd2; i++) {
        if ((result = close(i)) != 0) {
            printf("close error! result = %d\n", result);
            return -1;
        }
    }

    return fd2;
}
