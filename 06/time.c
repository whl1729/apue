#include <time.h>
#include <stdio.h>

int main() {
    time_t t;
    if ((t = time(NULL)) < 0) {
        printf("time error! t = %ld\n", t); 
    }

    printf("current time: %ld\n", t);
    return 0;
}
