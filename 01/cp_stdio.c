#include "apue.h"

#define BUFFSIZE 4096

int main(int argc, char *argv[]) {
    int n, src_fileno, dest_fileno;
    char buf[BUFFSIZE];

    if (argc < 3) {
        printf("Usage: ./cp_stdio src_fileno dest_fileno\n");
        exit(1);
    }

    src_fileno = argv[1][0] - '0';
    dest_fileno = argv[2][0] - '0';

    while ((n = read(src_fileno, buf, BUFFSIZE)) > 0) {
        if (write(dest_fileno, buf, n) != n) {
            err_sys("write error");
        }
    }

    if (n < 0) {
        err_sys("read error");
    }

    exit(0);
}
