#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h>

void pr_exit(int status);
void pr_rusage(struct rusage *usg);

int main() {
    pid_t pid, result, child;
    struct rusage usg;
    int status = 0;
    int i;

    if ((pid = fork()) < 0) {
        printf("fork error! pid = %d\n", pid);
    } else if (pid == 0) {
        child = getpid();

        printf("child: pid = %d, ppid = %d\n", child, getppid());
        for (i = 0; i < 10; i++) {
            sleep(1);
            printf("child %d sleeping %d second(s)\n", child, i+1);
        }

        printf("child %d exit\n", child);

        exit(0);
    } else {
        memset(&usg, 0, sizeof(struct rusage));

        if ((result = wait4(pid, &status, 0, &usg)) < 0) {
            printf("wait4 error! result = %d\n", result);
        } else if (result != pid) {
            printf("wait4 error! result = %d, pid = %d\n", result, pid);
        } else {
            printf("wait4: status:\n");
            pr_exit(status);

            printf("wait4: rusgae:\n");
            pr_rusage(&usg);
        }
    }

    return 0;
}

void pr_exit(int status) {
    if (WIFEXITED(status)) {
        printf("normal termination, exit status = %d\n", WEXITSTATUS(status));
    } else if (WIFSIGNALED(status)) {
        printf("abnormal termination, signal number = %d%s\n", WTERMSIG(status),
#ifdef WCOREDUMP
                WCOREDUMP(status)? " (core file generated)": "");
#else
                "");
#endif
    } else if (WIFSTOPPED(status)) {
        printf("child stopped, signal number = %d\n", WSTOPSIG(status));
    }
}

void pr_rusage(struct rusage *usg) {
    if (usg == NULL) {
        printf("error! null rusage\n");
        return;
    }

    printf("ru_utime(user time): tv_sec: %ld, tv_usec: %ld\n", usg->ru_utime.tv_sec, usg->ru_utime.tv_usec);
    printf("ru_stime(system time): tv_sec: %ld, tv_usec: %ld\n", usg->ru_stime.tv_sec, usg->ru_stime.tv_usec);
    printf("ru_maxrss(Maximum resident set size in kilobytes): %ld\n", usg->ru_maxrss);
    printf("ru_minflt(Number of soft page faults): %ld\n", usg->ru_minflt);
    printf("ru_majflt(Number of hard page faults): %ld\n", usg->ru_majflt);
    printf("ru_inblock(Number of input operations via the file system): %ld\n", usg->ru_inblock);
    printf("ru_oublock(Number of output operations via the file system): %ld\n", usg->ru_oublock);
    printf("ru_nvcsw(Number of voluntary context switches): %ld\n", usg->ru_nvcsw);
    printf("ru_nivcsw(Number of involuntary context switches): %ld\n", usg->ru_nivcsw);
}
