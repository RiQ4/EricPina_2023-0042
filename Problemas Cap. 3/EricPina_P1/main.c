#include <stdio.h>
#include <stdlib.h>

void main()
{
    int i, NUM;
    long FAC;
    printf("Ingrese un numero para calcular su factorial: ");
    scanf("%d", &NUM);

    if (NUM >= 0) {
        FAC = 1;
        for (i=1; i <= NUM; i++) {
            FAC *= i;
        }
        printf("\nEl factorial de %d es %ld", NUM, FAC);
    }
    else {
        printf("\nError en el dato.");
    }

}
