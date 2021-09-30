#include <malloc.h>
#include <stdio.h>

void display_mallinfo(void);

int main() {
    int *arr;

    printf("============== Before allocating blocks ==============\n");
    display_mallinfo();

    if ((arr = malloc(sizeof(int) * 1000)) == NULL) {
        printf("malloc error!\n");
        return 1;
    }

    printf("============== after allocating blocks ==============\n");
    display_mallinfo();

    free(arr);

    printf("============== after freeing blocks ==============\n");
    display_mallinfo();
    return 0;
}

void display_mallinfo(void) {
    struct mallinfo mi;

    mi = mallinfo();

    printf("Total non-mmapped bytes (arena):       %d\n", mi.arena);
    printf("# of free chunks (ordblks):            %d\n", mi.ordblks);
    printf("# of free fastbin blocks (smblks):     %d\n", mi.smblks);
    printf("# of mapped regions (hblks):           %d\n", mi.hblks);
    printf("Bytes in mapped regions (hblkhd):      %d\n", mi.hblkhd);
    printf("Max. total allocated space (usmblks):  %d\n", mi.usmblks);
    printf("Free bytes held in fastbins (fsmblks): %d\n", mi.fsmblks);
    printf("Total allocated space (uordblks):      %d\n", mi.uordblks);
    printf("Total free space (fordblks):           %d\n", mi.fordblks);
    printf("Topmost releasable block (keepcost):   %d\n", mi.keepcost);
}
