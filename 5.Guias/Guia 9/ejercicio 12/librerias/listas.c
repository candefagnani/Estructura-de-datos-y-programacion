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

/*
int insertar(Lista *plst,dato d)
{
    Nodo *ant,*act,*nvo;

    if(!*plst) return agregarPrincipio(plst,d);

    act=ant=*plst;
    while( act != NULL )
    {
        //if(act->d.Numero ==d) return 0;
        if (esIgual(act->d,d) )return 0;

        //if (act->d.Numero<d)
        if (insertarAqui(act->d,d))
        {
            if(ant==act) return agregarPrincipio(plst,d);
            nvo=(Nodo*)malloc(sizeof(Nodo));
            if(!nvo) return 0;
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

    if(!*plst) return eliminarPrincipio(plst);

    act=ant=*plst;
    while( act != NULL )
    {
        //if(act->d.Numero ==d) return 0;
        if (esIgual(act->d,d) )return 0;


    }
    return eliminarFinal(plst);
};
*/

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


#ifdef LISTAS_NUMERICAS
void mostrarElemento(dato unDato)
{
    printf("%d\n", unDato);
};

int esIgual(dato datoLista,dato datoAInsertar)
{
    return (datoLista==datoAInsertar);
};
int insertarAqui(dato datoLista,dato datoAInsertar)
{
    return datoLista > datoAInsertar;
};

/*
void producto(Lista plst)
{
    int producto = 1;
    Lista aux;
    aux = plst;
    while(aux != NULL)
    {
        producto *= (aux->d);
        aux = aux->sig;
    }
    printf("El producto es %d\n",producto);
};

void EliminarNodo(Lista *plst, int numAEliminar)
{
    Nodo *aux;
    Nodo *prev;
    aux = *plst;
    if(aux != NULL && aux->d == numAEliminar)
    {
        *plst = aux->sig;
        free(aux);
        return;
    }
    while(aux != NULL && aux->d != numAEliminar)
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
    max = aux->d;
    while(aux != NULL)
    {
        if((aux->d) > max)
            max = aux->d;
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
        if(aux->d == numABuscar)
            return 1;
        aux = aux->sig;
    }
    return 0;
};
 */
#endif

#ifdef LISTAS_STRUCT
void mostrarElemento(dato unDato)
{
    //printf("DNI %d\n", unDato.dni);
    printf("%c\n", unDato.palabra);
}
/*
int esIgual(dato datoLista,dato datoAInsertar)
{
    return (datoLista.dni == datoAInsertar.dni);
}
Inserto repetidos
int esIgual(dato datoLista, datoAInsertar){
    return 0;
}*/

int insertarAqui(dato datoLista,dato datoAInsertar)
{
    return strcmp(datoLista.palabra, datoAInsertar.palabra)  > 0;
}
#endif

#ifdef LISTAS_CHAR
void mostrarElemento(dato unDato)
{
    printf("%c\t", unDato);
}
int insertarAqui(dato datoLista,dato datoAInsertar)
{
    return (datoLista > datoAInsertar);
}
#endif

