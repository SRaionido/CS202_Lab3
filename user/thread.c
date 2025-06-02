// TO BE IMPLEMENTED - NEW USER LIBRARY
#include "kernel/types.h"
#include "user/user.h"
#include "user/thread.h"
typedef unsigned int uint;


#define STACK_SIZE 4096

int
thread_create(void *(*start_routine)(void *), void *arg)
{
  // Allocate user stack
  void *stack = malloc(STACK_SIZE);
  if (stack == 0)
    return -1;

  // clone() expects the top of the stack (stack grows down)
  int pid = clone(stack);
  if (pid < 0) {
    free(stack);
    return -1;
  }

  // Parent
  if (pid > 0)
    return 0;

  // Child thread
  start_routine(arg); // Run thread function
  exit(0);

  // Hopefully wont get here
  return 0;
}

void lock_init(struct lock_t *lock) {
  lock->locked = 0;
}

void lock_acquire(struct lock_t *lock) {
  while (__sync_lock_test_and_set(&lock->locked, 1) != 0);
}

void lock_release(struct lock_t *lock) {
  __sync_lock_release(&lock->locked);
}