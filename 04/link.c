#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    int result;

    if (argc < 3) {
        printf("usage: ./link srcpath destpath\n");
        return 1;
    }

    if ((result = link(argv[1], argv[2])) != 0) {
        printf("link error! result = %d\n", result);
        return 1;
    }

    return 0;
}
