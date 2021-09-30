#include <stdio.h>

#define BUF_SIZE 4

int main() {
    char buf[BUF_SIZE] = {0};
    int result;

    while (fgets(buf, BUF_SIZE, stdin) != NULL) {
        if ((result = fputs(buf, stdout)) < 0) {
            printf("fputs error! result = %d\n", result);
            return 1;
        }
    }

    if ((result = ferror(stdin)) != 0) {
        printf("ferror occurs! result = %d\n", result);
        return 1;
    }

    if ((result = feof(stdin)) != 0) {
        printf("feof occurs! result = %d\n", result);
        return 1;
    }

    return 0;
}
