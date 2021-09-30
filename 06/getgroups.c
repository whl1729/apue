#include <unistd.h>
#include <stdio.h>
#include <grp.h>

#define GRP_SIZE 16

void print_groups(gid_t grps[], int size);
struct group *get_grp(gid_t gid);
void print_grp(struct group *grp);

int main() {
    int num;
    gid_t grps[GRP_SIZE] = {0};

    if ((num = getgroups(GRP_SIZE, grps)) < 0) {
        printf("getgroups error! num = %d\n", num);
        return 1;
    }

    print_groups(grps, num);

    return 0;
}

void print_groups(gid_t grps[], int size) {
    int i;
    struct group *grp;

    for (i = 0; i < size; i++) {
        grp = get_grp(grps[i]);
        print_grp(grp);
    }
}

struct group *get_grp(gid_t gid) {
    struct group *cur;

    while ((cur = getgrgid(gid)) != NULL) {
        if (cur->gr_gid == gid) {
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

    printf("\n\n");
}
