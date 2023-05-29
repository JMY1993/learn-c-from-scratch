/* romove comments
* Write a program to remove all comments from a C program. Don't forget to handle quoted strings and character constants properly
* C comments do not nest.
*/

#include <stdio.h>

#define OUT 0
#define IN 1

int main() {
    int state = OUT;
    char c;
    while ((c = getchar()) != EOF) {
        if ( state == OUT ) {
            if (c == '/') {
                char c2 = getchar();
                if (c2 == '*') {
                    state = IN;
                } else {
                    putchar('/');
                    putchar(c2);
                }
            } else {
                putchar(c);
            }
        } else if ( state == IN ) {
            if (c == '*') {
                char c2 = getchar();
                if (c2 == '/') {
                    state = OUT;
                }
            }
        }
    }

    return 0;
}