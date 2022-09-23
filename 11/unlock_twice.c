#include <pthread.h>
#include <stdio.h>

int main() {
  pthread_mutex_t mutex;

  if (pthread_mutex_init(&mutex, NULL) != 0) {
    printf("fail to initialize mutex\n");
    return 1;
  }

  if (pthread_mutex_lock(&mutex) != 0) {
    printf("fail to lock mutex\n");
    return 2;
  }

  printf("lock ok\n");

  if (pthread_mutex_unlock(&mutex) != 0) {
    printf("fail to unlock mutex\n");
    return 3;
  }

  printf("unlock ok\n");

  if (pthread_mutex_unlock(&mutex) != 0) {
    printf("fail to unlock mutex again\n");
    return 4;
  }

  printf("unlock again ok\n");

  return 0;
}
