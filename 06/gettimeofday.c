#include <sys/time.h>
#include <stdio.h>
#include <string.h>

int main() {
    struct timeval tv;
    int result;

    memset((void *)&tv, 0, sizeof(struct timeval));

    if ((result = gettimeofday(&tv, NULL)) != 0) {
        printf("gettimeofday error! result = %d\n", result);
        return 1;
    }

    printf("sec: %ld, usec: %ld\n", tv.tv_sec, tv.tv_usec);

    return 0;
}
