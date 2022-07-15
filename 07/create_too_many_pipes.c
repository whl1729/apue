#include <stdio.h>
#include <unistd.h>

#define PIPE_NUM 1024

int main() {
  int fd[PIPE_NUM][2] = {0};
  int result;

  for (int i = 0; i < PIPE_NUM; i++) {
    result = pipe(fd[i]);
    if (result != 0) {
      printf("pipe %d fail.\n", i);
      return 1;
    }

    printf("pipe %d ok.\n", i);
  }

  return 0;
}
