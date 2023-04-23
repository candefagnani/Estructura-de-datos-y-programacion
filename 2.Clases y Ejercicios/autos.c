#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	int i, dia, cantAutos;
	/*El uso de srand es para cambiar la semilla del rand y así obtener 
    numeros que parezcan realmente aleatorios.*/
	srand(time(NULL));
	printf("Salgo de casa y camino diez pasos hacia la derecha");
	/*Para realizar los 10 pasos voy a repetir realizar UN PASO, diez veces. Para eso, uso un ciclo FOR formato:
	for (condicion incial; condicion final; post ejecucion)*/
	for (i=0; i<10; i++)
		printf("\n paso");
	/*Genero un dia aleatorio siendo:
		0 lunes
		1 martes ..
		6 domingo*/
	dia = rand() % 7;
	printf("\nEl dia generado es %d\n", dia);
	//Si el dia es LUN, MIE o VIE
	if (dia==0 || dia == 2 || dia == 4)
		printf("\nDoblo a la derecha para ir al subte\n");
	else
	{
		printf("\nDoblo a la izquierda para ir al club pero espero en la esquina a que no vengan autos");
		cantAutos = rand() % 5;
		while (cantAutos > 0)
		{
			printf("\nEspero porque hay autos %d autos...", cantAutos);
			cantAutos = rand() % 5;
		}
		printf("Cruzo la calle...");
	}
	return 0;

}