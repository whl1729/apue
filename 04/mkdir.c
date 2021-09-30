#include <sys/stat.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    int result;
    int i;

    if (argc < 2) {
        printf("usage: ./mkdir dir1 dir2 ...\n");
        return 1;
    }

    for (i = 1; i < argc; i++) {
        if ((result = mkdir(argv[i], 0755)) != 0) {
            printf("mkdir error! result = %d\n", result);
            return 1;
        }
    }

    return 0;
}
