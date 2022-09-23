#include "apue.h"
#include <pthread.h>

void print_time(struct timespec *ts, char *msg) {
  char buf[64];
  struct tm *tmp;

  tmp = localtime(&ts->tv_sec);
  strftime(buf, sizeof(buf), "%r", tmp);
  printf("%s %s\n", msg, buf);
}

int main() {
  int err;
  struct timespec tout;
  pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

  pthread_mutex_lock(&lock);
  printf("mutex is locked\n");

  clock_gettime(CLOCK_REALTIME, &tout);
  print_time(&tout, "current time is");
  tout.tv_sec += 3; /* 3 seconds from now */

  /* caution: this could lead to deadlock */
  err = pthread_mutex_timedlock(&lock, &tout);

  clock_gettime(CLOCK_REALTIME, &tout);
  print_time(&tout, "the time is now");

  if (err == 0) {
    printf("mutex locked again!\n");
  } else {
    printf("can't lock mutex again: %s\n", strerror(err));
  }

  exit(0);
}
