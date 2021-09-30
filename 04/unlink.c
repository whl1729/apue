#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    int result;

    if (argc < 2) {
        printf("usage: ./unlink path\n");
        return 1;
    }

    if ((result = unlink(argv[1])) != 0) {
        printf("unlink error! result = %d\n", result);
        return 1;
    }

    return 0;
}
