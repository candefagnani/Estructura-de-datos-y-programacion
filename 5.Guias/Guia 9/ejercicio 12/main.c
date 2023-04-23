#include <stdio.h>
#include "string.h"
#include "librerias/pilas.h"

//Escriba una función que reciba un string y devuelve el string invertido utilizando una Pila
int main(void)
{
    Pila pila = NULL;
    char cadena[50];
    int longitud;
    printf("Ingrese el string: ");
    fflush(stdin);
    gets(cadena);
    longitud = strlen(cadena);
    //printf("%d\n",longitud);
    printf("Cadena normal: %s\n",cadena);
    printf("Cadena al revéz\n");
    CadenaAlRevez(pila,cadena,longitud);

    return 0;
}
