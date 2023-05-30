/**
 * write a program to check a C program for rudimentary syntax errors like
 * unbalanced parenthese, brackets and braces. Dont forget about quotes, both
 * single and double, escape sequences, and comments. (This program is hard if
 * you do it in full generality)
 *
 * note: for source files that work with char and string (like this one), this program may file on them
 * such program will typically have expressions like '"', or '\''. if that is the case, symbol ' and " are naturally single.
 */

#include <stdio.h>

#define MAX_NEST_LEVEL 100
#define NOTHING 3
#define CLOSE 2
#define OPEN 1
#define FAIL 0

char stack[MAX_NEST_LEVEL];
int lens = 0;

int push(char c);
int pop();
int pair(char c, char op, char cl);
int pair2(char c, char op1, char op2, char cl1, char cl2);
void printStack();
int pairMono(char c, char mono);

int main() {

  char c;
  while ((c = getchar()) != EOF) {
    putchar(c);
    if (!pair(c, '{', '}') || !pair(c, '[', ']') || !pair(c, '(', ')') ||
        !pairMono(c, '\'') || !pairMono(c, '"')) {

      printf(" <- Mismatching the opening for \'%c\'. The currently unpaired symbols are: ", c);
      printStack();
    }

    if (!pair2(c, '/', '*', '*', '/')) {
      printf(" <- Mismatching the opening for \'%c%c\'. The currently unpaired symbols are: ", '*', '/');
      printStack();
    }
  }
  if (lens > 0) {
    printf(" |^ Mismatching the closing for ");
    for (int i = 0; i < lens; i++) {
      putchar(stack[i]);
    }
    printf(".\n");
    lens = 0;
  }
}

int push(char c) {
  stack[lens] = c;
  return ++lens;
}

int pop() { return --lens; }

int pair(char c, char op, char cl) {
  if (c == cl) {
    if (lens == 0) {
      return FAIL;
    } else if (stack[lens - 1] == op) {
      pop();
      return CLOSE;
    } else {
      return FAIL;
    }
  } else if (c == op) {
    push(c);
    return OPEN;
  } else {
    return NOTHING;
  }
}

int pair2(char c, char op1, char op2, char cl1, char cl2) {
  if (c == op1) {
    char c2 = getchar();
    putchar(c2);
    if (c2 == op2) {
      push(op1);
      push(op2);
      return OPEN;
    } else {
      return NOTHING;
    }
  } else if (c == cl1) {
    char c2 = getchar();
    putchar(c2);
    // printf("stack[lens-1] is %c, stack [lens-2] is %c", stack[lens - 1], stack[lens - 2]);
    if (lens < 2) {
      return FAIL;
    } else if (c2 != cl2) {
      return NOTHING;
    } else if (c2 == cl2 && stack[lens - 1] == op2 && stack[lens - 2] == op1) {
      pop();
      pop();
      return CLOSE;
    } else {
      return FAIL;
    }
  } else {
    return NOTHING;
  }
}

int pairMono(char c, char mono) {
  if (c == mono) {
    if (stack[lens - 1] == mono) {
      pop();
      return CLOSE;
    } else {
      push(c);
      return OPEN;
    }
  } else {
    return NOTHING;
  }
}

void printStack() {
  for (int i = 0; i < lens; i++) {
    putchar(stack[i]);
  }
}