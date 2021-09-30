#include <sys/utsname.h>
#include <string.h>
#include <stdio.h>

void print_uname(struct utsname *info);

int main() {
    struct utsname info;
    int result;

    memset((void *)&info, 0, sizeof(struct utsname));

    if ((result = uname(&info)) < 0) {
        printf("uname error! result = %d\n", result);
        return 1;
    }

    print_uname(&info);

    return 0;
}

void print_uname(struct utsname *info) {
    if (info == NULL) {
        printf("error! null info.\n");
    }

    printf("sysname:  %s\n", info->sysname);
    printf("nodename: %s\n", info->nodename);
    printf("release:  %s\n", info->release);
    printf("version:  %s\n", info->version);
    printf("machine:  %s\n", info->machine);

#ifdef _GNU_SOURCE
    printf("domainname: %s\n", info->domainname);
#endif
}
