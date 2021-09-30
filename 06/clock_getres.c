#include <sys/time.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

void print_clock_resolution(clockid_t clock_id, struct timespec *tsp);

int main() {
    int ids[] = { CLOCK_REALTIME, CLOCK_MONOTONIC, CLOCK_PROCESS_CPUTIME_ID, CLOCK_THREAD_CPUTIME_ID };
    int i, result;
    struct timespec tsp;

    for (i = 0; i < sizeof(ids) / sizeof(int); i++) {
        memset((void *)&tsp, 0, sizeof(tsp));

        if ((result = clock_getres(ids[i], &tsp)) != 0) {
            printf("clock_getres error! result = %d\n", result);
        } else {
            print_clock_resolution(ids[i], &tsp);
        }
    }

    return 0;
}

void print_clock_resolution(clockid_t clock_id, struct timespec *tsp) {
    switch (clock_id) {
        case CLOCK_REALTIME:
            printf("REALTIME: ");
            break;
        case CLOCK_MONOTONIC:
            printf("MONOTONIC_CLOCK: ");
            break;
        case CLOCK_PROCESS_CPUTIME_ID:
            printf("CPUTIME: ");
            break;
        case CLOCK_THREAD_CPUTIME_ID:
            printf("THREAD_CPUTIME: ");
            break;
        default:
            printf("unknown clock id! ");
            break;
    }

    printf("sec: %ld, nsec: %ld\n", tsp->tv_sec, tsp->tv_nsec);
}
