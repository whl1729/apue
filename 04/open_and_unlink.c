#include "apue.h"
#include <fcntl.h>

int main(int argc, char *argv[]) {
    int result;

    if (argc < 2) {
        printf("./open_and_unlink path\n");
        return 1;
    }

    if ((result = open(argv[1], O_RDWR)) < 0) {
        printf("open error! result = %d\n", result);
        return 1;
    }

    if ((result = unlink(argv[1])) != 0) {
        printf("unlink error! result = %d\n", result);
        return 1;
    }

    printf("file unlinked\n");
    sleep(15);
    printf("done\n");
    exit(0);
}
