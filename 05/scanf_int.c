#include <stdio.h>

int main() {
    int a;
    printf("enter a number: ");

    while (scanf("%d", &a) != 1) {
        printf("enter a number:");
    }

    printf("You entered %d.\n", a);

    return 0;
}
