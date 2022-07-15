#include <stdio.h>

FILE *open_data() {
  FILE *fp;
  char databuf[BUFSIZ]; /* setvbuf makes this the stdio buffer */

  printf("BUFSIZ=%d\n", BUFSIZ);

  if ((fp = fopen("/home/along/live/read/README.md", "r")) == NULL) {
    printf("fail to open /home/along/live/read/README.md!\n");
    return NULL;
  }

  if (setvbuf(fp, databuf, _IOLBF, BUFSIZ) != 0) {
    printf("fail to setvbuf\n");
    return NULL;
  }

  return fp;
}

int main() {
  char string[] = "hello world";
  FILE *fp = open_data();
  if (fp) {
    fwrite(string, sizeof(string), 5, fp);
  } else {
    printf("fp is null\n");
  }

  return 0;
}
