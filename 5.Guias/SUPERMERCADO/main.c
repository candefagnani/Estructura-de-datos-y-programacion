#include <stdio.h>
#include <stdlib.h>
#include "Colas.h"
#include <time.h>

int main(void)
{
    Cola cola = NULL;
    dato cliente;
    int i, cantClient = 0, cantProd = 0, tPasado = 0, txp = 0;
    srand(time(NULL));
    for (i = 0; i <= 28800; i++)
    {
        if (i == 0)
            txp = rand()%13 + 2;
        if (i%5 == 0){
            cliente = (rand()%20) + 3;
            ingresar(&cola, cliente);
            cantClient++;
        }
        tPasado++;
        if((*cola).d != 0 && (txp) == tPasado)
        {
            (*cola).d--;
            cantProd++;
            tPasado = 0;
            txp = rand()%17 + 2;
        }
        if((*cola).d == 0)
        {
            sacar(&cola, &cliente);
            tPasado = 0;
        }
    }
    printf("Clientes %d\n", cantClient);
    printf("Productos %d\n", cantProd);
    return 0;
}