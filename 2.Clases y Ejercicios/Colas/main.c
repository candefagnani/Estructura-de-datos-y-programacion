#include <stdio.h>
#include <stdlib.h>
#include "colas.h"

int main(void)
{
    Cola *cola = NULL;
    dato cliente;
    printf("Bienvenido a la cola virtual del supermercado. Pronto sera atendido...\n");
    cliente.numero = 1;
    agregar(&cola, cliente);
    cliente.numero = 2;
    agregar(&cola, cliente);

    cliente.numero = 3;
    agregar(&cola, cliente);

    while (sacar(&cola, &cliente))
    {
        printf("%d\n", cliente.numero);
    }
    printf("Se terminaron los datos de la cola\n");
    return 0;
}