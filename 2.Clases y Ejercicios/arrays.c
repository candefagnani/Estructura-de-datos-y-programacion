#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define CANTIDAD 10
int main()
{
    int f, c, suma, promedio;
	int num[CANTIDAD][CANTIDAD];
	srand(time(NULL));
	//Cargo la matriz
	for (f=0; f<CANTIDAD; f++)
	{
		for (c=0; c<CANTIDAD; c++)
		{
			num[f][c] = rand() % 10000;
		}
	}
	//Muestro la matriz
	for (f=0; f<CANTIDAD; f++)
	{
		for (c=0; c<CANTIDAD; c++)
		{
			printf("%5d", num[f][c]);
		}
		printf("\n");
	}
	return 0;
}