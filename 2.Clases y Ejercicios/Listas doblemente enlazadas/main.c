#include <stdio.h>
#include "librerias/listasDE.h"
#include "string.h"

Lista CargarCanciones();
int menu();


int main(void)
{
    Lista lstMusical = CargarCanciones();
    int opcion = 0;

    while(opcion != 9)
    {
        printf("Reproduciendo...\n");
        mostrarElemento(lstMusical->d);

        opcion = menu();
        switch(opcion){
            case 1:
            {
                Siguiente(&lstMusical);
                break;
            }
            case 2:
            {
                Anterior(&lstMusical);
                break;
            }
        }
    }

    return 0;
}

Lista CargarCanciones()
{
Lista lstMusical = NULL;
dato unaCancion;

unaCancion.numero = 1;
strcpy(unaCancion.autor, "Moon Garden");
strcpy(unaCancion.nombre, "Sunny Horizon");
insertar(&lstMusical, unaCancion);

unaCancion.numero = 2;
strcpy(unaCancion.autor, "Morat");
strcpy(unaCancion.nombre, "Paris");
insertar(&lstMusical, unaCancion);

unaCancion.numero = 32;
strcpy(unaCancion.autor, "Shakira");
strcpy(unaCancion.nombre, "Dias de Enero");
insertar(&lstMusical, unaCancion);

unaCancion.numero = 4;
strcpy(unaCancion.autor, "Diego Torres");
strcpy(unaCancion.nombre, "Un poquito");
insertar(&lstMusical, unaCancion);

unaCancion.numero = 11;
strcpy(unaCancion.autor, "Rio Roma");
strcpy(unaCancion.nombre, "Mi persona favorita");
insertar(&lstMusical, unaCancion);
return lstMusical;
}

int menu()
{
    int opcion = 0;

    printf("Opciones de reproduccion:\n");
    printf("1: siguiente cancion\n");
    printf("2: Anterior cancion\n");
    printf("9: Salir\n");
    printf("Ingrese su opion:\n");
    scanf("%d", &opcion);

    return opcion;
}