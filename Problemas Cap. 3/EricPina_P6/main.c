#include <stdio.h>
#include <stdlib.h>
void main()
{
    int i;
    double PRI = 0;
    double SEG = 1;
    double SIG;

    printf("\t %d \t %d", PRI, SEG);
    for (i = 3; i<= 50; i++)
    {
        SIG = PRI + SEG;
        PRI = SEG;
        SEG = SIG;
        printf("\t %.0lf", SIG);
    }
}
