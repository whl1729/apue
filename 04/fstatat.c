#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
    struct stat buf;
    int result;
    int flag = AT_SYMLINK_NOFOLLOW;

    if (argc < 3) {
        printf("Usage: ./stat pathname flag\n");
        printf("flag:\n");
        printf("      0 : AT_SYMLINK_NOFOLLOW\n");
        printf("      1 : AT_SYMLINK_FOLLOW\n");
        return 1;
    }

    if (atoi(argv[2]) != 0) {
        flag = AT_SYMLINK_FOLLOW;
    }

    memset(&buf, 0, sizeof(buf));

    if ((result = fstatat(AT_FDCWD, argv[1], &buf, flag)) != 0) {
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
