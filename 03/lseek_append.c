#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define BUF_LEN 30

int main() {
    int fd, offset, num;
    char buf[BUF_LEN] = {0};
    char msg[] = "don't believe me just watch!\n";

    if ((fd = open("/tmp/foo.txt", O_RDWR | O_APPEND)) < 0) {
        printf("open error! fd = %d\n", fd);
        return 1;
    }

    if ((offset = lseek(fd, 10, SEEK_SET)) < 0) {
        printf("lseek error! offset = %d\n", offset);
        return 1;
    }

    if ((num = read(fd, buf, BUF_LEN)) < 0) {
        printf("read error! num = %d\n", num);
        return 1;
    }

    printf("1. read %d characters: %s\n", num, buf);

    if ((offset = lseek(fd, 10, SEEK_SET)) < 0) {
        printf("lseek error! offset = %d\n", offset);
        return 1;
    }

    if ((num = write(fd, msg, strlen(msg))) < 0) {
        printf("write error! num = %d\n", num);
        return 1;
    }

    if ((num = read(fd, buf, BUF_LEN)) < 0) {
        printf("read error! num = %d\n", num);
        return 1;
    }

    printf("2. read %d characters: %s\n", num, buf);

    return 0;
}
