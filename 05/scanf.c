#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char c_foo;
    int i_foo;
    float f_foo;
    int result;
    char *buf = NULL;

    printf("Enter a character, an interger and a float number:\n");

    if ((result = scanf("%c%d%f", &c_foo, &i_foo, &f_foo)) <= 0) {
        printf("scanf error! result = %d\n", result);
    }

    printf("scanf result = %d\n", result);

    printf("c_foo=%d, i_foo=%d, f_foo=%f\n", c_foo, i_foo, f_foo);

    printf("Enter an sentence: ");

    if ((result = scanf("%ms", &buf)) <= 0) {
        printf("scanf error! result = %d\n", result);
    }

    printf("scanf result = %d, strlen(buf)= %ld\n", result, strlen(buf));

    printf("buf = %s\n", buf);

    free(buf);

    return 0;
}
