#include <unistd.h>
#include <stdio.h>
#include <limits.h>

int main() {
    char name[HOST_NAME_MAX+1] = {0};
    int result;

    if ((result = gethostname(name, HOST_NAME_MAX)) != 0) {
        printf("gethostname error! result = %d\n", result);
        return 1;
    }

    printf("hostname: %s\n", name);
    return 0;
}
