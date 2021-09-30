#include "apue.h"

int get_file_type(char *file_name, char **file_type);

int main(int argc, char *argv[])
{
    int i, result;
    char *ptr;

    if (argc < 2) {
        printf("Usage: ./file_type file1 file2 file3 ...\n");
        return 1;
    }

    for (i = 1; i < argc; i++) {
        if ((result = get_file_type(argv[i], &ptr)) == 0) {
            printf("%s: %s\n", argv[i], ptr);
        } else {
            printf("get_file_type(\"%s\") error!\n", argv[i]);
        }
    }

    return 0;
}

int get_file_type(char *file_name, char **file_type)
{
    struct stat buf;

    if (lstat(file_name, &buf) < 0) {
        printf("lstat error\n");
        return 1;
    }

    if S_ISREG(buf.st_mode) {
        *file_type = "regular";
    } else if S_ISDIR(buf.st_mode) {
        *file_type = "directory";
    } else if S_ISCHR(buf.st_mode) {
        *file_type = "character special";
    } else if S_ISBLK(buf.st_mode) {
        *file_type = "block special";
    } else if S_ISFIFO(buf.st_mode) {
        *file_type = "fifo";
    } else if S_ISLNK(buf.st_mode) {
        *file_type = "symbolic link";
    } else if S_ISSOCK(buf.st_mode) {
        *file_type = "socket";
    } else {
        *file_type = "** unknown mode **";
    }

    return 0;
}
