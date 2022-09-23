#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define LEN 100000

int count;
int arr1[LEN];
int arr2[LEN];

void *thread1_func(void *arg) {
  for (int i = 0; i < LEN; i++) {
    count++;
    arr1[i] = count;
    // printf("thread 1: count = %d\n", count);
  }

  return ((void *)1);
}

void *thread2_func(void *arg) {
  for (int i = 0; i < LEN; i++) {
    count--;
    arr2[i] = count;
    // printf("thread 2: count = %d\n", count);
  }

  return ((void *)2);
}

void print_array() {
  for (int i = 0; i < LEN; i++) {
    printf("%7d: (%7d, %7d)\n", i, arr1[i], arr2[i]);
  }
}

int main() {
  int err;
  pthread_t tid1, tid2;

  count = 0;

  err = pthread_create(&tid1, NULL, thread1_func, NULL);
  if (err != 0) {
    printf("fail to create thread 1\n");
    return 1;
  }

  err = pthread_create(&tid2, NULL, thread2_func, NULL);
  if (err != 0) {
    printf("fail to create thread 2\n");
    return 2;
  }

  err = pthread_join(tid1, NULL);
  if (err != 0) {
    printf("fail to join with thread 1\n");
    return 3;
  }

  err = pthread_join(tid2, NULL);
  if (err != 0) {
    printf("fail to join with thread 2\n");
    return 4;
  }

  print_array();
  printf("main: count = %d\n", count);
  return 0;
}
