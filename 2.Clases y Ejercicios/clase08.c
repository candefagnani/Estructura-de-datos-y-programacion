#include <stdio.h>
#include <stdlib.h>

struct nodo {
    int valor;
    struct nodo *sig;
};

void mostrarLista(struct nodo *p) {
    while (p != NULL) {
        printf("%d ", p->valor);
        p = p->sig;
    }
}

int main() 
{
    struct nodo *cab;
    struct nodo *uno = NULL;
    struct nodo *dos = NULL;
    struct nodo *tres = NULL;
    struct nodo *cuatro = NULL;

    uno = malloc(sizeof(struct nodo));
    dos = malloc(sizeof(struct nodo));
    tres = malloc(sizeof(struct nodo));
    cuatro = malloc(sizeof(struct nodo));

    uno->valor = 10;
    dos->valor = 20;
    tres->valor = 30;
    cuatro->valor = 40;

    uno->sig = dos;
    dos->sig = tres;
    tres->sig = cuatro;
    cuatro->sig = NULL;

    cab = uno;
    mostrarLista(cab);
    printf("\n");
}