#include "definiciondato.h"

//Estructuras especificas para listas
struct nodo
{
    dato d;
    struct nodo * sig; //lo hago circular al nodo
};
typedef struct nodo Nodo;
typedef Nodo * Lista; //lo hago para no usar punteros a punteros
//FIN -- Estructura especificas para listas

int agregarPrincipio(Lista * plst, dato d);
void mostrarLista(Lista plst);
int agregarFinal(Lista * plst, dato unDato);
int eliminarPrincipio(Lista * plst);
void mostrarYVaciarLista(Lista plst);
int eliminarFinal(Lista * plst);
void producto(Lista plst);
int leeElementos(Lista plst);
void EliminarNodo(Lista *plst, int numAEliminar);
int buscaMaximo(Lista plst);
int BuscarNodo(Lista *plst, int numABuscar);