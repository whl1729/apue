#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int in_fd, out_fd;
    ssize_t result;
    char buf;

    if (argc < 3) {
        printf("usage: cp_nohole srcpath destpath\n");
        return 1;
    }

    if ((in_fd = open(argv[1], O_RDONLY)) < 0) {
        printf("open %s error! result = %d\n", argv[1], in_fd);
        return 1;
    }

    if ((out_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644)) < 0) {
        printf("open %s error! result = %d\n", argv[2], out_fd);
        return 1;
    }

    while ((result = read(in_fd, (void *)&buf, 1)) > 0) {
        if (buf == 0) {
            continue;
        }

        if ((result = write(out_fd, (void *)&buf, 1)) < 0) {
            printf("write error! result = %ld\n", result);
            break;
        }
    }

    close(in_fd);
    close(out_fd);
    return 0;
}
