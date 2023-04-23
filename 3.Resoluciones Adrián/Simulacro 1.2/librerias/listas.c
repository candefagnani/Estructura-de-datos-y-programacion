#include "listas.h"
#include <stdio.h>
#include <stdlib.h>
#include "string.h"

int agregarPrincipio(Lista * plst, dato d)
{
    Nodo * nvo;
    nvo = (Nodo *) malloc(sizeof(Nodo));
    if (!nvo) return 0;

    nvo->d = d;
    nvo->sig = * plst;
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

    act=ant=*plst;
    while( act != NULL )
    {
        //if(act->d.Numero ==d) return 0;
        if (esIgual(act->d,d) )return 0;

        //if (act->d.Numero<d)
        if (insertarAqui(act->d,d))
        {
            if(ant==act)
                return agregarPrincipio(plst,d);
            nvo=(Nodo*)malloc(sizeof(Nodo));
            if(!nvo)
                return 0;

            nvo->d=d;
            ant->sig=nvo;
            nvo->sig=act;
            return 1;
        }
        ant=act;
        act=act->sig;
    }
    return agregarFinal(plst,d);
}

int eliminar(Lista *plst,dato d)
{

    Nodo *ant,*act,*nvo;

    if(!*plst)
        return eliminarPrincipio(plst);

    act=ant=*plst;
    while( act != NULL )
    {
        //if(act->d.Numero ==d) return 0;
        if (esIgual(act->d,d) )
            return 0;


    }
    return eliminarFinal(plst);
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
}

int BuscarNodo(Lista *plst, int numABuscar)
{
    Nodo *aux;
    aux = *plst;
    int pos = 0, hit;
    while(aux != NULL)
    {
        if(aux->d.numeroVendedor == numABuscar)
        {
            hit = 1;
            break;
        }
        aux = aux->sig;
        pos++;
    }
    if (hit == 1)
        return pos;
    else
        return pos = -1;
}

#ifdef LISTAS_STRUCT
void mostrarElemento(dato unDato)
{
    printf("Num Empleado: %d - Comision: %.2f - Nombre: %s - Cant. productos vendidos: %d - Total vendido: %.2f\n",unDato.numeroVendedor, unDato.comisionVendedor, unDato.nombreVendedor, unDato.CantproductosVendidos, unDato.totalVendido);
}

int esIgual(dato datoLista,dato datoAInsertar)
{
    return (datoLista.numeroVendedor == datoAInsertar.numeroVendedor);
}

int insertarAqui(dato datoLista,dato datoAInsertar)
{
    return strcmp(datoLista.nombreVendedor, datoAInsertar.nombreVendedor)  > 0;
}

#endif



