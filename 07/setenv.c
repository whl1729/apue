#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int result;
    char *value;

    if (argc < 4) {
        printf("usage: ./setenv name value rewrite_flag\n");
        return 1;
    }

    if ((result = setenv(argv[1], argv[2], atoi(argv[3]))) != 0) {
        printf("setenv error! result = %d\n", result);
        return 1;
    }

    if ((value = getenv(argv[1])) == NULL) {
        printf("getenv(%s) error!\n", argv[1]);
        return 1;
    }

    if (strcmp(value, argv[2]) != 0) {
        printf("after setenv, expect: %s=%s, actual: %s=%s\n", argv[1], argv[2], argv[1], value);
        return 1;
    }

    printf("after setenv, %s=%s\n", argv[1], value);

    return 0;
}
