#include <grp.h>
#include <stdio.h>
#include <string.h>

void print_all_grp();
void print_one_grp(struct group *grp);

int main(int argc, char *argv[]) {
    print_all_grp();
    return 0;
}

void print_all_grp() {
    struct group *cur;

    while ((cur = getgrent()) != NULL) {
        print_one_grp(cur);
        printf("\n");
    }
}

void print_one_grp(struct group *grp) {
    int i;

    if (grp == NULL) {
        printf("print_one_grp error! null grp.\n");
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
