#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    int result;

    if (argc < 2) {
        printf("usage: a.out string\n");
        return 1;
    }

    result = atoi(argv[1]);
    printf("atoi(%s) = %d, errno = %d\n", argv[1], result, errno);
    return 0;
}
