#include "Colas.h"
#include <stdio.h>
#include <stdlib.h>

int ingresar(Cola * pcola, dato dato){
    agregarFinal(pcola,dato);
    return 1;
}
int sacar(Cola * pcola, dato * dato){
    if ( *pcola == NULL ){
        return 0;
    }
    *dato = (*pcola)->d;
    eliminarPrincipio(pcola);
    return 1;
}
