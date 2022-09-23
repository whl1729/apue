#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define READER_NUM 10

struct job {
  struct job *j_next;
  struct job *j_prev;
  pthread_t j_id; // tells which thread handles this job
};

struct queue {
  struct job *q_head;
  struct job *q_tail;
  pthread_rwlock_t q_lock;
};

struct queue queue;
struct job jobs[READER_NUM];
int ids[READER_NUM];

// Initialize a queue.
int queue_init(struct queue *qp) {
  int err;

  qp->q_head = NULL;
  qp->q_tail = NULL;
  err = pthread_rwlock_init(&qp->q_lock, NULL);
  if (err != 0) {
    return err;
  }

  return 0;
}

// Insert a job at the head of the queue.
void job_insert(struct queue *qp, struct job *jp) {
  pthread_rwlock_wrlock(&qp->q_lock);
  jp->j_next = qp->q_head;
  jp->j_prev = NULL;
  if (qp->q_head != NULL) {
    qp->q_head->j_prev = jp;
  } else {
    qp->q_tail = jp; // list was empty
  }

  qp->q_head = jp;
  pthread_rwlock_unlock(&qp->q_lock);
}

// Append a job on the tail of the queue.
void job_append(struct queue *qp, struct job *jp) {
  pthread_rwlock_wrlock(&qp->q_lock);
  jp->j_prev = qp->q_tail;
  jp->j_next = NULL;
  if (qp->q_tail != NULL) {
    qp->q_tail->j_next = jp;
  } else {
    // list was empty
    qp->q_head = jp;
  }

  qp->q_tail = jp;
  pthread_rwlock_unlock(&qp->q_lock);
}

// Remove the given job from a queue.
// Caution: jp must be non-empty.
void job_remove(struct queue *qp, struct job *jp) {
  pthread_rwlock_wrlock(&qp->q_lock);
  if (jp == qp->q_head) {
    qp->q_head = jp->j_next;
    if (qp->q_tail == jp) {
      // The list contains only one job, i.e., *jp.
      qp->q_tail = NULL;
    } else {
      jp->j_next->j_prev = jp->j_prev;
    }
  } else if (jp == qp->q_tail) {
    qp->q_tail = jp->j_prev;
    jp->j_prev->j_next = jp->j_next;
  } else {
    jp->j_next->j_prev = jp->j_prev;
    jp->j_prev->j_next = jp->j_next;
  }
  pthread_rwlock_unlock(&qp->q_lock);
}

// Find a job for the given thread ID.
struct job *job_find(struct queue *qp, pthread_t id) {
  struct job *jp;

  // 为什么 rdlock 需要检查返回值，而 wrlock 不需要检查返回值？
  // 书中有解释：rwlock 的实现中可能对 rdlock 的数目有限制，超过限制会报错
  if (pthread_rwlock_rdlock(&qp->q_lock) != 0) {
    return NULL;
  }

  for (jp = qp->q_head; jp != NULL; jp = jp->j_next) {
    if (pthread_equal(jp->j_id, id)) {
      break;
    }
  }

  pthread_rwlock_unlock(&qp->q_lock);
  return jp;
}

void queue_print(struct queue *qp) {
  struct job *jp;

  if (pthread_rwlock_rdlock(&qp->q_lock) != 0) {
    return;
  }

  for (jp = qp->q_head; jp != NULL; jp = jp->j_next) {
    printf("%lu->", jp->j_id);
  }

  pthread_rwlock_unlock(&qp->q_lock);

  printf("NULL\n");
}

void queue_free(struct queue *qp) {
  pthread_rwlock_wrlock(&qp->q_lock);

  while (qp->q_head != NULL) {
    job_remove(qp, qp->q_head);
  }

  pthread_rwlock_unlock(&qp->q_lock);

  pthread_rwlock_destroy(&qp->q_lock);
}

void *reader(void *id) {
  int reader_id = *(int *)id;
  pthread_t tid = pthread_self();
  struct job *jp;
  for (int i = 0; i < 10; i++) {
    jp = job_find(&queue, tid);
    if (jp != NULL) {
      job_remove(&queue, jp);
      printf("reader %d (thread %lu) removes a job %p\n", reader_id, tid, jp);
      return (void *)1;
    }

    usleep(100);
  }

  printf("reader %d (thread %lu) cannot find any job\n", reader_id, tid);

  return (void *)0;
}

void *writer(void *ids) {
  pthread_t *tids = (pthread_t *)ids;
  for (int i = 0; i < READER_NUM; i++) {
    jobs[i].j_id = tids[i];
    jobs[i].j_prev = NULL;
    jobs[i].j_next = NULL;

    if (i % 2 == 0) {
      job_insert(&queue, jobs + i);
      printf("writer insert a job for thread %lu\n", tids[i]);
    } else {
      job_append(&queue, jobs + i);
      printf("writer append a job for thread %lu\n", tids[i]);
    }
  }

  queue_print(&queue);

  return (void *)0;
}

int main() {
  int err;
  pthread_t wtid;
  pthread_t rtid[READER_NUM];

  err = queue_init(&queue);
  if (err != 0) {
    printf("fail to initialize queue\n");
    return 1;
  }

  for (int i = 0; i < READER_NUM; i++) {
    ids[i] = i + 1;
    err = pthread_create(rtid + i, NULL, reader, (void *)(ids + i));
    if (err != 0) {
      printf("fail to create reader %d\n", i + 1);
      return 2;
    }
  }

  err = pthread_create(&wtid, NULL, writer, (void *)rtid);
  if (err != 0) {
    printf("fail to create writer\n");
    return 3;
  }

  for (int i = 0; i < READER_NUM; i++) {
    err = pthread_join(rtid[i], NULL);
    if (err != 0) {
      printf("fail to join with reader %d\n", i);
      return 4;
    }
  }

  err = pthread_join(wtid, NULL);
  if (err != 0) {
    printf("fail to join with writer %lu\n", wtid);
    return 5;
  }

  queue_print(&queue);
  queue_free(&queue);

  return 0;
}
