#include <sys/wait.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>

/* version without signal handling */
int system(const char *cmdstring)
{
    pid_t pid;
    int status;

    if (cmdstring == NULL) {
        return 1;  /* always a command processor with UNIX */
    }

    if ((pid = fork()) < 0) {
        status = -1;  /* probably out of processes */
    } else if (pid == 0) {  /* child */
        execl("/bin/sh", "sh", "-c", cmdstring, (char *)0);
        _exit(127);  /* execl error */
    } else {
        while (waitpid(pid, &status, 0) < 0) {
            if (errno != EINTR) {
                status = -1;  /* error other than EINTR from waitpid() */
                break;
            }
        }
    }

    return status;
}

int main(int argc, char *argv[]) {
    int result;

    if (argc != 2) {
        printf("usage: ./mysystem cmdstring\n");
        return 1;
    }

    if ((result = system(argv[1])) != 0) {
        printf("system returns: %d\n", result);
        return 1;
    }

    return 0;
}
