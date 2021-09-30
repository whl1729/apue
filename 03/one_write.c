#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>


int says(int fd, char *buf, int times);

char buf1[] = "hello world\n";
char buf2[] = "nice to meet you\n";

int main() {
    int fd;

    if ((fd = open("/tmp/result.txt", O_RDWR | O_CREAT | O_TRUNC, 0644)) < 0) {
        printf("open error! fd = %d\n", fd);
        return 1;
    }

    says(fd, buf1, 100);

    return 0;
}

int says(int fd, char *buf, int times) {
    int i, num;

    for (i = 0; i < times; i++) {
        if ((num = write(fd, buf, strlen(buf))) < strlen(buf)) {
            printf("write error! num = %d\n", num);
            return 1;
        }
    }

    return 0;
}
