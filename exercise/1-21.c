/* entab.c
* write a program entab that replaces strings of blanks by the minimum number of tabs and blanks to achieve the same spacing
* use the same tab stops as for detab. When either a tab or a single blank would suffice to reach a tab stop, which should be
* given preference?
*/

#include <stdio.h>

#define INDENTATION 4

int main(){

    int nw = 0;
    char c;

    while ((c=getchar()) != EOF) {
        if (c != ' ') {
            if (nw > 0) {
                for (;nw > 0; --nw){
                    putchar(' ');
                }
            }
            putchar(c);
        } else if (nw+1 == INDENTATION) {
            putchar('\t');
            nw = 0;
        } else {
            ++nw;
        }
    }

    return 0;

}