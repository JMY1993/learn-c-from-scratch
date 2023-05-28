#include <stdio.h>

/* count digits, white spaces, others */

int main(){

    int nw, no, c;

    nw = no = 0;

    int ndigits[10];

    for (int i = 0; i < 10; ++i) {
        ndigits[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        if (c == '\t' || c == '\n' || c == ' ') {
            ++nw;
        } else if (c >= '0' && c <='9') {
            ++ndigits[c-'0'];
        } else {
            ++no;
        }
    }

    printf("digits =");
    for (int i = 0; i<10; ++i) {
        printf("%d ",ndigits[i]);
    }
    printf(", white space = %d, other = %d\n", nw, no);
}