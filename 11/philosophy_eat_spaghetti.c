#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COUNT 1000

// 这里模拟「哲学家就餐」问题的餐具：
// 每位哲学家的左边和右边各有一根筷子，
// 他们需要拿到两边的筷子才能夹东西吃。
struct chopstick {
  pthread_mutex_t left_lock;
  pthread_mutex_t right_lock;
};

struct chopstick *chopstick;

struct chopstick *chopstick_alloc() {
  struct chopstick *chopstick;

  if ((chopstick = malloc(sizeof(struct chopstick))) != NULL) {
    if (pthread_mutex_init(&chopstick->left_lock, NULL) != 0) {
      printf("fail to initialize chopstick left lock\n");
      free(chopstick);
      return NULL;
    }

    if (pthread_mutex_init(&chopstick->right_lock, NULL) != 0) {
      printf("fail to initialize chopstick right lock\n");
      free(chopstick);
      return NULL;
    }
  }

  return chopstick;
}

void take_left(struct chopstick *chopstick, char *philosophy) {
  printf("%s is taking left chopstick\n", philosophy);
  pthread_mutex_lock(&chopstick->left_lock);
  printf("%s has taken left chopstick\n", philosophy);
}

void take_right(struct chopstick *chopstick, char *philosophy) {
  printf("%s is taking right chopstick\n", philosophy);
  pthread_mutex_lock(&chopstick->right_lock);
  printf("%s has taken right chopstick\n", philosophy);
}

void release_left(struct chopstick *chopstick, char *philosophy) {
  printf("%s is releasing left chopstick\n", philosophy);
  pthread_mutex_unlock(&chopstick->left_lock);
  printf("%s has released left chopstick\n", philosophy);
}

void release_right(struct chopstick *chopstick, char *philosophy) {
  printf("%s is releasing right chopstick\n", philosophy);
  pthread_mutex_unlock(&chopstick->right_lock);
  printf("%s has released right chopstick\n", philosophy);
}

void chopstick_release(struct chopstick *chopstick) {
  if (chopstick) {
    pthread_mutex_destroy(&chopstick->left_lock);
    pthread_mutex_destroy(&chopstick->right_lock);
    free(chopstick);
  }
}

void *eat_spaghetti(void *philosophy) {
  char *people = (char *)philosophy;
  if (strcmp(people, "philosophy1") == 0) {
    take_left(chopstick, people);
    take_right(chopstick, people);
    printf("%s is eating spaghetti\n", people);
    release_right(chopstick, people);
    release_left(chopstick, people);
  } else if (strcmp(people, "philosophy2") == 0) {
    take_right(chopstick, people);
    take_left(chopstick, people);
    printf("%s is eating spaghetti\n", people);
    release_left(chopstick, people);
    release_right(chopstick, people);
  } else {
    printf("unknow philosophy: %s\n", people);
  }

  return (void *)0;
}

void *eat_much_spaghetti(void *philosophy) {
  for (int i = 1; i <= COUNT; i++) {
    printf("%d. %s is goint to eat spaghetti\n", i, (char *)philosophy);
    eat_spaghetti(philosophy);
  }

  return (void *)0;
}

int main() {
  int err;
  pthread_t tid1, tid2;

  chopstick = chopstick_alloc();
  if (chopstick == NULL) {
    printf("fail to allocate chopstick\n");
    return 1;
  }

  err = pthread_create(&tid1, NULL, eat_much_spaghetti, (void *)"philosophy1");
  if (err != 0) {
    printf("fail to create thread 1\n");
    return 2;
  }

  err = pthread_create(&tid2, NULL, eat_much_spaghetti, (void *)"philosophy2");
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

  chopstick_release(chopstick);

  return 0;
}
