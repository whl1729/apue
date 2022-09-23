#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define COUNT 1000000

struct foo {
  int count;
  pthread_mutex_t lock;
};

// allocate the object
struct foo *foo_alloc() {
  struct foo *fp;
  if ((fp = malloc(sizeof(struct foo))) != NULL) {
    fp->count = 0;
    if (pthread_mutex_init(&fp->lock, NULL) != 0) {
      free(fp);
      return NULL;
    }
  }

  return fp;
}

// add a count to the object
void foo_add(struct foo *fp) {
  pthread_mutex_lock(&fp->lock);
  fp->count++;
  pthread_mutex_unlock(&fp->lock);
}

// decrease a count to the object
void foo_dec(struct foo *fp) {
  pthread_mutex_lock(&fp->lock);
  fp->count--;
  pthread_mutex_unlock(&fp->lock);
}

/* release the object */
void foo_release(struct foo *fp) {
  pthread_mutex_destroy(&fp->lock);
  free(fp);
}

void *thread1_func(void *fp) {
  for (int i = 0; i < COUNT; i++) {
    foo_add(fp);
  }

  return (void *)1;
}

void *thread2_func(void *fp) {
  for (int i = 0; i < COUNT; i++) {
    foo_dec(fp);
  }

  return (void *)2;
}

struct foo *fp;

int main() {
  int err;
  pthread_t tid1, tid2;

  fp = foo_alloc();
  if (fp == NULL) {
    printf("fail to allocate foo\n");
    return 1;
  }

  err = pthread_create(&tid1, NULL, thread1_func, fp);
  if (err != 0) {
    printf("fail to create thread 1\n");
    return 2;
  }

  err = pthread_create(&tid2, NULL, thread2_func, fp);
  if (err != 0) {
    printf("fail to create thread 2\n");
    return 3;
  }

  err = pthread_join(tid1, NULL);
  if (err != 0) {
    printf("fail to join with thread 1\n");
    return 4;
  }

  err = pthread_join(tid2, NULL);
  if (err != 0) {
    printf("fail to join with thread 2\n");
    return 5;
  }

  printf("main: count = %d\n", fp->count);

  foo_release(fp);

  return 0;
}
