#include <stdio.h>

void main()
{
    float COS;
    int CLA, TIME;
    printf("\nIngrese la CLAVE y TIEMPO: \nCLAVE: ");
    scanf("%d", &CLA);
    printf("\nTIEMPO: ");
    scanf("%d", &TIME);

    switch(CLA) {
        case 1:
            COS = TIME * 0.13/60;
            break;
        case 2:
            COS = TIME * 0.11/60;
            break;
        case 5:
            COS = TIME * 0.22/60;
            break;
        case 6:
            COS = TIME * 0.19/60;
            break;
        case 7:
        case 9:
            COS = TIME * 0.17/60;
            break;
        case 10:
            COS = TIME * 0.20/60;
            break;
        case 15:
            COS = TIME * 0.39/60;
            break;
        case 20:
            COS = TIME * 0.28/60;
        default:
            COS = -1;
    }
    if (COS != -1) {
        printf("\nLos valores son:\nClave: %d\nTiempo: %d\nCOS: %6.2f", CLA, TIME, COS);
    }
    else {
        printf("\nError de clave.");
    }
}
