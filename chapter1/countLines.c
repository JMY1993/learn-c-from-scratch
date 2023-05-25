#include <stdio.h>

/* count lines in input */

int main() {

  int c, count, nl;

  count = 0;
  nl = 0;

  while ((c = getchar()) != EOF) {
    count++;
    if (c == '\n') {
      ++nl;
    }
  }

  printf("\nYou've entered %d characters in total, in %d lines", count, nl);
}