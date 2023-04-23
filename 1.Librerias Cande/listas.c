#include <stdio.h>
#include <stdlib.h>
#include "listas.h"

int agregarPrincipio(Lista * plst, dato unDato)
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

void mostrarLista(Lista plst)
{
    Lista aux;
    aux = plst;
    while (aux != NULL)
    {
        printf("%d\n", aux->d.numero);
        aux = aux->sig;
    }
};

int agregarFinal(Lista * plst, dato unDato)
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

int eliminarPrincipio(Lista * plst)
{
    //Tomo el nodo a ELIMINAR
    Nodo * aux = * plst;
    if (*plst == NULL)
        return 0;
    //Ahora la lista apunta al siguiente nodo del que se va a eliminar
    *plst = aux->sig;
    free(aux);
};

void mostrarYVaciarLista(Lista plst)
{
    while (plst!=NULL)
    {
        printf("%d\n", plst->d.numero);
        eliminarPrincipio(&plst);
    }
};

int eliminarFinal(Lista * plst)
{
    //Tomo el nodo a ELIMINAR
    Nodo * ant;
    Nodo * aux = * plst;
    if (*plst == NULL)
        return 0;
    //Ahora la lista apunta al siguiente nodo del que se va a eliminar
    aux = *plst;
    while (aux->sig != NULL)
    {
        ant = aux;
        aux = aux->sig;
    }
    ant->sig=NULL;
    free(aux);
};

void producto(Lista plst)
{
    int producto = 1;
    Lista aux;
    aux = plst;
    while(aux != NULL)
    {
        producto *= (aux->d.numero);
        aux = aux->sig;
    }
    printf("El producto es %d\n",producto);
};

int leeElementos(Lista plst)
{
    int elementos = 0;
    Lista aux;
    aux = plst;
    while(aux != NULL)
    {
        elementos++;
        aux = aux->sig;
    }
    return elementos;
};

void EliminarNodo(Lista *plst, int numAEliminar)
{
    Nodo *aux;
    Nodo *prev;
    aux = *plst;
    if(aux != NULL && aux->d.numero == numAEliminar)
    {
        *plst = aux->sig;
        free(aux);
        return;   
    }
    while(aux != NULL && aux->d.numero != numAEliminar)
    {
        prev = aux;
        aux = aux->sig;
    }
    if (aux == NULL)
        return;
    prev->sig = aux->sig;
    free(aux);
};

int buscaMaximo(Lista plst)
{
    Lista aux;
    int max;
    aux = plst;
    max = aux->d.numero;
    while(aux != NULL)
    {
        if((aux->d.numero) > max)
            max = aux->d.numero;
        aux = aux->sig;
    }
    return max;
};

int BuscarNodo(Lista *plst, int numABuscar)
{
    Nodo *aux;
    aux = *plst;
    while(aux != NULL)
    {
        if(aux->d.numero == numABuscar)
            return 1;
        aux = aux->sig;
    }
    return 0;
};