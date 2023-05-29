/* fold.c
* Write a program to "fold" long input lines into two or more shorter lines after the last non-blank character that occurs
* before the n-th column of input. Make sure your program does something intelligent with very long lines, and if there are
* no blanks or tabs before the specified column.
*/

#include <stdio.h>

#define IN 1
#define OUT 0
#define MAX_LINE_LENGTH 70

int main() {
    int currentWordN = 0;
    int currentLineN = 0;
    char currentWord[MAX_LINE_LENGTH];
    int state = OUT;

    char c;

    for (int i = 0; i<MAX_LINE_LENGTH; i++) {
        putchar('-');
    }
    putchar('\n');
    while ((c = getchar()) != EOF) {
        if ( c != ' ' && c != '\n') {
            if (state == OUT) state = IN;
            currentWord[currentWordN] = c;
            currentWordN++;
            if (currentWordN + currentLineN >= MAX_LINE_LENGTH) {
                putchar('\n');
                currentLineN = 0;
            }
        } else {
            if (currentWordN >= MAX_LINE_LENGTH) {
                for (int i = 0; i < currentWordN; i++) {
                    putchar(currentWord[i]);
                }
                printf(" \n ^ Error: single word exceeds line length limit, can't trancate line. You may start over.");

                currentWordN = 0;
                currentLineN = 0;
            } else if (state == IN) {
                for (int i = 0; i < currentWordN; i++) {
                    putchar(currentWord[i]);
                }
                currentLineN += currentWordN;
                currentWordN = 0;
            }
            putchar(c);
            if (c == '\n') {
                currentLineN = 0;
            } else {
                currentLineN++;
            }
            
            state = OUT;
        }
    }
    return 0;
}