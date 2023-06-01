#include <stdio.h>
#include <stdlib.h>
#define MAX_VAL 2500


void main() {

    int I = 2, CAM = 1;
    long SSE = 0;
    while (I <= MAX_VAL+1) {

        SSE += I;
        printf("\t %d", I);

        if (CAM) {
            I += 5;
            CAM--;
        }
        else {
            I += 3;
            CAM++;
        }
    }
    printf("\nLa suma de la serie es: %ld", SSE);
}
