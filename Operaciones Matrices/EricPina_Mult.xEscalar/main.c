#include <stdio.h>
#include <stdlib.h>
#define TAM 3       //Tamano del arreglo.

void multE(int M[][TAM], int S); //Prototipo de la funcion mult. por escalar. Toma al arreglo y su tamano como argumentos.
void impresion(int M[][TAM], int F); //Prototipo Funcion impresion.

void main(void) //Funcion main() donde se declaran los arreglos a ser operados. Se llama la funcion resta.
{
    int A1[TAM][TAM] = {{5, 10, 15},  //Valores del Arreglo 1.
                        {20, 25, 30},
                        {35, 40, 45}};
    multE(A1, TAM);
}

void multE(int M[][TAM], int S)
{
    int E = 0; //Escalar.
    int R[S][S];
    printf("\nIndique el escalar entero por el cual la matriz sera multiplicada: ");
    scanf("%d", &E);

    for (int i = 0; i<S; i++) //Itera por las filas.
    {
        for (int j = 0; j<S; j++) //Itera por las clumnas
        {
            R[i][j] = M[i][j] * E;
        }
    }
    impresion(R, TAM); //Imprime el arreglo R por medio de la Funcion impresion.
}


void impresion(int M[][TAM], int F) //Funcion para imprimir arreglos 2D.
{
    for (int i = 0; i<F; i++) //Itera por las filas del arreglo
    {
        for (int j = 0; j<F; j++) //Itera por las columnas del arreglo
        {
            printf("\nResultado Posicion %d %d: %d ", i, j, M[i][j]); //Imprime el Resultado.

        }
    }
}


