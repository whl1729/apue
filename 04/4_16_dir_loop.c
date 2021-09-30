#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    char dir[] = "foo";
    int result;

    while (1) {
        if ((result = mkdir(dir, 0755)) != 0) {
            printf("mkdir error! result = %d\n", result);
            return 1;
        }

        if ((result = chdir(dir)) != 0) {
            printf("chdir error! result = %d\n", result);
            return 1;
        }
    }

    return 0;
}
