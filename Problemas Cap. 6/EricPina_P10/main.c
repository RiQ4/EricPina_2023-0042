#include <stdio.h>

const int MES = 12;
const int DEP = 3;
const int YEAR = 1;

void Lectura(float [][DEP][YEAR], int, int, int);
void Funcion1(float [][DEP][YEAR], int, int, int);
void Funcion2(float [][DEP][YEAR], int, int, int);
void Funcion3(float [][DEP][YEAR], int, int, int);

void main(void) {
    float PRO[MES][DEP][YEAR];
    Lectura(PRO, MES, DEP, YEAR);
    Funcion1(PRO, MES, DEP, 2);
    Funcion2(PRO, MES, DEP, YEAR);
    Funcion3(PRO, MES, DEP, YEAR);
}

void Lectura(float A[][DEP][YEAR], int F, int C, int P) {
    int K, I, J;
    for (K = 0; K < P; K++) {
        for (I = 0; I < F; I++) {
            for (J = 0; J < C; J++) {
                printf("Ano: %d\tMes: %d\tDepartamento: %d: ", K + 1, I + 1, J + 1);
                scanf("%f", &A[I][J][K]);
            }
        }
    }
}

void Funcion1(float A[][DEP][YEAR], int F, int C, int P) {
    int I, J;
    float SUM = 0.0;
    for (I = 0; I < F; I++) {
        for (J = 0; J < C; J++) {
            SUM += A[I][J][P - 1];
        }
    }
    printf("\n\nVentas totales de la empresa en el segundo ano: %.2f", SUM);
}

void Funcion2(float A[][DEP][YEAR], int F, int C, int P) {
    int I, J;
    float SUM1 = 0, SUM2 = 0, SUM3 = 0;
    for (I = 0; I < F; I++) {
        for (J = 0; J < C; J++) {
            switch (J + 1) {
                case 1:
                    SUM1 += A[I][J][P - 1];
                    break;
                case 2:
                    SUM2 += A[I][J][P - 1];
                    break;
                case 3:
                    SUM3 += A[I][J][P - 1];
                    break;
            }
        }
    }
    if (SUM1 > SUM2) {
        if (SUM1 > SUM3) {
            printf("\n\nDepartamento con mayores ventas en el ultimo ano: Hilos");
            printf(" Ventas: %.2f", SUM1);
        } else {
            printf("\n\nDepartamento con mayores ventas en el ultimo ano: Licra");
            printf(" Ventas: %.2f", SUM3);
        }
    } else if (SUM2 > SUM3) {
        printf("\n\nDepartamento con mayores ventas en el ultimo ano: Lanas");
        printf(" Ventas: %.2f", SUM2);
    } else {
        printf("\n\nDepartamento con mayores ventas en el ultimo ano: Licra");
        printf(" Ventas: %.2f", SUM3);
    }
}
void Funcion3(float A[][DEP][YEAR], int F, int C, int P)
{
    int DE, ME, AN;
    float VEN = -1.0;

    for (AN = 0; AN < P; AN++)
    {
        for (ME = 0; ME < F; ME++)
        {
            for (DE = 0; DE < C; DE++)
            {
                if (A[ME][DE][AN] > VEN)
                {
                    VEN = A[ME][DE][AN];
                    ME = ME + 1;
                    DE = DE + 1;
                    AN = AN + 1;
                }
            }
        }
    }

    printf("\n\nDepartamento: %d\tMes: %d\tAno: %d", DE, ME, AN);
    printf("\tVentas: %.2f", VEN);
}

