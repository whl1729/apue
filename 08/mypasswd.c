#include <unistd.h>
#include <stdio.h>

int main() {
    printf("before execlp(passwd):\n");
    printf("uid: %d, gid: %d, euid: %d, egid: %d\n",
            getuid(), getgid(), geteuid(), getegid());

    if (execlp("passwd", "passwd", "-a", (char *)0) < 0) {
        printf("execlp passwd error.\n");
        return 1;
    }

    printf("after execlp(passwd):\n");
    printf("uid: %d, gid: %d, euid: %d, egid: %d\n",
            getuid(), getgid(), geteuid(), getegid());

    return 0;
}
