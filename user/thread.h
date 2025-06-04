#ifndef USER_THREAD_H
#define USER_THREAD_H

struct lock_t {
    uint locked;
};

// Thread API
int thread_create(void *(*start_routine)(void *), void *arg);

// Spinlock API
void lock_init(struct lock_t *lock);
void lock_acquire(struct lock_t *lock);
void lock_release(struct lock_t *lock);

#endif
