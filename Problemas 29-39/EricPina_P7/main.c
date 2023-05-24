#include <stdio.h>
#include <math.h>
/* Eric Pina 2023-0042 */

void main()
{
    float X1, X2, X3, Y1, Y2, Y3, LA1, LA2, LA3, PER;

    printf("\nIngrese las coordenadas del primer punto: ");
    printf("\nX1: ");
    scanf("%f", &X1);
    printf("\nY1: ");
    scanf("%f", &Y1);
    printf("\nIngrese las coordenadas del segundo punto: ");
    printf("\nX2: ");
    scanf("%f", &X2);
    printf("\nY2: ");
    scanf("%f", &Y2);
    printf("\nIngrese las coordenadas del tercer punto: ");
    printf("\nX3: ");
    scanf("%f", &X3);
    printf("\nY3: ");
    scanf("%f", &Y3);

    LA1 = sqrt(pow(X1-X2, 2) + pow(Y1-Y2, 2));
    LA2 = sqrt(pow(X2-X3, 2) + pow(Y2-Y3, 2));
    LA3 = sqrt(pow(X1-X3, 2) + pow(Y1-Y3, 2));

    PER = LA1 + LA2 + LA3;

    printf("\nEl perimetro del triangulo es de %6.3f unidades.", PER);
}
