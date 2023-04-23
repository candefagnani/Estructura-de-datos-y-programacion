#include <stdio.h>
#include <stdlib.h>
#include "colas.h"
#include "listas.h"

int ingresar(Cola * pcola, dato d)
{
    return agregarFinal(pcola, d);
};

int sacar(Cola * pcola, dato * d)
{
    if (*pcola == NULL)
        return 0;
    *d = (*pcola)->d;
    return eliminarPrincipio(pcola);
};

void sumaColas(Cola cola1, Cola cola2, Cola *colaSuma)
{
    dato suma;
    dato dato1;
    dato dato2;
    while(cola1 != NULL)
    {
        sacar(&cola1, &dato1);
        sacar(&cola2, &dato2);
        suma.dni = dato1.dni + dato2.dni;
        agregar(colaSuma,suma);
    }
    while (sacar(colaSuma, &suma))
    {
        printf("%d\n", suma.dni);
    }
    printf("Se terminaron los datos de la cola\n");
};