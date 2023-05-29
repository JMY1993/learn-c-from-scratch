#include <stdio.h>

#define MAXLENGTH 1000

int mygetline(char line[], int maxline);
void copy(char to[], char from[]);

int main() {

    int len;
    int max;
    char line[MAXLENGTH];
    char longest[MAXLENGTH];

    max = 0;
    while ((len = mygetline(line, MAXLENGTH)) > 0) {
        if (len > max) {
            max = len;
            copy(longest, line);
        }

        if (max > 0) {
            printf("%s", longest);
        }
    }

    return 0;

}

int mygetline(char s[], int lim){

    char c;
    int i;
    for (i = 0; i<lim-1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }

    if (c=='\n') {
        s[i] = '\n';
        ++i;
    }

    s[i] = '\0';

    return i;
}

void copy(char to[], char from[]) {
    for (int i = 0; (to[i] = from[i]) != '\0'; i++) {
        ;
    }
}