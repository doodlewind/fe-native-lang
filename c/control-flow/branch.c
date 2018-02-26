#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
  srand(time(NULL));
  int r = rand();

  if (r % 2 == 1) {
    printf("odd number!\n");
  } else {
    printf("even number!\n");
  }

  return 0;
}
