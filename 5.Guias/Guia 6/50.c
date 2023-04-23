#include <stdio.h>
#include <stdlib.h>
/*50. Pedir al Usuario la Extensión “n” del vector. Dimensionarlo, ingresar al vector los
“n” números e informar el promedio. Luego, pedir un valor “m”, redimensionar,
agregar los elementos que faltan y recalcular el promedio.*/
int main(void)
{
	int i = 0, cantNumeros = 0, num;
	int *vector;
	printf("Ingrese la cantidad de numeros que desea que tenga su vector: ");
	scanf("%i", &cantNumeros);
	while(cantNumeros < 0)
	{
    		printf("Ingrese la cantidad de numeros que desea que tenga su vector: ");
    		scanf("%i", &cantNumeros);
	}
	vector = (int *) malloc(cantNumeros * sizeof(int));
	for (i = 0; i < cantNumeros; i++)
	{   
    		scanf("%i",&num);
    		vector[i] = num;
	}
	for (i = 0; i < cantNumeros; i++)
    		printf("%i ",vector[i]);
    printf("\n");
	free(vector);
    return 0;
}
