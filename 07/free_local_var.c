#include <stdlib.h>

int main() {
    int foo = 10;
    free(&foo);
    return 0;
}
