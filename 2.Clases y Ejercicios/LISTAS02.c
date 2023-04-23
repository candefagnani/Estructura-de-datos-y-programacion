#include <stdio.h>
#include <stdlib.h>

//Estructura que tiene el dato que quiero guardar en la lista
typedef struct 
{
    int numero;
} dato;

//Estructuras especificas para listas
struct nodo
{
    dato d;
    struct nodo * sig; //lo hago circular al nodo
};
typedef struct nodo Nodo;
typedef Nodo * Lista; //lo hago para no usar punteros a punteros
//FIN -- Estructura especificas para listas

//Funciones Creadas
int agregarPrincipio(Lista * plst, dato d); //recibo la lista e inserto un dato
void mostrarLista(Lista plst);
int agregarFinal(Lista * plst, dato unDato);
int eliminarPrincipio(Lista * plst);
void mostrarYVaciarLista(Lista plst);
int eliminarFinal(Lista * plst);

//Main
int main (void)
{
    Lista * lista = NULL;
    dato unnumero;
    
    /*
    printf("Agrego al principio\n");
    unnumero.numero = 10;
    agregarPrincipio(&lista, unnumero);
    unnumero.numero = 32;
    agregarPrincipio(&lista, unnumero);
    unnumero.numero = 1;
    agregarPrincipio(&lista, unnumero);
    unnumero.numero = 183;
    agregarPrincipio(&lista, unnumero);
    
    mostrarLista(lista);
    */

    //printf("Agrego al final\n");
    unnumero.numero = 10;
    agregarFinal(&lista, unnumero);
    unnumero.numero = 32;
    agregarFinal(&lista, unnumero);
    unnumero.numero = 1;
    agregarFinal(&lista, unnumero);
    unnumero.numero = 183;
    agregarFinal(&lista, unnumero);

    mostrarLista(lista);
    eliminarFinal(&lista);
    printf("\n\n");
    mostrarLista(lista);
    
    return 0;
}

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
}