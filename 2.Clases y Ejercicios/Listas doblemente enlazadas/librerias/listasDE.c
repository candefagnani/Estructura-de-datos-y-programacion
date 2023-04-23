//LISTAS DOBLEMENTE ENLAZADAS
#include "listasDE.h"
#include <stdio.h>
#include <stdlib.h>
#include "string.h"

int agregarPrincipio(Lista * plst, dato d)
{
    Nodo * nvo;
    nvo = (Nodo *) malloc(sizeof(Nodo));
    if (!nvo) return 0;

    nvo->d = d;
    nvo->ant = NULL;
    nvo->sig = * plst;
    if (nvo->sig != NULL)
        nvo->sig->ant = nvo;
    *plst = nvo;

    return 1;
}

void mostrarLista(Lista plst)
{
    Lista aux;
    aux = plst;

    while (aux!=NULL)
    {
        mostrarElemento(aux->d);
        aux = aux->sig;
    }

}

void mostrarYVaciarLista(Lista plst)
{
    while (plst!=NULL)
    {
        mostrarElemento(plst->d);
        eliminarPrincipio(&plst);
    }
}

int agregarFinal(Lista * plst, dato d)
{
    Nodo * nvo, *aux;

    if (*plst == NULL)
        return agregarPrincipio(plst, d);

    nvo = (Nodo *) malloc(sizeof(Nodo));
    if (!nvo) return 0;

    nvo->d = d;
    nvo->sig = NULL;

    aux = *plst;
    while (aux->sig != NULL)
        aux = aux->sig;
    nvo->ant = aux;
    aux->sig = nvo;
    return 1;
}

int eliminarPrincipio(Lista * plst)
{
    //Tomo el nodo a ELIMINAR
    Nodo * aux = * plst;
    if (*plst == NULL)
        return 0;
    //Ahora la lista apunta al siguiente nodo del que se va a eliminar
    *plst = aux->sig;
    if((*plst) != NULL)
        (*plst)->ant = NULL;
    free(aux);
    return 1;
}

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


int insertar(Lista *plst,dato d)
{
    Nodo *ant,*act,*nvo;

    if(!*plst) return agregarPrincipio(plst,d);

    act = ant = *plst;
    while( act != NULL )
    {
        //if(act->d.Numero ==d) return 0;
        if (esIgual(act->d,d) )return 0;

        //if (act->d.Numero<d)
        if (insertarAqui(act->d,d))
        {
            if(ant == act) return agregarPrincipio(plst,d);
            nvo = (Nodo*)malloc(sizeof(Nodo));
            if(!nvo) return 0;
            nvo->d = d;
            nvo->ant = ant;
            nvo->sig = act;

            ant->sig = nvo;
            act->ant = nvo;
            return 1;
        }
        ant = act;
        act = act->sig;
    }
    return agregarFinal(plst,d);
}

int eliminar(Lista *plst,dato d)
{

    Nodo *ant,*act,*nvo;

    if(!*plst) return eliminarPrincipio(plst);

    act=ant=*plst;
    while( act != NULL )
    {
        //if(act->d.Numero ==d) return 0;
        if (esIgual(act->d,d) )return 0;


    }
    return eliminarFinal(plst);
};

void mostrarElemento(dato unDato)
{
    printf("-----Numero de cancion: %d\n", unDato.numero);
    printf("Autor: %s\n", unDato.autor);
    printf("Canción: %s\n", unDato.nombre);
}

int esIgual(dato datoLista,dato datoAInsertar)
{
    return (datoLista.numero == datoAInsertar.numero);
}


int insertarAqui(dato datoLista,dato datoAInsertar)
{
    return (datoLista.numero > datoAInsertar.numero);
}

int Siguiente(Lista *plst)
{
    if((*plst)->sig != NULL) //si esto es nulo quiere decir que estoy en el ult nodo
        *plst = (*plst)->sig;
    return 0;
}

int Anterior(Lista *plst)
{
    if((*plst)->ant != NULL) //si esto es nulo quiere decir que estoy en el primer nodo
        *plst = (*plst)->ant;
    return 0;
}





