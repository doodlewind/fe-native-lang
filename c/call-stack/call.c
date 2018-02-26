#include <stdio.h>

int add(int a, int b);

int add(int a, int b) { return a + b; }

int main(int argc, char *argv[]) {
  int x = add(1, 2);
  printf("%d\n", x);

  return 0;
}
