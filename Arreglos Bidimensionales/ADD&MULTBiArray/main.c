#include <stdio.h>
const int TAM = 3;

void impresion(int M[][TAM], int F);
void valores(int M[][TAM], int F);
void OP(int M[][TAM], int F);

void main(void)
{

    int M1[TAM][TAM];
    valores(M1, TAM);
    OP(M1, TAM);

}

void valores(int M[][TAM], int F)
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

/* void impresion(int M[][TAM], int F)
{
    for (int i = 0; i<F; i++)
    {
        for (int j = 0; j<TAM; j++)
        {
            printf("\nResultado Posicion %d %d: %d ", i, j, M[i][j]);

        }
    }
}
*/

void impresionUNI(int M[], int F)
{
    for (int i = 0; i<F; i++)
    {
         printf("\nResultado Posicion %d: %d ", i, M[i]);
    }
}

void OP(int M[][TAM], int F)
{
    int r;
    int m;
    for (int i = 0; i<F; i++){
            r = 0;
            m = 1;
        for (int j = 0; j<F; j++){
          r += M[j][i];
          printf("\nr = %d", r);
          m *= M[i][j];
          printf("\nm = %d", m);
        }
        printf("\nValor de la suma de la columna %d: %d", i, r);
        printf("\nValor de la mult. de la fila %d: %d", i, m);

    }
    //impresionUNI(PreR, TAM);
}
