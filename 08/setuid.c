#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int uid;
    int result;

    if (argc < 2) {
        printf("usage: ./setuid uid\n");
        return 1;
    }

    uid = atoi(argv[1]);

    if ((result = setuid(uid)) < 0) {
        printf("error! setuid returns: %d\n", result);
        return 1;
    }

    printf("current uid: %d\n", getuid());
    printf("current euid: %d\n", geteuid());

    return 0;
}
