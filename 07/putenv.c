#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    int result;

    if (argc < 2) {
        printf("usage: ./putenv str\n");
        return 1;
    }

    if ((result = putenv(argv[1])) != 0) {
        printf("putenv(%s) error! result = %d\n", argv[1], result);
        return 1;
    }

    return 0;
}
