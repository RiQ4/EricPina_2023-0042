#include <stdio.h>
#include <stdlib.h>
#define TAM 3 //Define el tamano del arreglo

void impresion(int M[][TAM], int F); //Declara los prototipos de las funciones impresion y resta de matrices.
void resta(int M1[][TAM], int M2[][TAM], int F);

void main(void) //Funcion main() donde se declaran los arreglos a ser operados. Se llama la funcion resta.
{
    int A1[TAM][TAM] = {{7, 22, 14},  //Valores del Arreglo 1.
                        {32, 12, 51},
                        {9, 18, 15}};

    int A2[TAM][TAM] = {{2, 4, 6}, //Valores del Arreglo 2.
                        {8, 10, 12},
                        {14, 16, 18}};
    resta(A1, A2, TAM);                  //Llamada de la funcion resta, pasando A1, A2 y su tamano.


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



void resta(int M1[][TAM], int M2[][TAM], int F) //Funcion para restar dos arreglos 2D.
{
    int R[F][F];            //Arreglo Resultante.
    for (int i = 0; i<F; i++) //Itera por las filas.
    {
        for (int j = 0; j<F; j++) //Itera por las clumnas
        {
            R[i][j] = M1[i][j] - M2[i][j]; //Asigna valores a R mediante la resta de M1 y M2
        }
    }
    impresion(R, TAM); //Imprime el arreglo R por medio de la Funcion impresion.
}
