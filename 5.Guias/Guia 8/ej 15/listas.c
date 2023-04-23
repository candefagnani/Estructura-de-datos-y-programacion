#include <stdio.h>
#include <stdlib.h>
#include "listas.h"

Lista creaNodo(int numero)
{
    Nodo *nuevo = malloc(sizeof(Nodo));
    nuevo->num.numero = numero;
    nuevo->sig=NULL;
    return nuevo;
}

void agregaPrincipio(Lista *pcabeza,Lista agregado)
{
    agregado->sig=*pcabeza;
    *pcabeza=agregado;
    return;
};

void mostrarLista(Lista plst)
{
    Lista aux;
    aux = plst;
    while (aux != NULL)
    {
        printf("%d\n", aux->num.numero);
        aux = aux->sig;
    }
};

void agregaFinal(Lista *pcabeza, Lista agregado)
{
    if (*pcabeza==NULL)
    {
        *pcabeza=agregado;
        return;
    }
    else
    {
        Nodo *temporario = *pcabeza;
        while (temporario->sig!=NULL)
            temporario=temporario->sig;
        temporario->sig=agregado;
        return;
    }

}

int eliminarPrincipio(Lista * plst)
{
    //Tomo el nodo a ELIMINAR
    Nodo * aux = * plst;
    if (*plst == NULL)
        return 0;
    //Ahora la lista apunta al siguiente nodo del que se va a eliminar
    *plst = aux->sig;
    free(aux);
    return 0;
}

void mostrarYVaciarLista(Lista plst)
{
    while (plst!=NULL)
    {
        printf("%d\n", plst->num.numero);
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
    return 0;
}

void producto(Lista plst)
{
    int producto = 1;
    Lista aux;
    aux = plst;
    while(aux != NULL)
    {
        producto *= (aux->num.numero);
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
    if(aux != NULL && aux->num.numero == numAEliminar)
    {
        *plst = aux->sig;
        free(aux);
        return;   
    }
    while(aux != NULL && aux->num.numero != numAEliminar)
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
    max = aux->num.numero;
    while(aux != NULL)
    {
        if((aux->num.numero) > max)
            max = aux->num.numero;
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
        if(aux->num.numero == numABuscar)
            return 1;
        aux = aux->sig;
    }
    return 0;
};
