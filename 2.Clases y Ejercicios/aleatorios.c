#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int randConNegativos(int tope)
{
	int num, signo;
	/*Genero el numero aleatorio*/
	num =(rand()% (tope+1));
	//Genero el signo. 0 positivo, 1 negativo
	signo = rand() % 2;
	/*Como el numero generado por rand es siempre positivo, si
    el numero generado para signo es 1, lo multiplico por -1 para generar un numero negativo.*/
	if (signo == 1)
		num = num * -1;
	return num;
}

int main()
{
	int i, numero;
	/*El uso de srand es para cambiar la semilla del rand y así obtener
    numeros que parezcan realmente aleatorios.*/
	srand(time(NULL));
	/*Genero un numero aleatorio y lo muestro por pantalla*/
	for (i=0; i< 10; i++)
	{
		numero = randConNegativos(10);
		printf("El numero elegido es %d\n", numero);
	}
	return 0;
}