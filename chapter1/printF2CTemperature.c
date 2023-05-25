/*
* chapter 1.2
*/

#include <stdio.h>

int main(){

    float top, bottom, fahr, step;
    top = 300;
    bottom = 0;
    step = 20;
    fahr = bottom;

    while (fahr <= top) {
        float centigrade = 5 * (fahr - 32) / 9;
        printf("%3.0f\t%6.1f\n", fahr, centigrade);
        fahr += step;
    }

    return 0;
}