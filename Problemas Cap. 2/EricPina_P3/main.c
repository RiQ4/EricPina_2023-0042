#include <stdio.h>
#include <math.h>
#define REF_DIST 500
#define REF_TIME 10

void main()
{
    float DIST, TIM, BIL;
    printf("\nCalculo de Ticket de Viaje: \nIngrese la distancia en Km: ");
    scanf("%f", &DIST);
    printf("\nIngrese el tiempo en H: ");
    scanf("%f", &TIM);

    if ((DIST*2)>500 && TIM>10) {
        BIL = ((DIST*2)*0.19)*0.80;
    }
    else {
        BIL = (DIST*2)*0.19;
    }
    printf("\nEl costo de su boleto es de %7.2f", BIL);



}
