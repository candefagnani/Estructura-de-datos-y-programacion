#include <stdio.h>
int main(void)
{
	FILE * ftxt;
	char linea[100];
	/*
		fopen recibe como parametro lo siguiente:
		1.nombre del archivo
		2.tipo de apertura del archivo que puede
		2.1 "r"ead para solo lectura
		2.2 "a"ppend para agregar contenido a un archivo EXISTENTE
		2.3 "w"rite para CREAR un archivo y poder escribir
	*/
	ftxt = fopen("C:\\Temp\\equipos.txt", "rt");
	if (ftxt != NULL)
	{
		printf("El archivo pudo ser abierto...\n");
		/*
			fgets me permite leer el contenido de TEXTO de un archivo
			de texto linea por linea. Deberia declarar una variable
			por EXCESO para poder guardar cualquier contenido que tenga
			la linea
		*/
		fgets(linea, 100, ftxt);
		/*
			feof (file end of file)
			Devuelve si estoy al final del archivo o no.
			Por lo tanto lo usamos para saber si queda algo para leer
			o no.
		*/
		while (!feof(ftxt))
		{
			printf("%s", linea);
			fgets(linea, 100, ftxt);
		}
		fclose(ftxt);
	}
	else
		printf("El archivo no se pudo abrir\n");
	getch();
	return 0;
}

#include <stdio.h>
int main(void)
{
	FILE * ftxt;
	char linea[100];
	/*
    	fopen recibe como parametro lo siguiente:
		1.nombre del archivo
		2.tipo de apertura del archivo que puede
		2.1 "r"ead para solo lectura
		2.2 "a"ppend para agregar contenido a un archivo EXISTENTE
		2.3 "w"rite para CREAR un archivo y poder escribir
	*/
	ftxt = fopen("C:\\Temp\\nuevo.txt", "wt");
	if (ftxt != NULL)
	{
		printf("El archivo pudo ser abierto...\n");
		printf("Ingrese una palabra:");
		fgets(linea, 100, stdin);
		while (linea[0] != '\n')
		{
			/*
				Si estoy aca adentro quiere decir que en la variable
				"linea" tengo un texto que quiero GUARDAR en el archivo
				nuevo.txt
				La funcion fprintf funciona IGUAL que el printf solo
				que primero se le dice en donde se quiere grabar lo que
				esta entre comillas
			*/
			fprintf(ftxt, "%s", linea);
			printf("Ingrese una palabra:");
			fgets(linea, 100, stdin);
		}
		fclose(ftxt);
	}
	else
		printf("El archivo no se pudo abrir\n");
	getch();
	return 0;
}



#include <stdio.h>
int main(void)
{
	FILE * ftxt;
	int numero, suma, cantidad;
	/*
		fopen recibe como parametro lo siguiente:
		1.nombre del archivo
		2.tipo de apertura del archivo que puede
		2.1 "r"ead para solo lectura
		2.2 "a"ppend para agregar contenido a un archivo EXISTENTE
		2.3 "w"rite para CREAR un archivo y poder escribir
	*/
	ftxt = fopen("C:\\Temp\\promedio.txt", "wt");
	if (ftxt != NULL)
	{
		printf("El archivo pudo ser abierto...\n");
		suma = 0;
		cantidad = 0;
		printf("Ingrese un numero:");
		scanf("%d", &numero);
		while (numero)
		{
			suma = suma + numero;
			cantidad++;
			fprintf(ftxt,"%d\n", numero);
			printf("Ingrese un numero:");
			scanf("%d", &numero);
		}
		fprintf(ftxt,"---------------------------\n");
		fprintf(ftxt,"Suma: %d\n", suma);
		fprintf(ftxt,"Promedio: %.2f\n", (float)suma/cantidad);
		fclose(ftxt);
	}
	else
		printf("El archivo no se pudo abrir\n");
	getch();
	return 0;
}

#include <stdio.h>
int main(void)
{
	FILE * ftxt;
	int c1, c2, c3, c4;
	/*
		fopen recibe como parametro lo siguiente:
		1.nombre del archivo
		2.tipo de apertura del archivo que puede
		2.1 "r"ead para solo lectura
		2.2 "a"ppend para agregar contenido a un archivo EXISTENTE
		2.3 "w"rite para CREAR un archivo y poder escribir
	*/
	ftxt = fopen("C:\\Temp\\matriz.txt", "rt");
	if (ftxt != NULL)
	{
		printf("El archivo pudo ser abierto...\n");
		fscanf(ftxt, "%d %d %d %d", &c1,&c2,&c3,&c4);
		while (!feof(ftxt))
		{
			printf("%d %d %d %d\n", c1, c2, c3, c4);
			fscanf(ftxt, "%d %d %d %d", &c1,&c2,&c3,&c4);
		}
    printf("%d %d %d %d\n", c1, c2, c3, c4);
		fclose(ftxt);
	}
	else
		printf("El archivo no se pudo abrir\n");
	getch();
	return 0;
}