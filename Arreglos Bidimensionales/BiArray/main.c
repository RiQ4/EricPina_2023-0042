#include <stdio.h>
#include <stdlib.h>
const int TAM = 3;

void valores(int matriz[][TAM], int F); //Pide los valores de la matriz
void impresion(int matriz[][TAM], int F);


void main(void)
{

    // int matriz[TAM][TAM];
    int A1[3][3] = {2, 5, 6,
                        3, 6, 9,
                        4, 7, 10};


    impresion(A1, TAM);



}

/*void valores(int M[][TAM], int F)
{
    for (int i = 0; i<F; i++)
    {
        for (int j = 0; j<F; j++)
        {
            printf("\nIngrese los valores para la posicion %d, %d: ", i+1, j+1);
            scanf("%d", &M[i][j]);
        }
    }
}
*/

void impresion(int M[][TAM], int F)
{
    for (int i = 0; i<F; i++)
    {
        for (int j = 0; j<TAM; j++)
        {
                printf("\nResultado Posicion %d %d: %d ", i, j, M[i][j]);

        }
    }
}


/*
void suma(int M1[][TAM], int M2[][TAM], int F) {
    int R[F][F];
    for (int i = 0; i<F; i++){
        for (int j = 0; j<F; j++){
           R[i][j] = M1[i][j] + M2[i][j];
        }
    }
    impresion(R, TAM);
}
*/
