/*
 * chapter 1.4 the print F2C temperature function, with for loop
 * symbolic constants is also used here
 */

#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

int main() {
    printf("F\tC\n");
    for (float fahr = LOWER; fahr <= UPPER; fahr += STEP) {
        printf("%3.0f\t%3.1f\n", fahr, (5.0/9.0)*(fahr-32));
    }
}