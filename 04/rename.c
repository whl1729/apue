#include <stdio.h>

int main(int argc, char *argv[]) {
    int result;

    if (argc < 3) {
        printf("usage: ./rename oldname newname\n");
        return 1;
    }

    if ((result = rename(argv[1], argv[2])) != 0) {
        printf("rename error! result = %d\n", result);
        return 1;
    }

    return 0;
}
