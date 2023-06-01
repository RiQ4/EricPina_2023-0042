#include <stdio.h>
#include <math.h>
#define CONS 820

void main()
{

    int R, T, Q, RES;
    printf("\nIngrese los valores de las variables: \nR: ");
    scanf("%d", &R);
    printf("\nT: ");
    scanf("%d", &T);
    printf("\nQ: ");
    scanf("%d", &Q);

    RES = pow(R, 4) - pow(T, 3) + 4 * pow(Q, 2);

    if (RES<CONS) {
        printf("\n%d, %d, %d", R, T, Q);
    }

}
