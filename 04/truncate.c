#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int result;

    if (argc < 3) {
        printf("usage: ./truncate filename length\n");
        return 1;
    }

    if ((result = truncate(argv[1], atoi(argv[2]))) != 0) {
        printf("truncate error! result = %d\n", result);
        return 1;
    }

    return 0;
}
