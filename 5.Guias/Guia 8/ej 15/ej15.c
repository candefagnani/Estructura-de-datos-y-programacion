#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "listas.h"

int sacarProducto(Nodo **pcabeza,int *pcontprod,int *pcontclientes)
{
    int segundosProducto;
    if ((*pcabeza)->num.numero == 0)
    {
        eliminarPrincipio(pcabeza);
        *pcontclientes+=1;
        puts("Se saco un cliente");
        segundosProducto=0;
    }
    if ((*pcabeza)->num.numero != 0)
    {
        segundosProducto=2+rand()%10;
        (*pcabeza)->num.numero -=1;
        *pcontprod+=1;
        printf("Se cobro un producto, consumiendo %d segundos. Ahora le quedan %d productos a la cabeza\n",segundosProducto,(*pcabeza)->num.numero);
    }

    return segundosProducto;
}

void sumarCliente(Nodo **pcabeza)
{
    int productos;
    productos=3+rand()%10;
    Lista agregado= creaNodo(productos);
    agregaFinal(pcabeza,agregado);
    printf("Se suma cliente con %d productos\n",productos);
    return;
}

int main(void)
{
    srand(time(NULL));

    Lista cabeza = NULL;
    Nodo **pcabeza;
    pcabeza = &cabeza;

    int segundos = 1;
    int segundosProducto,auxsegundos;

    int contprod = 0;
    int *pcontprod;
    pcontprod = &contprod;

    int contclientes = 0;
    int *pcontclientes;
    pcontclientes = &contclientes;

    int horas, minutos, maximo = 0;

    puts("Ingrese cantidad de horas");
    scanf("%d",&horas);
    maximo += (horas*60*60);

    puts("Ingrese cantidad de minutos");
    scanf("%d",&minutos);
    maximo += (minutos*60);

    sumarCliente(pcabeza);
    while (segundos<=maximo)
    {
        auxsegundos = segundos;
        segundosProducto = sacarProducto(pcabeza,pcontprod,pcontclientes);
        while (segundos < (auxsegundos+segundosProducto))
        {
            if (segundos%5 == 0)
                sumarCliente(pcabeza);
            segundos+=1;
        }
    }

    printf("Se vendieron %d productos\n",*pcontprod);
    printf("Se atendieron %d clientes\n",*pcontclientes);
    return 0;
}
