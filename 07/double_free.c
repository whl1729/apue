#include <stdlib.h>

int main() {
    int *foo;
    int *bar;

    foo = malloc(sizeof(int));
    free(foo);
    bar = malloc(sizeof(int));
    free(foo);
    *bar = 100;
    free(bar);

    return 0;
}
