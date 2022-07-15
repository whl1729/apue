#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  int fd;
  int i;
  char name[20];
  char quit;
  for (i = 1; i <= 1025; i++) {
    printf("open file %d ", i);
    snprintf(name, 20, "/tmp/%d.txt", i);
    fd = open(name, O_CREAT);
    if (fd < 0) {
      printf("fail\n");
    } else {
      printf("ok: fd = %d\n", fd);
    }
  }

  while (quit != 'y') {
    printf("Would you like to quit? (y or n):");
    scanf("%c", &quit);
  }

  return 0;
}
