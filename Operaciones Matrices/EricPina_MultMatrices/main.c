#include <stdio.h>
#include <stdlib.h>
#define TAM 3
void impresion(int M[][TAM], int F);

void multM(int M1[][TAM], int M2[][TAM], int N);

void main(void)
{
    int A1[TAM][TAM] = {{3, 5, 5}, {3, 7, 8}, {6, 8, 10}};

    int A2[TAM][TAM] = {{2, 4, 5}, {3, 7, 8}, {4, 8, 9}};

    multM(A1, A2, TAM);
}

void multM(int M1[][TAM], int M2[][TAM], int N)
{
    int i, j, k; //Variables de los bucles.
    int R[N][N]; //Arreglo resultante

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) { //Iteraciones.
            R[i][j] = 0;          //Todo R es igualado a 0
            for (k = 0; k < N; k++) {   //Por como se da la multiplicacion de matrices, se crea otro bucle para iterar las filas y columnas de respectivos arreglos.
                R[i][j] += M1[i][k] * M2[k][j];
            }
        }
    }
    impresion(R, N);
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
