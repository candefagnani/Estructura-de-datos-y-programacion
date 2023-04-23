#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int valor;
} tipo_d;

typedef struct nodo {
    tipo_d dato;
    struct nodo *sig;
} Nodo;

typedef Nodo* pNodo;

pNodo crearNodo(tipo_d dato);

tipo_d cargarTipoD();

int leerLista(pNodo *cabeza);
int agregarPpio(pNodo *cabeza, tipo_d d);
int agregarFinal(pNodo *cabeza, tipo_d dato);
int posicion(pNodo *cabeza, tipo_d dato);
pNodo avanzarHastaPosicion(pNodo *cabeza, int k);
int in(pNodo *cabeza, tipo_d dato);
int agregarEnK(pNodo *cabeza, tipo_d dato, int k);
int borrarElemento(pNodo *cabeza, int k);
int editarElemento(pNodo *cabeza, int k);
int len(pNodo *cabeza);
int swap(pNodo *cabeza, int i, int j);
int ordenarListaDecreciente(pNodo *cabeza);
int ordenarListasConjuntas(pNodo *cab1,pNodo *cab2);
int frecuencias(pNodo *cabeza);
