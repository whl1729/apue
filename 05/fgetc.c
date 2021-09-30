#include <stdio.h>

int main() {
    int c, result;

    while ((c = fgetc(stdin)) != EOF) {
        putc(c, stdout);
    }

    if ((result = ferror(stdin)) != 0) {
        printf("ferror occurs! result = %d\n", result);
    }

    if ((result = feof(stdin)) != 0) {
        printf("feof occurs!\n");
    }

    return 0;
}
