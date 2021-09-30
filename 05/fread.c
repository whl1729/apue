#include <stdio.h>

#define NAME_LEN 20

struct student {
    int age;
    char name[NAME_LEN];
};

int main() {
    size_t n;
    struct student sysu[3];

    if ((n = fread(sysu, sizeof(struct student), 3, stdin)) != 3) {
        printf("fread error! n = %ld\n", n);
        return 1;
    }

    if ((n = fwrite(sysu, sizeof(struct student), 3, stdout)) != 3) {
        printf("fwrite error! n = %ld\n", n);
        return 1;
    }

    return 0;
}
