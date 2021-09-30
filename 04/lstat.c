#include <sys/stat.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    struct stat buf;
    int result;

    if (argc < 2) {
        printf("./stat pathname\n");
        return 1;
    }

    memset(&buf, 0, sizeof(buf));

    if ((result = lstat(argv[1], &buf)) != 0) {
        printf("stat error! result = %d\n", result);
        return result;
    }

    printf("st_mode: %#o\n", buf.st_mode);
    printf("st_ino: %lu\n", buf.st_ino);
    printf("st_dev: %lu\n", buf.st_dev);
    printf("st_rdev: %lu\n", buf.st_rdev);
    printf("st_nlink: %u\n", buf.st_nlink);
    printf("st_uid: %u\n", buf.st_uid);
    printf("st_gid: %u\n", buf.st_gid);
    printf("st_size: %lu\n", buf.st_size);
    printf("st_atim: tv_sec=%ld, tv_nsec=%ld\n", buf.st_atim.tv_sec, buf.st_atim.tv_nsec);
    printf("st_mtim: tv_sec=%ld, tv_nsec=%ld\n", buf.st_mtim.tv_sec, buf.st_mtim.tv_nsec);
    printf("st_ctim: tv_sec=%ld, tv_nsec=%ld\n", buf.st_ctim.tv_sec, buf.st_ctim.tv_nsec);
    printf("st_blksize: %d\n", buf.st_blksize);
    printf("st_blocks: %ld\n", buf.st_blocks);

    return 0;
}
