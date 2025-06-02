#include "kernel/types.h"
#include "user/user.h"

void thread_fn() {
//   printf("Thread running\n");
  printf("Exiting child thread\n");
  exit(0);
}

int main() {
  void *stack = malloc(4096);
  int tid = clone(stack);
  if (tid == 0) {
    printf("Entering child if\n");
    thread_fn();
  } else {
    // printf("ENTERING WAIT\n");
    wait(&tid);
    // printf("Parent done\n");
  }
//   free(stack);
  printf("Exiting via parent\n");
  exit(0);
//   return 0;
}