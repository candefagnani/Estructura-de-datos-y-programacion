#include <stdio.h>
#include "librerias/listasDE.h"
#include "string.h"


Lista CargarLista();
int menu();

int main(void)
{
    Lista lista = CargarLista();
    int opcion, elementos,rta;
    dato unString;
    char StringABuscar[100];
    char cadena1[100],cadena2[100];

    opcion = menu();

    while(opcion != 9)
    {
        switch (opcion)
        {
            case 1: //a) Mostrar las Cadenas Leídas
            {
                mostrarLista(lista);
                printf("\n");
                break;
            }
            case 2: //b) Agregar un Elemento
            {
                printf("Ingrese su string\n");
                fflush(stdin);
                gets(unString.string);
                insertar(&lista,unString);
                printf("Ahora la lista queda...\n");
                mostrarLista(lista);
                printf("\n");
                break;
            }
            case 3: //c) Borrar un Elemento
            {
                printf("Que palabra desea borrar?\n");
                fflush(stdin);
                gets(StringABuscar);
                if(BuscarNodo(&lista,StringABuscar))
                {
                    printf("Encontrado\n");
                    strcpy(unString.string,StringABuscar);
                    eliminar(&lista,unString);
                    mostrarLista(lista);
                    printf("\n");
                }
                else
                    printf("El elemento no fue encontrado en la lista\n");
                break;
            }
            case 4: //d) Buscar un Elemento
            {
                printf("Que elemento desea buscar?..\n");
                fflush(stdin);
                gets(StringABuscar);
                if(BuscarNodo(&lista,StringABuscar))
                    printf("El elemento fue encontrado en la lista\n");
                else
                    printf("El elemento no fue encontrado en la lista\n");
                break;
            }
            case 5: //e) Cantidad de Elementos Leídos
            {
                elementos = leeElementos(lista);
                printf("La cantidad de elementos de la lista es de %d\n", elementos);
                break;
            }
            case 6: //f) Dar la longitud de una cadena Buscada
            {
               printf("De cual string deseas saber la longitud?\n");
                fflush(stdin);
                gets(StringABuscar);
                if(BuscarNodo(&lista,StringABuscar))
                    printf("La longitud de %s es %d\n",StringABuscar,longitud(StringABuscar));
                else
                    printf("El string no fue encontrado en la lista\n");
                break;
            }
            case 7: //g) Copiar dos cadenas elegidas por Posición, una después de la otra, mostrando el
                    // Resultado por pantalla y agregándole a la Lista
            {
                printf("Cuales son los strings que quieres encadenar?\n");
                printf("Cadena 1...\n");
                fflush(stdin);
                gets(cadena1);
                printf("Cadena 2...\n");
                fflush(stdin);
                gets(cadena2);
                if(BuscarNodo(&lista,cadena1) && BuscarNodo(&lista,cadena2))
                {
                    printf("Ambar cadenas se encuentran en la lista, se pueden unir\n");
                    strcat(strcpy(StringABuscar,cadena1),cadena2);
                    printf("Los strings unidos quedan...%s\n",StringABuscar);
                    strcpy(unString.string,StringABuscar);
                    insertar(&lista,unString);
                    printf("Ahora la cadena queda...\n");
                    mostrarLista(lista);
                    printf("\n");
                }
                else
                    printf("Alguno de los strings no pertenece a la lista\n");
                break;
            }
            case 8: //h) Convertir la cadena todo a Minúsculas o Mayúsculas, según lo desee el usuario.
            {
                printf("Que string desea convertir...\n");
                fflush(stdin);
                gets(StringABuscar);
                if(BuscarNodo(&lista,StringABuscar))
                {
                   printf("Desea pasarlo a mayusculas (1) o a minusculas (2)...\n");
                   scanf("%d",&rta);
                   if(rta == 1)
                       mayusculas(StringABuscar);
                   else
                       minusculas(StringABuscar);
                }
                else
                    printf("El string no se encuentra en la lista\n");
                break;
            }
        }
        opcion = menu();
        if (opcion == 9)
        {
            printf("Programa terminado\n");
            break;
        }
    }
    return 0;
}

Lista CargarLista()
{
    Lista lista = NULL;
    dato unString;

    printf("Ingrese su string (o F para terminar de agregar)\n");
    fflush(stdin);
    gets(unString.string);
    while((unString.string[0] != 'F'))
    {
        insertar(&lista,unString);
        printf("Ingrese su string (o F para terminar de agregar)\n");
        fflush(stdin);
        gets(unString.string);
    }
    return lista;
}

int menu()
{
    int opcion;
    printf("1) Mostrar las Cadenas Leídas\n"
           "2) Agregar un Elemento\n"
           "3) Borrar un Elemento\n"
           "4) Buscar un Elemento\n"
           "5) Cantidad de Elementos Leídos\n"
           "6) Dar la longitud de un cadena Buscada\n"
           "7) Copiar dos cadenas elegidas por Posición, una después de la otra, mostrando el resultado por pantalla y agregándole a la Lista\n"
           "8) Convertir la cadena todo a Minúsculas o Mayúsculas, según lo desee el usuario.\n"
           "9) Salir del programa.\n");
    printf("Su opcion:\t");
    scanf("%d",&opcion);
    while(opcion < 1 || opcion > 9)
    {
        printf("1) Mostrar las Cadenas Leídas\n"
               "2) Agregar un Elemento\n"
               "3) Borrar un Elemento\n"
               "4) Buscar un Elemento\n"
               "5) Cantidad de Elementos Leídos\n"
               "6) Dar la longitud de un cadena Buscada\n"
               "7) Copiar dos cadenas elegidas por Posición, una después de la otra, mostrando el resultado por pantalla y agregándole a la Lista\n"
               "8) Convertir la cadena todo a Minúsculas o Mayúsculas, según lo desee el usuario.\n"
               "9) Salir del programa.\n");
        printf("Su opcion:\t");
        scanf("%d",&opcion);
    }
    return opcion;
}

