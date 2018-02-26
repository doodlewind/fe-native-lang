#include <stdio.h>

struct Screen {
  float height;
  float width;
};

int main(int argc, const char *argv[]) {
  struct Screen screen;
  screen.width = 16.0;
  screen.height = 9.0;
  printf("Size: %.0f - %.0f\n", screen.width, screen.height);

  return 0;
}
