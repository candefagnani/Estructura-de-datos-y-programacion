#include "listas.h"
#ifndef PILAS_PILAS_H
#define PILAS_PILAS_H
typedef Lista Pila;

int apilar(Pila * pila, dato d );
int desapilar(Pila * pila, dato *d);
void CadenaAlRevez(Pila pila, char *cadena,int longitud);
int Verificacion(Pila pila,char *cuentaMatematica, int longitud);
#endif //PILAS_PILAS_H
