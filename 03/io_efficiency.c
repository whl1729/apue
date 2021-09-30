#include "apue.h"

#define BUF_SIZE_MAX 65536

int toInt(char *str);

int main(int argc, char *argv[]) {
    int buf_size, num;
    int buf[BUF_SIZE_MAX];

    if (argc < 2) {
        printf("Usage: ./io_efficiency buf_size\n");
        exit(1);
    }

    buf_size = toInt(argv[1]);
    if (buf_size > BUF_SIZE_MAX) {
        printf("buf_size(%d) too large! it should be no more than %d.\n", buf_size, BUF_SIZE_MAX);
        exit(1);
    }

    while ((num = read(STDIN_FILENO, buf, buf_size)) > 0) {
        if (write(STDOUT_FILENO, buf, num) != num) {
            printf("write error!\n");
            exit(1);
        }
    }

    exit(0);
}

int toInt(char *str) {
    int i;
    int num = 0;
    for (i = 0; str[i] != 0; i++) {
        num = 10 * num + (str[i] - '0');
    }

    return num;
}
