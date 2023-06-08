#include <stdio.h>
#include <math.h>


void parim(int NUM, int *P, int *I);

void main(void)
{
    int I, N, NUM, PAR = 0, IMP = 0;
    printf("Ingresa el numero de datos: ");
    scanf("%d", &N);
    for (I =1; I <= N; I++)
    {
        printf("Ingresa el numero %d: ", I);
        scanf("%d", &NUM);
        parimp(NUM, &PAR, &IMP);
    }
    printf("\nCantidad de pares: %d", PAR);
    printf("\nCantidad de impares: %d", IMP);
}
void parimp(int NUM, int *P, int *I)

{
    int RES;
    RES = pow(-1, NUM);
    if (RES > 0)
        *P += 1;
    else if (RES < 0)
        *I += 1;
}

