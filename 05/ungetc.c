#include <stdio.h>

int main() {
    int c;
    int cnt = 0;
    int result;

    while ((c = getc(stdin)) != EOF) {
        if ((result = putc(c, stdout)) != c) {
            printf("putc error! result = %d\n", result);
        }

        if (cnt < 5) {
            cnt++;
            if ((result = ungetc(c, stdin)) != c) {
                printf("ungetc error! result = %d\n", result);
            }
        } else {
            cnt = 0;
        }
    }

    if ((result = ferror(stdin)) != 0) {
        printf("ferror occurs! result = %d\n", result);
    }

    if ((result = feof(stdin)) != 0) {
        printf("feof occurs! result = %d\n", result);
    }

    return 0;
}
