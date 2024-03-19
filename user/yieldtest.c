#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

const int nonblock = 1;

void yieldtest(void) {
  printf("yield test\n");

  for (int i = 0; i < 3; i++) {
    int pid = fork();
    if (pid == 0) {
      printf("switch to child %d\n", i);
      exit(0);
    } else {
    }
  }
  printf("parent yield\n");
  // yield之后
  // 在单核情况下，调度器应当调度到子进程
  yield();
  printf("parent yield finished\n");
  for (int i = 0; i < 3; i++) {
    wait(0, 0);
  }
}

int main(int argc, char *argv[]) {
  yieldtest();
  exit(0);
}