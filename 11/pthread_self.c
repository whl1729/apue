#include <pthread.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  pid_t pid = getpid();
  pthread_t tid = pthread_self();

  printf("current pid: %u\n", pid);
  printf("current tid: %lu\n", tid);
  printf("current tid(in hexdecimal): %#lx\n", tid);

  return 0;
}
