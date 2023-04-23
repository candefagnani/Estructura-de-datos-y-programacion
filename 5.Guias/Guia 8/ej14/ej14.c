#include <stdio.h>
#include <stdlib.h>
#include "colas.h"

int main(void)
{
    Cola *cola1 = NULL;
    Cola *cola2 = NULL;
    Cola *colaSuma = NULL;
    dato num;

    //Creo la cola 1
    num.numero = 3;
    agregar(&cola1,num);
    num.numero = 4;
    agregar(&cola1,num);
    num.numero = 2;
    agregar(&cola1,num);
    num.numero = 8;
    agregar(&cola1,num);
    num.numero = 12;
    agregar(&cola1,num);

    //Creo la cola 2
    num.numero = 6;
    agregar(&cola2,num);
    num.numero = 2;
    agregar(&cola2,num);
    num.numero = 9;
    agregar(&cola2,num);
    num.numero = 11;
    agregar(&cola2,num);
    num.numero = 3;
    agregar(&cola2,num);

    //Muestro la cola suma
    sumaColas(cola1,cola2,&colaSuma);
    
    return 0;
}


/*14. Utilizando la clase Cola, escriba una función que reciba 2 Colas con números enteros
y devuelva una nueva Cola con sus elementos sumados uno a uno.
Cola A Cola B Cola Resultado
3        6         9
4        2         6
2        9         11
8        11        19
12       3         15
*/

