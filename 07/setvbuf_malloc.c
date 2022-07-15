#include <stdio.h>
#include <stdlib.h>

// char *databuf;

FILE *open_data() {
  FILE *fp;
  char *databuf;

  printf("BUFSIZ=%d\n", BUFSIZ);

  /* setvbuf makes this the stdio buffer */
  databuf = malloc(BUFSIZ);

  if (databuf == NULL) {
    printf("error: fail to malloc memory for databuf!\n");
    return NULL;
  }

  if ((fp = fopen("/home/along/live/read/README.md", "r")) == NULL) {
    printf("error: fail to fopen /home/live/read/README.md!\n");
    return NULL;
  }

  if (setvbuf(fp, databuf, _IOLBF, BUFSIZ) != 0) {
    printf("error: fail to setvbuf!\n");
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
    printf("fp is null!\n");
  }

  // if (databuf) {
  //  free(databuf);
  //}
  return 0;
}
