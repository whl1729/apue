#include <stdio.h>
#include <unistd.h>

int main() {
    long num = sysconf(_SC_OPEN_MAX);
    printf("OPEN_MAX=%ld\n", num);
    return 0;
}
