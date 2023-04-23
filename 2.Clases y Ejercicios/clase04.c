#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define CANT_ELEMENTOS 10

//Zona de prototipos
void ordenar(int [],int);
int busquedaBinaria(int [], int, int);

//Main
int main(void)
{
	int v[CANT_ELEMENTOS];
	int i, vab;
    srand(time(NULL));
	for (i=0; i<CANT_ELEMENTOS;i++)
		v[i]=rand();
	printf("Vector original:\n");
	for (i=0; i<CANT_ELEMENTOS;i++)
		printf("%d ", v[i]);
	printf("\n");
	printf("Ordeno...\n");
	ordenar(v, CANT_ELEMENTOS);
	printf("Vector resultante:\n");
	for (i=0; i<CANT_ELEMENTOS;i++)
		printf("%d ", v[i]);
	printf("\n");
	printf("Ingrese el valor a buscar:");
	scanf("%d", &vab);
	printf("El valor se encuentra en la posicion %d\n",
				busquedaBinaria(v, CANT_ELEMENTOS, vab));
	return 0;
}

void ordenar(int vec[],int cantElementos)
{
    int j, i = 0;
    int aux;
    for (j = 1; j < cantElementos; j++)
    {
        for (i = 0; i < cantElementos-j; j++)
        {
            if (vec[i] > vec[i+1])
            {
                aux = vec[i];
                vec[i] = vec[i+1];
                vec[i+1] = aux;
            }
        }
    }
    return;
}

int busquedaBinaria(int vec[], int cantElementos, int valorABuscar)
{
	int posIni, posFin, medio;
	posIni = 0;
	posFin = cantElementos - 1;
	medio = (posIni + posFin) / 2;
	while (vec[medio] != valorABuscar && posIni <= posFin)
	{
		if (vec[medio] < valorABuscar)
			posIni = medio + 1;
		else
			posFin = medio -1;
		medio = (posIni + posFin) / 2;
	}
	if (posIni <= posFin)
		return medio;
	else
		return -1;
}

