#include <fcntl.h>
#include <stdio.h>

int main() {
    int fd = open("/home/along/note/README.md", 0644);
    printf("fd of ~/note/README.md: %d\n", fd);

    fd = open("/home/along/note/readme.md", 0644);
    printf("fd of ~/note/readme.md: %d\n", fd);

    fd = open("/home/along/test/hello.txt", O_RDONLY | O_TRUNC);
    printf("fd of ~/test/hello.txt: %d\n", fd);

    printf("O_RDONLY=%#o\n", O_RDONLY);
    printf("O_WRONLY=%#o\n", O_WRONLY);
    printf("O_RDWR=%#o\n", O_RDWR);
    printf("O_EXCL=%#o\n", O_EXCL);
    printf("O_CREAT=%#o\n", O_CREAT);
    printf("O_TRUNC=%#o\n", O_TRUNC);
    printf("O_APPEND=%#o\n", O_APPEND);

    return 0;
}
