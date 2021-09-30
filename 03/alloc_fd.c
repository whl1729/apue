#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#define NAME_MAX 40

int main() {
    int i, result;
    int fds[10];
    char name[NAME_MAX];

    printf("first we close stdin\n");

    if ((result = close(0)) != 0) {
        printf("close(0) error! result = %d\n", result);
        return 1;
    }

    printf("then we open 10 files\n");

    for (i = 0; i < 10; i++) {
        if ((result = snprintf(name, NAME_MAX, "/home/along/test/foo_%d.txt", i)) < 0) {
            printf("snprintf error! result = %d\n", result);
            return 1;
        }

        if ((result = open(name, O_RDWR | O_CREAT, 0644)) < 0) {
            printf("open(%s) error! result = %d\n", name, result);
            return 1;
        }

        fds[i] = result;
        printf("fd for %s: %d\n", name, result);
    }

    printf("now we close /home/along/test/foo_0.txt.\n");

    if ((result = close(fds[0])) != 0) {
        printf("close(%d) error! result = %d\n", fds[0], result);
        return 1;
    }

    printf("finally we open /home/along/test/foo_10.txt.\n");

    if ((result = open("/home/along/test/foo_10.txt", O_RDWR | O_CREAT, 0644)) < 0) {
        printf("open(/home/along/test/foo_10.txt) error! result = %d\n", result);
        return 1;
    }

    printf("fd for /home/along/test/foo_10.txt: %d\n", result);

    return 0;
}
