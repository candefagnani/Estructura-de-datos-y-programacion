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

    if(!*plst)
        return agregarPrincipio(plst,d);

    act = ant = *plst;
    while( act != NULL )
    {
        //if(act->d.Numero ==d) return 0;
        if (esIgual(act->d,d) )
            return 0;

        //if (act->d.Numero<d)
        if (insertarAqui(act->d,d))
        {
            if(ant == act)
                return agregarPrincipio(plst,d);
            nvo = (Nodo*)malloc(sizeof(Nodo));
            if(!nvo)
                return 0;
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
    Nodo *ant,*act;
    act = ant = *plst;
    while( act != NULL )
    {
        if (esIgual(act->d,d))
        {
            if(act->ant != NULL && act->sig != NULL)
            {
                ant->sig = act->sig;
                act->sig->ant = act->ant;
                /*
                * a b c
                * sig a -> c
                * ant c -> a
                */
            }
            if(act->sig == NULL)
                eliminarFinal(plst);
            if(act->ant == NULL)
                eliminarPrincipio(plst);
        }
        act = act->sig;
    }
}

void mostrarElemento(dato unDato)
{
    //printf("-----Numero de cancion: %d\n", unDato.numero);
    printf("%s\t", unDato.string);
    //printf("Canción: %s\n", unDato.nombre);
}

int esIgual(dato datoLista,dato datoAInsertar)
{
    return strcmp(datoLista.string,datoAInsertar.string) == 0;
}

int insertarAqui(dato datoLista,dato datoAInsertar)
{
    return strcmp(datoLista.string,datoAInsertar.string) > 0;
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
}

int BuscarNodo(Lista *plst, char *StringABuscar)
{
    Nodo *aux;
    aux = *plst;
    dato nuevo;
    strcpy(nuevo.string, StringABuscar);
    while(aux != NULL)
    {
        if(esIgual(aux->d, nuevo))
            return 1;
        aux = aux->sig;
    }
    return 0;
};

void mayusculas(char cadena[])
{
    int i;
    for (i = 0; i < longitud(cadena); i++)
    {
        if (cadena[i] >= 'a' && cadena[i] <= 'z')
            cadena[i] -= 32;
    }
    printf("cadena en mayusculas: %s\n",cadena);
}

void minusculas(char cadena[])
{
    int i;
    for (i = 0; i < longitud(cadena); i++)
    {
        if (cadena[i]>='A' && cadena[i]<='Z')
            cadena[i] = cadena[i] + 32;
    }
    printf("cadena en minusculas: %s\n",cadena);
}

int longitud(char cad[])
{
    int cant = 0;
    while(cad[cant])
        cant++;
    return cant;
}