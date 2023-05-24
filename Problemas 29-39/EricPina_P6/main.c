#include <stdio.h>
#include <math.h>
/* Eric Pina 2023-0042 */

void main()
{
   float LA1, LA2, LA3, AUX, ARE;

   printf("\nCalculo del area de un triangulo");
   printf("\nIngrese los lados del triangulo");
   printf("\nLado #1: ");
   scanf("%f", &LA1);
   printf("\nLado #2: ");
   scanf("%f", &LA2);
   printf("\nLado #3: ");
   scanf("%f", &LA3);

   AUX = (LA1+LA2+LA3)/2;
   ARE = sqrt(AUX*(AUX-LA1)*(AUX-LA2)*(AUX-LA3));

   printf("\nEl area del triangulo es de %6.2f unidades cuadradas", ARE);

}
