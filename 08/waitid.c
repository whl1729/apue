#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

void pr_siginfo(siginfo_t *info);

int main() {
    siginfo_t info;
    pid_t pid, child;
    int i, result;

    if ((pid = fork()) < 0) {
        printf("fork error! pid = %d\n", pid);
    } else if (pid == 0) {
        child = getpid();

        printf("child: pid = %d, ppid = %d\n", child, getppid());

        for (i = 0; i < 10; i++) {
            sleep(1);
            printf("child %d sleeping %d seconds\n", child, i+1);
        }

        printf(" child %d sleep enough. Bye~Bye~\n", child);
    } else {
        printf("parent: pid = %d, child = %d\n", getpid(), pid);

        /* test WNOHANG */
        memset(&info, 0, sizeof(siginfo_t));

        if ((result = waitid(P_PID, pid, &info, WNOHANG | WEXITED)) != 0) {
            printf("waitid(WNOHANG) error! result = %d\n", result);
        } else {
            printf("waitid(WNOHANG): siginfo: \n");
            pr_siginfo(&info);
        }

        /* test WNOWAIT */
        memset(&info, 0, sizeof(siginfo_t));

        if ((result = waitid(P_PID, pid, &info, WNOWAIT | WEXITED)) != 0) {
            printf("waitid(WNOWAIT) error! result = %d\n", result);
        } else {
            printf("waitid(WNOWAIT): siginfo: \n");
            pr_siginfo(&info);
        }

        /* test WEXITED */
        memset(&info, 0, sizeof(siginfo_t));

        if ((result = waitid(P_PID, pid, &info, WEXITED)) != 0) {
            printf("waitid(WEXITED) error! result = %d\n", result);
        } else {
            printf("waitid(WEXITED): siginfo: \n");
            pr_siginfo(&info);
        }

        /* test WEXITED again */
        memset(&info, 0, sizeof(siginfo_t));

        if ((result = waitid(P_PID, pid, &info, WEXITED)) != 0) {
            printf("waitid(WEXITED) error! result = %d\n", result);
        } else {
            printf("waitid(WEXITED): siginfo: \n");
            pr_siginfo(&info);
        }
    }

    return 0;
}

void pr_siginfo(siginfo_t * info) {
    if (info == NULL) {
        printf("error! null siginfo\n");
        return;
    }

    printf("si_signo: %d\n", info->si_signo);
    printf("si_errno: %d\n", info->si_errno);
    printf("si_code : %d\n", info->si_code);
}
