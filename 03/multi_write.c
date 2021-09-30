#include "apue.h"
#include <fcntl.h>

char buf[] = "hello world\n";

int main() {
    int pid, fd, result;

    pid = getpid();
    printf("my pid is %d\n", pid);

    if ((fd = open("/tmp/hello.txt", O_WRONLY | O_CREAT)) < 0) {
        printf("open error! fd = %d\n", fd);
        return 1;
    }

    while (1) {
        if ((result = write(fd, buf, sizeof(buf))) != sizeof(buf)) {
            printf("write error! result = %d\n", result);
            return 1;
        }
    }

    return 0;
}
