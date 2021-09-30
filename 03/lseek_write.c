#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd, result;
    char buf[] = "hello world!\n";

    if ((fd = open("/tmp/test.txt", O_RDWR | O_CREAT, 0644)) < 0) {
        printf("open error! fd = %d\n", fd);
        return 1;
    }

    if ((result = lseek(fd, 0, 2)) < 0) {
        printf("lseek error! result = %d\n", result);
        return 1;
    }

    if ((result = write(fd, buf, sizeof(buf))) < sizeof(buf)) {
        printf("write error! result = %d\n", result);
        return 1;
    }

    return 0;
}
