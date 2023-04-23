//41. Realizar un programa que presente un menú con las siguientes opciones:
#include <stdio.h>
#define LIMITE 100

int MENU()
{
    int opcion;
    printf("Ingrese una de las siguientes opciones\n");
    printf("1. Cargar 2 matrices MxN tipo float \n2.Informar la suma de las matrices \n3.Informar la resta de las matrices \n4.Informar el producto de las matrices \n5.Informar la cantidad de numeros iguales que existen en ambas matrices \n6.Mostrar la matriz traspuesta de ambas \nSalir del programa\n");
    scanf("%i",opcion);
    while (opcion < 1 || opcion > 7)
    {
        printf("1. Cargar 2 matrices MxN tipo float \n2.Informar la suma de las matrices \n3.Informar la resta de las matrices \n4.Informar el producto de las matrices \n5.Informar la cantidad de numeros iguales que existen en ambas matrices \n6.Mostrar la matriz traspuesta de ambas \nSalir del programa\n");
        scanf("%i",opcion);
    }
    return opcion;
}

int main (void)
{
    int loop = 0, respuesta,filas;
    float matriz1[LIMITE][LIMITE];
    float matriz2[LIMITE][LIMITE];
    while (loop == 0)
    {
        respuesta = MENU();
        switch(respuesta)
        {
            case 1:
            {
                //8. Cargar 2 matrices de MxN de tipo float.
                break;
            }
            case 2:
            {
                //9. Informar la Suma de las Matrices.
                
                break;
            }
            case 3:
            {
                //10. Informar la Resta de las Matrices.
                break;
            }
            case 4:
            {
                //11. Informar el producto de las Matrices.
                break;
            }
            case 5:
            {
                //12. Informar la cantidad de números iguales que existen en ambas matrices.
                break;
            }
            case 6:
            {
                //13. Mostrar la matriz traspuesta de Ambas.
                break;
            }
            case 7:
            {
               //14. Salir del programa.
                loop = 1;
                break;
            }
        }
    }
    return 0;
}