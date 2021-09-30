#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int result, fd;

    if (argc < 2) {
        printf("usage: ./4_17_unlink_creat path\n");
        return 1;
    }

    if ((result = unlink(argv[1])) != 0) {
        printf("unlink error! result = %d\n", result);
    }

    if ((fd = creat(argv[1], 0666)) < 0) {
        printf("creat %s error! result = %d\n", argv[1], result);
        return 1;
    }

    return 0;
}
