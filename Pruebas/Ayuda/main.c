#include <stdio.h>
#include <stdlib.h>
#define MAT0
#define MAT1
#define MAT2
double promedio();

/*
void main()
{
    int a = 81;
    int *ptrA;  //Declaracion de Puntero
    ptrA = &a;  //Direccion de a
    printf("\n%p", ptrA);  //Es equivalente a printf("\n%x", &a);
    printf("\n%d", *ptrA); //Imprime lo que esta dentro de a
}
*/
void main(){

    float a[3];
    a[MAT0] = 95;
    a[MAT1] = 65;
    a[MAT2] = 75;
    printf("\nEl valor del promedio es %lf", promedio());

}

double promedio() {
    int *ptrA;
    ptrA = &a;



}
