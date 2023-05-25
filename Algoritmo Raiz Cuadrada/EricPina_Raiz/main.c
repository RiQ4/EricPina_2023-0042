#include <stdio.h>
#include <stdlib.h>
/*Eric Pina 2023-0042*/

void main()
{

    double x, b;
    int run = 1;

    printf("\nCalculo de Raiz Cuadrada");

    while(run){
        int repeat = 1;
        printf("\nIntroduzca un Numero: ");

        scanf("%lf", &x);
        b = x;

        while(repeat) {

            if (b != (x/b)){
                b = 0.5*((x/b)+b);
            }
            else {
                printf("\nLa raiz de %lf es %lf", x, b);
                repeat = 0;
                printf("\n¿Desea repetir el programa? \n1 - Si \n0 - No\n");
                scanf("%d", &run);
            }
        }
    }
}

