#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr;
    int i;

    if ((arr = malloc(sizeof(int) * 10)) == NULL) {
        printf("malloc error!\n");
        return 1;
    }

    *(arr-1) = -1;

    for (i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
    free(arr);

    return 0;
}
