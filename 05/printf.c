#include <stdio.h>

int main() {
    int i_foo = 1000000000;
    int i_bar = -31415926;
    float f_foo = 3.1415926;
    float f_bar = 1729.142857;

    printf("%20d\n", i_foo);
    printf("%20d\n", i_bar);
    printf("% 20d\n", i_foo);
    printf("% 20d\n", i_bar);
    printf("%020d\n", i_foo);
    printf("%020d\n", i_bar);
    printf("%'d\n", i_foo);
    printf("%'d\n", i_bar);
    printf("%-20d\n", i_foo);
    printf("%-20d\n", i_bar);
    printf("%+d\n", i_foo);
    printf("%-d\n", i_bar);

    printf("%*.*f\n", 15, 4, f_foo);
    printf("%*.*f\n", 15, 4, f_bar);
    printf("%20.*f\n", 3, f_foo);
    printf("%20.*f\n", 3, f_bar);
    printf("%20.5f\n", f_foo);
    printf("%20.5f\n", f_bar);

    printf("%o\n", i_foo);
    printf("%o\n", i_bar);

    printf("%#o\n", i_foo);
    printf("%#o\n", i_bar);

    printf("%x\n", i_foo);
    printf("%x\n", i_bar);
    printf("%#X\n", i_foo);
    printf("%#X\n", i_bar);

    return 0;
}
