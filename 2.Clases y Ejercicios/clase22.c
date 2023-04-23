#include <stdio.h>
#include <stdlib.h>

void mifgets(char * cad, int lon);
void SacarEnters(char * cad);

int main(void)
{
	char frase[10];
	printf("Ingrese una frase:");

	/* Si uso el scanf solamente puedo ingresar de a una palabra
	scanf("%s", frase);*/

	/* Puedo usar la funcion pero OJO que no controla la longitud de la
	variable que esta escribiendo.
	gets(frase);*/

	/* Esta funcion controla la longitud PERO deja los enters adentro
	si es que lo ingresado es MENOR que lo esperado.
	fgets(frase, 10, stdin);*/
	mifgets(frase, 10);
	printf("La frase ingresada es %s\n.Chau", frase);
	return 0;
}



void mifgets(char * cad, int lon)
{
	int i;
	fgets( cad, lon, stdin);
	for (i=0; i<lon; i++)
	{
		if (cad[i] == '\n')
			cad[i] = '\0';
	}
	return;
}

void SacarEnters(char *cad)
{
    while(*cad) //lo que pregunto es si estoy o no APUNTANDO al caracter nulo
    {
        if(*cad == '\n')
            *cad = 0;
        else
            *cad++;
    }
}