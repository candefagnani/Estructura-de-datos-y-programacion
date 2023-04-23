#include "stdio.h"
#include "pilas.h"

int apilar(Pila * pila, dato d){
    return agregarPrincipio(pila, d);
}
int desapilar(Pila * pila, dato *d){
    if (*pila == NULL)
        return 0;
    *d = (*pila)->d;
    return eliminarPrincipio(pila);
}
