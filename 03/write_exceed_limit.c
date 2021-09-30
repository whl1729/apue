#include "apue.h"
#include "fcntl.h"

#define BUF_SIZE 4096

int main() {
    int num, num2, fd;
    char buf[BUF_SIZE];

    if ((num = read(STDIN_FILENO, buf, BUF_SIZE)) < 0) {
        printf("read error! num = %d\n", num);
        return 1;
    }

    if ((fd = open("/tmp/tmp.txt", O_WRONLY | O_CREAT)) < 0) {
        printf("open error! fd = %d\n", fd);
        return 1;
    }

    while (1) {
        if ((num2 = write(fd, buf, num)) < num) {
            printf("write errpr! num2 = %d\n", num2);
            return 1;
        }
    }

    return 0;
}
