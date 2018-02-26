#include <stdio.h>

typedef struct {
  float height;
  float width;
} Rect;

Rect *initRect(float height, float width);

Rect *initRect(float height, float width) {
  Rect rect;
  rect.width = 16.0;
  rect.height = 9.0;
  return &rect;
}

int main(int argc, const char *argv[]) {
  Rect *rect = initRect(16.0, 9.0);
  printf("Size: %.0f - %.0f\n", rect->width, rect->height);

  return 0;
}
