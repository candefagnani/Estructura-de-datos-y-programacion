#include <stdio.h>
#include<stdlib.h>
#define FILAS 2
#define COLUMNAS 5

void cargarMatriz(float matriz[FILAS][COLUMNAS]);
void mostrarMatriz(float matriz[FILAS][COLUMNAS]);
void cambiar(float *a,float *b);
void ordenar(float vec[COLUMNAS]);
void ordenarFilas(float matriz[FILAS][COLUMNAS]);

int main(void)
{
    float matriz[2][5];
    cargarMatriz(matriz);
    ordenarFilas(matriz);
    printf("La matriz ordenada: \n");
    mostrarMatriz(matriz);
    return 0;
}

void cargarMatriz(float matriz[2][5])
{
    int i,j;
    for (i = 0;i < 2;i++)
    {
        for (j = 0; j < 5; j++) {
            printf("Ingrese el valor [%i][%i] de la matriz: ", i + 1, j + 1);
            scanf("%f", &matriz[i][j]);
        };
    }
}
void mostrarMatriz(float matriz[2][5])
{
    int i,j;
    for(i=0;i<2;i++)
    {
        for(j=0;j<5;j++)
        {
            printf("%.2f \t",matriz[i][j]);
        }
        printf("\n");
    }
}

void cambiar(float *a,float *b)
{
    float aux= *a;
    *a = *b;
    *b = aux;
}

void orden(float vec[COLUMNAS])
{
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=i+1;j<5;j++)
        {
           if(vec[i] > vec[j])
           {
               cambiar(vec+i,vec+j);
           }
        }
    }
}

void ordenarFilas(float matriz[FILAS][COLUMNAS])
{
    int i;
    for (i = 0; i < 2; i++)
        orden(matriz[i]);
}