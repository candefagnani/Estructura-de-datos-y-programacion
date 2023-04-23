//42. Ingresar 10 números enteros y almacenarlos en el archivo enteros.dat, 
//y verificar que el archivo contiene (10*sizeof(int)) bytes.*
//44. Leer el archivo enteros.dat e informar la suma de los números positivos y negativos.
//47. Leer el Archivo enteros.dat y Ordenarlos y escribir un nuevo archivo enterosordenados.dat.

#include<stdio.h>
#include<stdlib.h>
#define Maximo 10

void ordenar(int vec[], int cantElementos);

void main()
{
	int Vec[Maximo],contador;
	int positivos = 0, negativos = 0;
	char archivo[]= "enteros.dat";
	FILE* ptr;
	FILE* txt;
	char archivo2[] = "enterosOrdenados.dat";
	ptr=fopen(archivo,"w+t");
	if(ptr==NULL)
	{
		puts("Error al abrir el archivo\n");
	}
	else
	{
		puts("El archivo se ha abierto correctamente");
		for(contador=0;contador<10;contador++)
		{
			printf("Ingrese un numero:\n");
			scanf("%i",&Vec[contador]);
		}
	}
	fwrite(Vec,sizeof(int),10,ptr);
	fclose(ptr);
	ptr=fopen(archivo,"r+t");
	if(ptr==NULL)
	{
		puts("Error al abrir el archivo\n");
	}
	else
	{
		puts("El archivo se ha abierto correctamente");
		fread(Vec,sizeof(int),10,ptr);
		for(contador=0;contador<10;contador++)
		{
			printf("El numero [%i]:%i\n", contador, Vec[contador]);
		}
		for(contador=0;contador<10;contador++)
		{
			if(Vec[contador] > 0)
			{
				positivos += Vec[contador];
			}
			else{
				negativos += Vec[contador];
			}
		}
		printf("La suma de los positivos es %i y la de los negativos %i\n",positivos,negativos);
	}
	ptr=fopen("enteros.dat","r");
  	fseek(ptr, 0L, SEEK_END);
  	printf("enteros.dat ocupa %li bytes\n", ftell(ptr));
	fclose(ptr);
	ptr=fopen("enteros.dat","r+t");
	txt = fopen(archivo2,"w+t");
	if (ptr == NULL)
		puts("El archivo no pudo ser abierto\n");
	else{
		puts("El archivo pudo ser abierto correctamente\n");
		ordenar(Vec[10],10);
		fwrite(Vec,sizeof(int),10,txt);
	}
	//a partir de aca hay un error --> con el ejercicio 47
	fclose(txt);
	txt=fopen(archivo2,"r+t");
	if(txt==NULL)
	{
		puts("Error al abrir el archivo\n");
	}
	else
	{
		puts("El archivo se ha abierto correctamente");
		for(contador=0;contador<10;contador++)
		{
			printf("El numero [%i]:%i\n", contador, Vec[contador]);
		}
		fwrite(Vec,sizeof(int),10,txt);
	}
	fclose(txt);
	txt=fopen(archivo2,"r");
  	fseek(txt, 0L, SEEK_END);
  	printf("enterosordenados.dat ocupa %li bytes\n", ftell(txt));
	fclose(txt);
	return;		
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
