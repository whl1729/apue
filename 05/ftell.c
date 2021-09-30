#include <stdio.h>

int main(int argc, char *argv[]) {
    FILE *fp;
    long pos;
    int result;

    if (argc < 2) {
        printf("usage: ./ftell filepath\n");
        return 1;
    }

    if ((fp = fopen(argv[1], "r+")) == NULL) {
        printf("fopen %s error!", argv[1]);
        return 1;
    }

    if ((pos = ftell(fp)) < 0) {
        printf("ftell %s error! pos = %ld\n", argv[1], pos);
        return 1;
    }

    printf("after opening, pos = %ld\n", pos);

    if ((result = fseek(fp, 0, SEEK_END)) != 0) {
        printf("fseek error! result = %d\n", result);
        return 1;
    }

    if ((pos = ftell(fp)) < 0) {
        printf("ftell %s error! pos = %ld\n", argv[1], pos);
        return 1;
    }

    printf("after fseek(fp, 0, SEEK_END), pos = %ld\n", pos);

    if ((result = fseek(fp, 20, SEEK_SET)) != 0) {
        printf("fseek error! result = %d\n", result);
        return 1;
    }

    if ((pos = ftell(fp)) < 0) {
        printf("ftell %s error! pos = %ld\n", argv[1], pos);
        return 1;
    }

    printf("after fseek(fp, 20, SEEK_SET), pos = %ld\n", pos);

    if ((result = fseek(fp, 200, SEEK_CUR)) != 0) {
        printf("fseek error! result = %d\n", result);
        return 1;
    }

    if ((pos = ftell(fp)) < 0) {
        printf("ftell %s error! pos = %ld\n", argv[1], pos);
        return 1;
    }

    printf("after fseek(fp, 200, SEEK_CUR), pos = %ld\n", pos);

    return 0;
}
