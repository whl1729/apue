#include <stdio.h>
#include <fcntl.h>

int main() {
    int fd;

    if ((fd = open("/tmp/output.txt", O_EXCL)) < 0) {
        printf("open error! fd = %d\n", fd);
        return 1;
    }

    return 0;
}
