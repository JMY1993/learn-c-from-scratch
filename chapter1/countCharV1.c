#include <stdio.h>

int main() {

  long nc = 0;
  while (getchar() != EOF) {
    ++nc;
  }
  printf("you've entered %ld characters in total.\n", nc);

  return 0;
}