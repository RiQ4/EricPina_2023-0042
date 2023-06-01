#include <stdio.h>


void main()
{
    int TRA, EDA, DIA;
    float COS;

    printf("\nCalculadora de Tratamiento:");
    printf("\nIngrese los valores de: ");
    printf("\nTratamiento: ");
    scanf("%d", &TRA);
    printf("\nEdad: ");
    scanf("%d", &EDA);
    printf("\nDias: ");
    scanf("%d", &DIA);

    switch (TRA) {
    case 1:
        COS = DIA * 2800;
        break;
    case 2:
        COS = DIA * 1950;
        break;
    case 3:
        COS = DIA * 2500;
        break;
    case 4:
        COS = DIA * 1150;
        break;
    default:
        COS = -1;
    }

    if (COS != -1) {
        if (EDA >= 60) {
            COS = COS * 0.75;
        }
        else if (EDA <= 25) {
            COS = COS * 0.85;
        }
        printf("\nTratamiento No. %d\nDias: %d\nCosto: %8.2f", TRA, DIA, COS);
    }
    else {
        printf("\nDatos Incorrectos.");
    }
}
