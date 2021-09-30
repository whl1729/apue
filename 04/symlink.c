#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    int result;

    if (argc < 3) {
        printf("./symlink actualpath sympath\n");
        return 1;
    }

    if ((result = symlink(argv[1], argv[2])) != 0) {
        printf("symlink error! result = %d\n", result);
        return 1;
    }

    return 0;
}
