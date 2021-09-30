#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    char *value;

    if (argc < 2) {
        printf("usage: ./getenv name\n");
        return 1;
    }

    if ((value = getenv(argv[1])) == NULL) {
        printf("getenv error!\n");
        return 1;
    }

    printf("%s=%s\n", argv[1], value);
    return 0;
}
