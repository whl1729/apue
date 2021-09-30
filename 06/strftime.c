#include <time.h>
#include <stdio.h>

#define BUF_SIZE 200

int main(int argc, char *argv[]) {
    char buf[BUF_SIZE];
    size_t result;
    time_t now;
    struct tm *ptm;

    if (argc < 2) {
        printf("usage: ./strftime formatstr\n");
        return 1;
    }

    if ((now = time(NULL)) < 0) {
        printf("time error! now = %ld\n", now);
        return 1;
    }

    if ((ptm = localtime(&now)) == NULL) {
        printf("localtime error!\n");
        return 1;
    }

    if ((result = strftime(buf, BUF_SIZE, argv[1], ptm)) == 0) {
        printf("strftime error!\n");
        return 1;
    }

    printf("%s\n", buf);
    return 0;
}
