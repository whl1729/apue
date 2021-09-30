#include <limits.h>
#include <stdio.h>

int main() {
    printf("----------- ISO C Limits ----------\n");
    printf("CHAR_BIT = %d\n", CHAR_BIT);
    printf("CHAR_MAX = %d\n", CHAR_MAX);
    printf("CHAR_MIN = %d\n", CHAR_MIN);
    printf("SCHAR_MAX = %d\n", SCHAR_MAX);
    printf("SCHAR_MIN = %d\n", SCHAR_MIN);
    printf("UCHAR_MAX = %u\n", UCHAR_MAX);
    printf("INT_MAX = %d\n", INT_MAX);
    printf("INT_MIN = %d\n", INT_MIN);
    printf("UINT_MAX = %u\n", UINT_MAX);
    printf("SHRT_MAX = %d\n", SHRT_MAX);
    printf("SHRT_MIN = %d\n", SHRT_MIN);
    printf("USHRT_MAX = %u\n", USHRT_MAX);
    printf("LONG_MAX = %ld\n", LONG_MAX);
    printf("LONG_MIN = %ld\n", LONG_MIN);
    printf("ULONG_MAX = %lu\n", ULONG_MAX);
    printf("LLONG_MAX = %lld\n", LLONG_MAX);
    printf("LLONG_MIN = %lld\n", LLONG_MIN);
    printf("ULLONG_MAX = %llu\n", ULLONG_MAX);
    printf("MB_LEN_MAX = %d\n", MB_LEN_MAX);

    printf("----------- POSIX Limits -----------\n");
    printf("_POSIX_ARG_MAX = %d\n", _POSIX_ARG_MAX);
    printf("_POSIX_CHILD_MAX = %d\n", _POSIX_CHILD_MAX);
    printf("_POSIX_DELAYTIMER_MAX = %d\n", _POSIX_DELAYTIMER_MAX);
    printf("_POSIX_HOST_NAME_MAX = %d\n", _POSIX_HOST_NAME_MAX);
    printf("_POSIX_LINK_MAX = %d\n", _POSIX_LINK_MAX);
    printf("_POSIX_LOGIN_NAME_MAX = %d\n", _POSIX_LOGIN_NAME_MAX);
    printf("_POSIX_MAX_CANON = %d\n", _POSIX_MAX_CANON);
    printf("_POSIX_MAX_INPUT = %d\n", _POSIX_MAX_INPUT);
    printf("_POSIX_NAME_MAX = %d\n", _POSIX_NAME_MAX);
    printf("_POSIX_NGROUPS_MAX = %d\n", _POSIX_NGROUPS_MAX);
    printf("_POSIX_OPEN_MAX = %d\n", _POSIX_OPEN_MAX);
    printf("_POSIX_PATH_MAX = %d\n", _POSIX_PATH_MAX);
    printf("_POSIX_PIPE_BUF = %d\n", _POSIX_PIPE_BUF);
    printf("_POSIX_RE_DUP_MAX = %d\n", _POSIX_RE_DUP_MAX);
    printf("_POSIX_RTSIG_MAX = %d\n", _POSIX_RTSIG_MAX);
    printf("_POSIX_SEM_NSEMS_MAX = %d\n", _POSIX_SEM_NSEMS_MAX);
    printf("_POSIX_SEM_VALUE_MAX = %d\n", _POSIX_SEM_VALUE_MAX);
    printf("_POSIX_SIGQUEUE_MAX = %d\n", _POSIX_SIGQUEUE_MAX);
    printf("_POSIX_SSIZE_MAX = %d\n", _POSIX_SSIZE_MAX);
    printf("_POSIX_STREAM_MAX = %d\n", _POSIX_STREAM_MAX);
    printf("_POSIX_SYMLINK_MAX = %d\n", _POSIX_SYMLINK_MAX);
    printf("_POSIX_SYMLOOP_MAX = %d\n", _POSIX_SYMLOOP_MAX);
    printf("_POSIX_TIMER_MAX = %d\n", _POSIX_TIMER_MAX);
    printf("_POSIX_TTY_NAME_MAX = %d\n", _POSIX_TTY_NAME_MAX);
    printf("_POSIX_TZNAME_MAX = %d\n", _POSIX_TZNAME_MAX);

    printf("---------- XSI Limits ----------\n");
    printf("NL_LANGMAX = %d\n", NL_LANGMAX);
    printf("NZERO = %d\n", NZERO);
    printf("_XOPEN_IOV_MAX = %d\n", _XOPEN_IOV_MAX);
    /* The following two constants doesn't exist in Linux */
    /* printf("_XOPEN_NAME_MAX = %d\n", _XOPEN_NAME_MAX); */
    /* printf("_XOPEN_PATH_MAX = %d\n", _XOPEN_PATH_MAX); */
    return 0;
}
