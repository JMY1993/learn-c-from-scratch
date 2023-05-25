#include <stdio.h>

int main() {
  double nc;
  for (nc = 0; getchar() != EOF; ++nc) {
  }
  printf("you've entered %.0f characters in total.\n", nc);

  return 0;
}