#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {
    FILE *fp;

    if (argc < 2) {
        printf("usage: ./fopen filepath\n");
        return 1;
    }

    if ((fp = fopen(argv[1], "w")) == NULL) {
        printf("fopen %s error!\n", argv[1]);
        return 1;
    }

    return 0;
}
