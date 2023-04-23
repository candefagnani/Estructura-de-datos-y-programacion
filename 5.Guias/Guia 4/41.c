#include <stdio.h>
#define LIMITE 100

//ESTRUCTURAS CREADAS
typedef struct
{
    int columnas;
    int filas;
    int matriz[LIMITE][LIMITE];
} matriz_t;


//FUNCIONES DEFINIDAS
int MENU();
void cargarMatriz(matriz_t filas, matriz_t columnas);
void mostrarMatriz(matriz_t *matriz);
void sumaMatrices(matriz_t *matrizA, matriz_t *matrizB);
void restaMatrices(matriz_t *matrizA, matriz_t *matrizB);

int main (void)
//41. Realizar un programa que presente un menú con las siguientes opciones:
{
    int opcion, loop = 0;
    matriz_t matriz1,matriz2;
    while (loop == 0)
    {
        opcion = MENU();
        switch(opcion)
        {

            case 1:
                //8. Cargar 2 matrices de MxN de tipo float.
                //voy con matriz1
                printf("Cuantas filas quiere que tenga su matriz1? ");
                scanf("%i",&matriz1.filas);
                while (matriz1.filas < 1 || matriz1.filas > 100)
                {
                    printf("Cuantas filas quiere que tenga su matriz1? ");
                    scanf("%i",&matriz1.filas);
                }
                printf("Cuantas columnas quiere que tenga su matriz1? ");
                scanf("%i",&matriz1.columnas);
                while (matriz1.columnas < 1 || matriz1.columnas > 100)
                {
                    printf("Cuantas columnas quiere que tenga su matriz1? ");
                    scanf("%i",&matriz1.columnas);
                }
                printf("\n");
                matriz1.matriz = cargarMatriz(matriz1.filas,matriz1.columnas);
                //voy con matriz2
                printf("Cuantas filas quiere que tenga su matriz2? ");
                scanf("%i",&matriz2.filas);
                while (matriz2.filas < 1 || matriz2.filas > 100)
                {
                    printf("Cuantas filas quiere que tenga su matriz2? ");
                    scanf("%i",&matriz2.filas);
                }
                printf("Cuantas columnas quiere que tenga su matriz2? ");
                scanf("%i",&matriz2.columnas);
                while (matriz2.columnas < 1 || matriz2.columnas > 100)
                {
                    printf("Cuantas columnas quiere que tenga su matriz2? ");
                    scanf("%i",&matriz2.columnas);
                }
                printf("\n");
                matriz2.matriz = cargarMatriz(matriz2.filas, matriz2.columnas);
                mostrarMatriz(&matriz1);
                mostrarMatriz(&matriz2);
                break;
            case 2:
                //9. Informar la Suma de las Matrices.
                sumaMatrices(&matriz1,&matriz2);
                break;
            case 3:
            {
                //10. Informar la Resta de las Matrices.
                restaMatrices(&matriz1,&matriz2);
                break;
            }
            case 4:
        
                //11. Informar el producto de las Matrices.
                break;
            case 5:
                 //12. Informar la cantidad de números iguales que existen en ambas matrices.
                 break;
            case 6:
                //13. Mostrar la matriz traspuesta de Ambas.
                break;
            
            case 7:
                //14. Salir del programa.
                loop = 1;
                break;
        }
    }
    return 0;
}

int MENU()
{
    int respuesta;
    printf("1.Cargar 2 matrices de MXN de tipo float \n2.Informar la suma de matrices \n3.Informar la resta de matrices \n4.Informar el producto de las matrices \n5.Informar la cantidad de numeros iguales que existen en ambas matrices \n6.Mostrar la matriz traspuesta de ambas \n7.Salir del programa\n");
    scanf("%i",&respuesta);
    while (respuesta < 1 || respuesta > 7)
    {
    printf("1.Cargar 2 matrices de MXN de tipo float \n2.Informar la suma de matrices \n3.Informar la resta de matrices \n4.Informar el producto de las matrices \n5.Informar la cantidad de numeros iguales que existen en ambas matrices \n6.Mostrar la matriz traspuesta de ambas \n7.Salir del programa\n");
    scanf("%i",&respuesta);
    }
    return respuesta;
}

void cargarMatriz(matriz_t filas, matriz_t columnas)
{
    int f,c;
    int numero;
    matriz_t matriz;
    for (f = 0; f < matriz.filas; f++)
    {
        for(c = 0; c < matriz.columnas; c++)
        {
            scanf("%i",&numero);
            matriz.matriz[f][c] = numero;
        }
    }
}

void mostrarMatriz(matriz_t *matriz)
{
    int f,c;
    printf("Filas: %d\n", matriz->filas);
    printf("Col: %d\n", matriz->columnas);

    for (f = 0; f < matriz->filas; f++)
    {
        for (c = 0; f < matriz->columnas; c++)
        {
            printf("%.2f", ((float**)matriz->matriz)[f][c]);
            
        }
        printf("\n");
    }
} 

void sumaMatrices(matriz_t *matrizA, matriz_t *matrizB)
{
    int f,c;
    matriz_t matrizSuma;
    if (((*matrizA).filas == (*matrizB).filas) && ((*matrizA).columnas == (*matrizB).columnas))
    {
        for (f = 0; f < (*matrizA).filas; f++)
        {
            for (c = 0; c < (*matrizA).columnas; c++)
            {
                matrizSuma.matriz[f][c] = (*matrizA).matriz[f][c] + (*matrizB).matriz[f][c];
            }
        }
        mostrarMatriz(&matrizSuma);
    }
    else 
        printf("La suma de las matrices no se puede efectuar porque no se tiene la misma dimension\n");
}

void restaMatrices(matriz_t *matrizA, matriz_t *matrizB)
{
    int f,c;
    matriz_t matrizResta;
    if (((*matrizA).filas == (*matrizB).filas) && ((*matrizA).columnas == (*matrizB).columnas))
    {
        for (f = 0; f < (*matrizA).filas; f++)
        {
            for (c = 0; c < (*matrizA).columnas; c++)
            {
                matrizResta.matriz[f][c] = (*matrizA).matriz[f][c] + (*matrizB).matriz[f][c];
            }
        }
        mostrarMatriz(&matrizResta);
    }
    else 
        printf("La resta de las matrices no se puede efectuar porque no se tiene la misma dimension\n");
}
