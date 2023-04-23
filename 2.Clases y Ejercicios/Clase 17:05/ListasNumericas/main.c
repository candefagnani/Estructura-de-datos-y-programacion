#include <stdio.h>
#include <string.h>
#include "../librerias/pilas.h"

int main() {
    Pila plst = NULL;
    dato d1;
    dato d2;
    dato d3;
    dato d4;
    dato aux;

    d1.dni = 1;
    strcpy(d1.nombre, "Adrian");
    d2.dni = 2;
    strcpy(d2.nombre, "Maria");
    d3.dni = 3;
    strcpy(d3.nombre, "Fabiana");
    d4.dni = 4;
    strcpy(d4.nombre, "Zoolaner");


    apilar(&plst, d1);
    apilar(&plst, d2);
    apilar(&plst, d3);
    apilar(&plst, d4);

    while (!(plst == NULL)){
        desapilar(&plst, &aux);
        mostrarElemento(aux);
    }
    return 0;
}
