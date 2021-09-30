#include <stdio.h>
#include <unistd.h>

int main() {
    int i;

    if (environ == NULL) {
        printf("error! null environ!\n");
        return 1;
    }

    for (i = 0; environ[i] != NULL; i++) {
        printf("environ[%d]: %s\n", i, environ[i]);
    }

    return 0;
}
