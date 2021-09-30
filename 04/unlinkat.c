#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
    int result;

    if (argc < 2) {
        printf("usage: ./unlinkat path\n");
        return 1;
    }

    if ((result = unlinkat(AT_FDCWD, argv[1], AT_REMOVEDIR)) != 0) {
        printf("unlinkat error! result = %d\n", result);
        return result;
    }

    return 0;
}
