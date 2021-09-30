#include <time.h>
#include <stdio.h>

void print_tm(struct tm *ptm);
char *weekday(int wday);

int main() {
    time_t now;
    struct tm *ptm;

    if ((now = time(NULL)) < 0) {
        printf("time error! now = %ld\n", now);
        return 1;
    }

    if ((ptm = gmtime(&now)) == NULL) {
        printf("gmtime error!\n");
        return 1;
    }

    print_tm(ptm);

    return 0;
}

void print_tm(struct tm *ptm) {
    printf("%d/%d/%d %d:%d:%d %s\n",
            ptm->tm_year + 1900,
            ptm->tm_mon + 1,
            ptm->tm_mday,
            ptm->tm_hour,
            ptm->tm_min,
            ptm->tm_sec,
            weekday(ptm->tm_wday));

    printf("days since January 1: %d\n", ptm->tm_yday);
    printf("daylight saving time flag: %d\n", ptm->tm_isdst);
}

char *weekday(int wday) {
    switch (wday) {
        case 0:    return "Sunday";
        case 1:    return "Monday";
        case 2:    return "Tuesday";
        case 3:    return "Wednesday";
        case 4:    return "Thursday";
        case 5:    return "Friday";
        case 6:    return "Saturday";
        default:   return "unknown";
    }
}
