#include <stdio.h>

void main (void)
{
    char cad[50];
    int res;
    FILE *ar;

    if((ar = fopen("arc.txt", "w")) != NULL)
    {
        printf("\nDesea ingresar texto? 1- Si 0- No: " );
        scanf("%d", &res);
        while (res)
        {
            fflush(stdin);
            printf("\nIngrese el texto: ");
            gets(cad);
            fputs(cad, ar);

            printf("Quiere escribir nuevamente? 1- Si 0- No: ");
            scanf("%d", &res);
            if (res)
            {
                fputs("\n", ar);
            }
        }
        fclose(ar);
    }
    else
    {
        printf("No se pudo abrir el archivo.");
    }

}

