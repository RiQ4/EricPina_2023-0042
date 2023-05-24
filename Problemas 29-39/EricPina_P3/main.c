#include <stdio.h>
/* Eric Pina 2023-0042 */

void main(){

    float PIE, LIB, MET, KIL;

    printf("\nIngrese los datos del objeto: ");
    printf("\nLongitud en PIES: ");
    scanf("%f", &PIE);
    printf("\Peso en LIBRAS: ");
    scanf("%f", &LIB);

    MET = PIE * 0.3048;
    KIL = LIB * 0.453592;

    printf("\nLos datos del objeto son: \nLongitud: %5.2f METROS \t Peso: %5.2f KILOS", MET, KIL);

}

