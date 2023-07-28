#include <stdio.h>
#include <stdlib.h>
#define TAM 3
void transM(int M[][TAM], int S);
void impresion(int M[][TAM], int F);

void main(void)
{
    int A1[TAM][TAM] = {{3, 5, 5}, {3, 7, 8}, {6, 8, 10}};
    printf("\nMatriz a transponer:\n");
    impresion(A1, TAM);
    transM(A1, TAM);
}

void transM(int M[][TAM], int S)
{
    int i, j;
    int C[S][S];
    for(i=0; i<S; i++)
    {
        for(j=0; j<S; j++)
        {
            C[j][i] = M[i][j];
        }
    }
    printf("\nMatriz transpuesta:\n");
    impresion(C, S);
}

void impresion(int M[][TAM], int F) //Funcion para imprimir arreglos 2D.
{
    for (int i = 0; i<F; i++) //Itera por las filas del arreglo
    {
        for (int j = 0; j<F; j++) //Itera por las columnas del arreglo
        {
            printf("%d ", M[i][j]);

        }
        printf("\n");
    }
}
