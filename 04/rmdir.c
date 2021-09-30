#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    int result;
    int i;

    if (argc < 2) {
        printf("usage: ./rmdir dir1 dir2 ...\n");
        return 1;
    }

    for (i = 1; i < argc; i++) {
        if ((result = rmdir(argv[i])) != 0) {
            printf("rmdir error! result = %d\n", result);
            return 1;
        }
    }

    return 0;
}
