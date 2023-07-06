#include <stdio.h>
#include <stdlib.h>
#define tirePerf 45000 //Km
#define anualKm 15000 //Km
#define oilChKm 25000 //Km
#define maxArrSize 50 //Elementos Maximos del Arreglo
float gComb(float D, int e, float fl);
float vCost(float D, float tireCost, float ensCost, float oilCost);
void getInfo();
void printHeader();
void printData(int S, int E);
void saveFile(int X, int E);

struct tabla
{
    char nombre[20];
    float distance;
    float gFuel[maxArrSize];
    float gVar;
};
struct tabla tabla0;
float dist;

void main()
{
    int eMax, eMin;
    float comb, tireC, ensC, oilChange;
    int arrSize;
    int con = 1;

    printf("\nCalculo de costo por visita.");
    printf("\nIngrese los siguientes datos.\n");
    printf("\nPrecio del Combustible (RD$xGal): ");
    scanf("%f", &comb);
    printf("\nEficiencia Maxima del Vehiculo (L/100km): ");
    scanf("%d", &eMax);
    printf("\nEficiencia Minima del Vehiculo (L/100km): ");
    scanf("%d", &eMin);
    printf("\nPrecio de la llantas (RD$xUnidad): ");
    scanf("%f", &tireC);
    printf("\nCosto del Seguro Anual (RD$): ");
    scanf("%f", &ensC);
    printf("\nCosto de Cambio de Aceite (RD$): ");
    scanf("%f", &oilChange);

    arrSize = (eMin-eMax)+1;
    getInfo();

    if (eMax<eMin)
    {

        for (int i = eMax; i<=eMin; i++) //Calculo de combustible iterado
        {
            //printf("\nValue i: %d", i);
            int arrPos = i - eMax;
            //printf("\narrPos: %d", arrPos);
            tabla0.gFuel[arrPos] = gComb(dist, i, comb);
            //printf("\t%5.2f", tabla0.gFuel[arrPos]);    //Test Print
        }
    }
    else
    {
        printf("\nEficiencia Minima no puede ser menor que Eficiencia Maxima");
        return;
    }
    tabla0.gVar = vCost(dist, tireC, ensC, oilChange);

    printHeader();
    printData(arrSize, eMax);
}

void getInfo()
{
    char name[20];

    printf("\nNombre del cliente: ");
    fflush(stdin);
    gets(name);
    strcpy(tabla0.nombre, name);
    fflush(stdin);
    printf("\nDistancia a recorrer (Km): ");
    scanf("%f", &dist);
    tabla0.distance = dist;

}

float gComb(float D, int e, float fl)
{
    float newCombPrice = fl/3.79;
    float finalComb = (newCombPrice*e*D)/100;
    return finalComb;
}

float vCost(float D, float tireCost, float ensCost, float oilCost)
{
    //Costo Llanta
    float totalTireC = 4*tireCost;
    float tirePerKM = totalTireC/tirePerf;

    //Seguro
    float ensPerKm = ensCost/anualKm;

    //Aceite
    float oilCostPerKm = oilCost/oilChKm;

    return tirePerKM+ensPerKm+oilCostPerKm;
}

void printHeader()
{
    printf("\nCliente ---> %s", tabla0.nombre);
    printf("\n---------------------------------------------------------------------------------");
    printf("\n| Distancia\t | Eficiencia\t | Gastos Var.\t | Gastos Comb.\t | Total\t|");
    printf("\n---------------------------------------------------------------------------------");
}

void printData(int S, int E)
{
    for(int i = 0; i<S; i++)
    {
        printf("\n| %5.2f    \t |  %d    \t |   %5.2f    \t | %5.2f  \t | %5.2f\t|", tabla0.distance, E+i, tabla0.gVar, tabla0.gFuel[i], tabla0.gVar+tabla0.gFuel[i]);
        printf("\n---------------------------------------------------------------------------------");
        saveFile(i, E+i);
    }
    printf("\n\nSe ha guardado el archivo con exito.\n");
}

void saveFile(int X, int E)
{
    FILE *data;
    data = fopen("tabla.txt", "a");

    if (data != NULL)
    {
        fprintf(data, "\n| %5.2f    \t |  %d    \t |   %5.2f    \t | %5.2f  \t | %5.2f\t|", tabla0.distance, E, tabla0.gVar, tabla0.gFuel[X], tabla0.gVar+tabla0.gFuel[X]);
        //fprintf(data, "\n%5.2f, %d ,%5.2f, %5.2f, %5.2f", tabla0.distance, E, tabla0.gVar, tabla0.gFuel[X], tabla0.gVar+tabla0.gFuel[X]);
        fclose(data);
    }
    else
    {
        printf("\nError al abrir el archivo.");
        return;
    }
}
