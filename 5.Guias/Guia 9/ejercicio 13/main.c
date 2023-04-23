#include <stdio.h>
#include "librerias/pilas.h"
#include "string.h"

//13. Realizar con una PILA el Control de la Coherencia de Paréntesis de una Instrucción
//matemática: Todos los q se abran deben cerrarse:
//a) Cada vez que encontremos un “(“ se añade a la pila
//b) Cada vez que encontremos un “)” se extraerá el “(“ de arriba de la pila
//c) La expresión con paréntesis es correcta si la pila está vacía al acabar la expresión
int main(void)
{
    Pila pila = NULL;
    char cuentaMatematica[50];
    int verdad, longitud;
    printf("Ingrese la cuenta matemática, recuerde que todos los parentesis que se abran se deben cerrar\n");
    fflush(stdin);
    gets(cuentaMatematica);
    longitud = strlen(cuentaMatematica);
    printf("Su expresion %s\n",cuentaMatematica);
    verdad = Verificacion(pila,cuentaMatematica,longitud);
    if (verdad == 0)
        printf("La expresion es correcta\n");
    else
        printf("La expresion es incorrecta\n");
    return 0;
}
