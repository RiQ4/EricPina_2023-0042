#include <stdio.h>
#include <math.h>

void main()
{
    int T, P, N;

    printf("\nIngrese un Numerador: ");
    scanf("%d", &T);
    printf("\nIngrese un Denominador: ");
    scanf("%d", &P);
    printf("\nIngrese un Exponente: ");
    scanf("%d", &N);

    if (P != 0) {
        if (pow((T/P), N) == pow(T, N)/pow(P, N)) {
            printf("\nLa igualdad es Verdadera.");
        }
        else {
            printf("\nLa igualdad es Falsa.");
        }
    }
    else printf("\nP no puede ser cero.");

}
