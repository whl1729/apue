#include <grp.h>
#include <stdio.h>
#include <string.h>

struct group *get_grp(const char *grpname);
void print_grp(struct group *grp);

int main(int argc, char *argv[]) {
    struct group *grp;

    if (argc < 2) {
        printf("usage: ./getgrnam groupname\n");
        return 1;
    }

    grp = get_grp(argv[1]);
    print_grp(grp);
    return 0;
}

struct group *get_grp(const char *grpname) {
    struct group *cur;

    if (grpname == NULL) {
        printf("get_grp error! null grpname.\n");
        return NULL;
    }

    while ((cur = getgrnam(grpname)) != NULL) {
        if (strcmp(cur->gr_name, grpname) == 0) {
            return cur;
        }
    }

    return NULL;
}

void print_grp(struct group *grp) {
    int i;

    if (grp == NULL) {
        printf("print_grp error! null grp.\n");
        return;
    }

    printf("gr_name: %s\n", grp->gr_name);
    printf("gr_passwd: %s\n", grp->gr_passwd);
    printf("gr_gid: %d\n", grp->gr_gid);
    printf("gr_mem: ");

    for (i = 0; grp->gr_mem[i] != NULL; i++) {
        printf("%s ", grp->gr_mem[i]);
    }

    printf("\n");
}
