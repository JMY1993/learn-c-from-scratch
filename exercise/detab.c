#include <stdio.h>

#define INDENTATION 4

int main(){
    char c;
    printf("Input a few lines, to which this program is replacing the tabs with 4 consecutive spaces.\n");
    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            for (int i = 0; i<4; ++i) {
                putchar(' ');
            }
        } else {
            putchar(c);
        }
    }
    return 0;
}