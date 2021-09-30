#include <stdio.h>

int main(int argc, char *argv[]) {
    int result;

    if (argc < 2) {
        printf("./remove path\n");
        return 1;
    }

    if ((result = remove(argv[1])) != 0) {
        printf("remove error! result = %d\n", result);
        return 1;
    }

    return 0;
}
