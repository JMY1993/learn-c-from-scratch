/* count word version 1.0 
* this is just a bare-bone version of linux program wc
*/

#include <stdio.h>

#define IN 1
#define OUT 0

int main(){

    int inside = OUT;

    int nl, nw, nc;
    nl = nw = nc = 0;

    int chr;

    while ((chr = getchar()) != EOF) {
        ++nc;
        if (chr == '\n') ++nl;

        if (chr == '\t' || chr == '\n' || chr == ' ') {
            inside = OUT;
        } else if (inside == OUT) {
            inside = IN;
            ++nw;
        }
    }

    printf("\t %d \t %d \t %d\n", nl, nw, nc);
}