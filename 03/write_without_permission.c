#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;
    int result;
    char buf[] = "hello world";

    if ((fd = open("/tmp/test.txt", O_RDONLY | O_CREAT)) < 0) {
        printf("open error! fd = %d\n", fd);
        return 1;
    }

    if ((result = write(fd, buf, sizeof(buf))) != sizeof(buf)) {
        printf("write error! result = %d\n", result);
        return 1;
    }

    return 0;
}
