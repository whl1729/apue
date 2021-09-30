#include <stdlib.h>
#include <stdio.h>

int main() {
    int i;
    void *ptr;
    size_t size = 1024*1024*1024;
    for (i = 0; ; i++) {
        if ((ptr = calloc(1, size)) == NULL) {
            printf("calloc error! i = %d\n", i);
            return 1;
        }

        printf("calloc ok! i = %d, ptr = %p\n", i, ptr);
    }

    return 0;
}
