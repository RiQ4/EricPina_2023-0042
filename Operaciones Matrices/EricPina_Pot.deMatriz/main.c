#include <stdio.h>
#include <stdlib.h>
#define TAM 3       //Tamano del arreglo.

void pot(int M[][TAM], int S); //Prototipo de la funcion mult. por escalar. Toma al arreglo y su tamano como argumentos.
void impresion(int M[][TAM], int F); //Prototipo Funcion impresion.

void main(void) //Funcion main() donde se declaran los arreglos a ser operados. Se llama la funcion resta.
{
    int A1[TAM][TAM] = {{5, 10, 15},  //Valores del Arreglo 1.
        {20, 25, 30},
        {35, 40, 45}
    };
    pot(A1, TAM);
}

void pot(int M[][TAM], int S)
{
    int Ex = 0; //Exponente.
    int R[S][S];
    printf("\nIndique la potencia deseada: ");
    scanf("%d", &Ex);

    for (int i = 0; i<S; i++)   //Se guarda el arreglo dentro de otro para facilitar la operacion.
    {
        for (int j = 0; j<S; j++)
        {
            R[i][j] = M[i][j];  //Se guarda al arreglo original en R
        }
    }
    if (Ex==0)      //Se verifica si el exponente es 0
    {
        for (int i = 0; i<S; i++)
        {
            for (int j = 0; j<S; j++)
            {
            R[i][j] = 1;    //Si es verdadero, toda la maatriz sera igualada a 1
            }
        }
    }
    else
    {
        for (int i = 0; i<S; i++)   //Se itera por toda la matriz.
        {
            for (int j = 0; j<S; j++)
            {
                for (int n = 1; n<Ex; n++)  //Se multiplica el numero en R por el numero original en M la cantidad de veces dictada por el exponente.
                {
                R[i][j] *= M[i][j];
                }
            }
        }
    impresion(R, S); //Se imprime el resultado.
    }
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


