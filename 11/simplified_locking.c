#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define COUNT 1000
#define NHASH 29
#define HASH(id) (((unsigned long)id) % NHASH)

struct foo *fh[NHASH];

pthread_mutex_t hashlock = PTHREAD_MUTEX_INITIALIZER;

struct foo {
  int f_count; /* protected by hashlock */
  pthread_mutex_t f_lock;
  int f_id;
  struct foo *f_next; /* protected by hashlock */
};

// allocate the object
struct foo *foo_alloc(int id) {
  struct foo *fp;
  int idx;

  if ((fp = malloc(sizeof(struct foo))) != NULL) {
    fp->f_count = 1;
    fp->f_id = id;
    if (pthread_mutex_init(&fp->f_lock, NULL) != 0) {
      free(fp);
      return NULL;
    }

    // 这里实现的实际上是链式哈希表的插入操作。
    // 首先对 key 进行哈希，得到哈希桶的索引，
    // 由于对应位置可能已经有数据了，这里把新数据插入到哈希桶的开头。
    idx = HASH(id);
    pthread_mutex_lock(&hashlock);
    fp->f_next = fh[idx];
    fh[idx] = fp;
    pthread_mutex_lock(&fp->f_lock);
    pthread_mutex_unlock(&hashlock);
    pthread_mutex_unlock(&fp->f_lock);
  }

  return fp;
}

// add a reference to the object
void foo_hold(struct foo *fp) {
  pthread_mutex_lock(&hashlock);
  fp->f_count++;
  pthread_mutex_unlock(&hashlock);
}

// find an existing object
struct foo *foo_find(int id) {
  struct foo *fp;

  pthread_mutex_lock(&hashlock);
  for (fp = fh[HASH(id)]; fp != NULL; fp = fp->f_next) {
    if (fp->f_id == id) {
      fp->f_count++;
      break;
    }
  }
  pthread_mutex_unlock(&hashlock);

  return fp;
}

// release a reference to the object
void foo_rele(struct foo *fp) {
  struct foo *tfp;
  int idx;

  pthread_mutex_lock(&hashlock);
  // last reference, remove from list
  if (--fp->f_count == 0) {
    idx = HASH(fp->f_id);
    tfp = fh[idx];
    if (tfp == fp) {
      fh[idx] = fp->f_next;
    } else {
      while (tfp->f_next != fp) {
        tfp = tfp->f_next;
      }
      tfp->f_next = fp->f_next;
    }

    pthread_mutex_unlock(&hashlock);
    pthread_mutex_destroy(&fp->f_lock);
    free(fp);
  } else {
    pthread_mutex_unlock(&hashlock);
  }
}

void *allocator(void *arg) {
  for (int i = 1; i <= COUNT; i++) {
    printf("allocator is allocating foo %d\n", i);
    foo_alloc(i);
    printf("allocator has allocated foo %d\n", i);
  }

  return (void *)1;
}

void *deallocator(void *arg) {
  struct foo *fp;
  int try_time;

  for (int i = 1; i <= COUNT; i++) {
    try_time = 1;
    while ((fp = foo_find(i)) == NULL) {
      printf("%d deallocator cannot find foo %d\n", try_time, i);
      try_time++;
    }
    printf("deallocator has found foo %d\n", i);
    printf("deallocator is releasing foo %d\n", i);
    foo_rele(fp);
    printf("deallocator has released foo %d\n", i);
  }

  return (void *)2;
}

int main() {
  pthread_t tid1, tid2;

  if (pthread_create(&tid1, NULL, allocator, NULL) != 0) {
    printf("fail to create thread 1\n");
    return 1;
  }

  if (pthread_create(&tid2, NULL, deallocator, NULL) != 0) {
    printf("fail to create thread 2\n");
    return 2;
  }

  if (pthread_join(tid1, NULL) != 0) {
    printf("fail to join with thread 1\n");
    return 3;
  }

  if (pthread_join(tid2, NULL) != 0) {
    printf("fail to join with thread 2\n");
    return 4;
  }

  return 0;
}
