#include <stdio.h>
#include <math.h>

void main()
{
    int NUM;

    printf("\nVerificacion de Numeros Pares: \nIngrese un numero: ");
    scanf("%d", &NUM);

    if (NUM != 0) {
        if (pow(-1, NUM)>0) {
            printf("\nPar.");
        }
        else {
            printf("\nImpar.");
        }
    }
    else {
        printf("\nNulo.");
    }
}
