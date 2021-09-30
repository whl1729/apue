#include <stdio.h>

int main() {
    char name[40];
    printf("What's your name? ");
    scanf(" %39[^\n]", name);
    printf("Hello %s!\n", name);

    return 0;
}
