#include "apue.h"
#include <stdlib.h>
#include <fcntl.h>

#define BUF_SIZE_MAX 65536

int toInt(char *str);

int main(int argc, char *argv[]) {
    int buf_size, num;
    int buf[BUF_SIZE_MAX];

    if (argc < 2) {
        printf("Usage: ./io_efficiency buf_size\n");
        exit(1);
    }

    buf_size = atoi(argv[1]);
    if (buf_size > BUF_SIZE_MAX) {
        printf("buf_size(%d) too large! it should be no more than %d.\n", buf_size, BUF_SIZE_MAX);
        exit(1);
    }

    set_fl(STDOUT_FILENO, O_SYNC);

    while ((num = read(STDIN_FILENO, buf, buf_size)) > 0) {
        if (write(STDOUT_FILENO, buf, num) != num) {
            printf("write error!\n");
            exit(1);
        }
    }

    exit(0);
}

void set_fl(int fd, int flags) {
    int val, result;

    if ((val = fcntl(fd, F_GETFL, 0)) < 0) {
        err_sys("fcntl getfl error! val = %d\n", val);
        return;
    }

    val |= flags;

    if ((result = fcntl(fd, F_SETFL, val)) < 0) {
        err_sys("fcntl setfl error! result = %d\n", result);
        return;
    }
}
