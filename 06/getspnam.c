#include <shadow.h>
#include <stdio.h>
#include <string.h>

struct spwd *get_pw(const char *name);
void print_spwd(struct spwd *pw);

int main(int argc, char *argv[]) {
    struct spwd *pw;

    if (argc < 2) {
        printf("usage: ./getspnam username\n");
        return 1;
    }

    pw = get_pw(argv[1]);
    print_spwd(pw);
    return 0;
}

struct spwd *get_pw(const char *name) {
    struct spwd *cur;

    if (name == NULL) {
        printf("get_pw error! null name.\n");
        return NULL;
    }

    while ((cur = getspnam(name)) != NULL) {
        if (strcmp(cur->sp_namp, name) == 0) {
            return cur;
        }
    }

    return NULL;
}

void print_spwd(struct spwd *pw) {
    if (pw == NULL) {
        printf("print_spwd error! null pw.\n");
        return;
    }

    printf("sp_namp: %s\n", pw->sp_namp);
    printf("sp_pwdp: %s\n", pw->sp_pwdp);
    printf("sp_lstchg: %ld\n", pw->sp_lstchg);
    printf("sp_min: %ld\n", pw->sp_min);
    printf("sp_max: %ld\n", pw->sp_max);
    printf("sp_warn: %ld\n", pw->sp_warn);
    printf("sp_inact: %ld\n", pw->sp_inact);
    printf("sp_expire: %ld\n", pw->sp_expire);
    printf("sp_flag: %lu\n", pw->sp_flag);
}
