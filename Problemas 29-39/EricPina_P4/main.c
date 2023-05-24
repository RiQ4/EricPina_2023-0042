#include <stdio.h>
#include <math.h>
/* Eric Pina 2023-0042 */

void main() {

   float RAD, ALT, VOL, ARE;

   printf("\nIngrese el radio del cilindro: ");
   scanf("%f", &RAD);
   printf("\nIngrese la altura del cilindro: ");
   scanf("%f", &ALT);

   VOL = M_PI * pow(RAD, 2) * ALT;
   ARE = 2* M_PI * RAD * ALT;

   printf("\nEl volumen es de %6.2f \t El area es de %6.2f", VOL, ARE);
}
