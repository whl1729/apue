#include <pwd.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>

struct passwd *getpwnam(const char *name);
void printpwent(struct passwd *pw);

int main(int argc, char *argv[]) {
    struct passwd *pw;

    if (argc < 2) {
        printf("usage: getpwnam username\n");
        return 1;
    }

    pw = getpwnam(argv[1]);
    printpwent(pw);

    return 0;
}

struct passwd *getpwnam(const char *name) {
    struct passwd *ptr;
    struct passwd *result = NULL;

    setpwent();
    while ((ptr = getpwent()) != NULL) {
        if (strcmp(name, ptr->pw_name) == 0) {
            result = ptr;
            break;
        }
    }
    endpwent();
    return result;
}

void printpwent(struct passwd *pw) {
    if (pw == NULL) {
        printf("error! null passwd ptr\n");
        return;
    }

    printf("pw_name: %s\n", pw->pw_name);
    printf("pw_passwd: %s\n", pw->pw_passwd);
    printf("pw_uid: %u\n", pw->pw_uid);
    printf("pw_gid: %u\n", pw->pw_gid);
    printf("pw_gecos: %s\n", pw->pw_gecos);
    printf("pw_dir: %s\n", pw->pw_dir);
    printf("pw_shell: %s\n", pw->pw_shell);
}
