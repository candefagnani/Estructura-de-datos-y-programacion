#include <stdio.h>
#include <stdlib.h>
#include "colas.h"

int agregarPrincipio(Cola * plst, dato unDato)
{
    Nodo * nvo;
    nvo = (Nodo *) malloc(sizeof(Nodo));
    if (!nvo)
        return 0;
    nvo->d = unDato;
    nvo->sig = * plst;
    *plst = nvo;

    return 1;
};

int agregar(Cola * plst, dato unDato)
{
    Nodo * nvo, *aux;
    if (*plst == NULL)
        return agregarPrincipio(plst, unDato);

    nvo = (Nodo*) malloc(sizeof(Nodo));
    if (!nvo) return 0;
    nvo->d = unDato;
    nvo->sig = NULL;
    aux = *plst;
    while (aux->sig != NULL)
        aux = aux->sig;
    aux->sig = nvo;
    return 1;
};

int eliminarPrincipio(Cola * plst)
{
    //Tomo el nodo a ELIMINAR
    Nodo * aux = * plst;
    if (*plst == NULL)
        return 0;
    //Ahora la lista apunta al siguiente nodo del que se va a eliminar
    *plst = aux->sig;
    free(aux);
};

int sacar(Cola * pcola, dato * d)
{
    if (*pcola == NULL)
        return 0;
    *d = (*pcola)->d;
    return eliminarPrincipio(pcola);
}