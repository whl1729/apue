#include <pthread.h>
#include <stdio.h>
#include <time.h>

struct task {
  int data;
  pthread_rwlock_t rwlock;
};

struct task task;

int init_task(struct task *task) {
  int err;

  task->data = 0;
  err = pthread_rwlock_init(&task->rwlock, NULL);
  if (err != 0) {
    printf("pthread_rwlock_init error: %d\n", err);
    return err;
  }

  return 0;
}

int main() {
  int err;
  struct timespec future;

  init_task(&task);

  err = pthread_rwlock_wrlock(&task.rwlock);
  if (err != 0) {
    printf("pthread_rwlock_wrlock error: %d\n", err);
    return 1;
  }

  err = pthread_rwlock_tryrdlock(&task.rwlock);
  if (err != 0) {
    printf("pthread_rwlock_tryrdlock error: %d\n", err);
  } else {
    printf("pthread_rwlock_tryrdlock ok\n");
  }

  err = pthread_rwlock_trywrlock(&task.rwlock);
  if (err != 0) {
    printf("pthread_rwlock_trywrlock error: %d\n", err);
  } else {
    printf("pthread_rwlock_trywrlock ok\n");
  }

  clock_gettime(CLOCK_REALTIME, &future);
  future.tv_sec += 3;
  printf("future.tv_sec: %ld\n", future.tv_sec);
  err = pthread_rwlock_timedrdlock(&task.rwlock, &future);
  if (err != 0) {
    printf("pthread_rwlock_timedrdlock error: %d\n", err);
  } else {
    printf("pthread_rwlock_timedrdlock ok\n");
  }

  future.tv_sec += 3;
  err = pthread_rwlock_timedwrlock(&task.rwlock, &future);
  if (err != 0) {
    printf("pthread_rwlock_timedwrlock error: %d\n", err);
  } else {
    printf("pthread_rwlock_timedwrlock ok\n");
  }

  err = pthread_rwlock_unlock(&task.rwlock);
  if (err != 0) {
    printf("pthread_rwlock_unlock error: %d\n", err);
    return 2;
  }

  return 0;
}
