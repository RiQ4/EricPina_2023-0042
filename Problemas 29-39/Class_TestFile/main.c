#include <stdio.h>
#include <stdlib.h>

/* Programa para calcular descuento de 11% si x>1,500
    Eric Pina 2023-0042     */

void main()
{
    float PRICE = 0;
    float F_PRICE = 0;
    printf("\nIngrese un precio: ");
    scanf("%f", &PRICE);

    if (PRICE>1500) {
        F_PRICE = PRICE * 1.11;
        printf("\nEl precio final es de %7.2f", F_PRICE);
    }
    else if (PRICE>0 && PRICE <= 1500){
        F_PRICE = PRICE*(1-0.11);
        printf("\nEl precio final es de %7.2f", F_PRICE);
    }

}
