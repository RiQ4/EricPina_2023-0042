#include <stdio.h>
#include <stdlib.h>
#define TAM 3 //tamano del arreglo bidimensional cuadrado.

void sumaD(int M[][TAM], int S);

void main(void)
{

    int Val[TAM][TAM] = {{1, 2, 9},
                         {2, 3, 4},
                         {4, 5, 6}};

    sumaD(Val, TAM);
}

void sumaD(int M[][TAM], int S){
    int R = 0;
    for (int i = 0; i<S; i++)
    {
        for (int j = 0; j<S; j++)
        {
            if (i+j==S-1)
            {
                R += M[i][j];
            }
        }
    }
    printf("\nValor de suma: %d", R);

}
