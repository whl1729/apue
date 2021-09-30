#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd1, fd2, result;
    int fd3 = 100;

    if ((fd1 = open("/tmp/test.txt", O_RDWR | O_CREAT)) < 0) {
        printf("open error! fd1 = %d\n", fd1);
        return 1;
    }

    printf("fd1 = %d\n", fd1);

    if ((fd2 = dup(fd1)) < 0) {
        printf("dup error! fd1 = %d, fd2 = %d\n", fd1, fd2);
        return 1;
    }

    printf("dup(%d) = %d\n", fd1, fd2);

    if ((result = dup2(fd1, fd3)) < 0) {
        printf("dup2 error! fd1 = %d, fd3 = %d, result = %d\n", fd1, fd3, result);
        return 1;
    }

    printf("dup2(%d, %d) = %d\n", fd1, fd3, result);

    return 0;
}
