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
void CadenaAlRevez(Pila pila, char *cadena,int longitud)
{
    int i = 0;
    dato aux;
    dato letra;
    for (i = 0; i < longitud; i++)
    {
        aux = cadena[i];
        apilar(&pila,aux);
    }
    for (i = 0; i < longitud; i++)
    {
        desapilar(&pila,&letra);
        mostrarElemento(letra);
    }
}