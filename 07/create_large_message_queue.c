#include <fcntl.h>
#include <mqueue.h>
#include <stdio.h>
#include <sys/stat.h>

int main() {
  struct mq_attr attr;

  /* initialize the queue attributes */
  attr.mq_flags = 0;
  attr.mq_maxmsg = 10;
  attr.mq_msgsize = 1000;
  attr.mq_curmsgs = 0;

  mqd_t result = mq_open("first_mq", O_RDONLY | O_CREAT, 0644, &attr);
  printf("result: %d\n", result);
  return 0;
}
