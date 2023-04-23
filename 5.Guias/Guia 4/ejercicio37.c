#include <stdio.h>
#define LIMITE 100
int MENU()
{
    int n;
    printf("1.Cargar una matriz de MXN \n2.Informar el promedio de los valores \n3.Informar la suma de los valores de una fila \n4.Informar el producto de la diagonal principal y la secundaria\n5.Informar la cantidad de num postivos y negativos de una columna \n6.Mostrar la matriz traspuesta \n7.Salir\n");  
    scanf("%i",&n);
    while(n < 1 || n > 7)
    {
        printf("1.Cargar una matriz de MXN \n2.Informar el promedio de los valores \n3.Informar la suma de los valores de una fila \n4.Informar el producto de la diagonal principal y la secundaria\n5.Informar la cantidad de num postivos y negativos de una columna \n6.Mostrar la matriz traspuesta \n7.Salir\n");  
        scanf("%i",&n);
    }
    return n;
}
int main (void)
{
//37. Realizar un programa que presente un menú con las siguientes opciones:
    int promedio = 0,COLUMNAS,FILAS,f,c,filaElegida,loop=0,opcion,columnaElegida,positivos = 0, negativos = 0;
    float numero = 0,productoDiagP = 1,productoDiagOp = 1,sumaFila = 0,sumaMatriz = 0;
	int matriz[LIMITE][LIMITE];
    int matrizTranspuesta[COLUMNAS][FILAS];
    while (loop == 0)
    {
        opcion = MENU();
        switch(opcion)
        {
            case 1:
                //1. Cargar una matriz de MxN de tipo float.
                printf("Cuantas columnas desea que tenga la matriz? ");
                scanf("%i",&COLUMNAS);
                printf("Cuantas filas desea que tenga la matriz? ");
                scanf("%i",&FILAS);
                //Cargo la matriz
                for (f=0; f<FILAS; f++)
                {
                    for (c=0; c<COLUMNAS; c++)
                    {
                        scanf("%f",&numero);
                        matriz[f][c] = numero;
                    }
                }
                //Muestro la matriz
                for (f=0; f<FILAS; f++)
                {
                    for (c=0; c<COLUMNAS; c++)
                    {
                        printf("%5d", matriz[f][c]);
                    }
                    printf("\n");
                }
                break;
            case 2:
            {
                //2. Informar el promedio de todos los valores.
                for (f=0;f<FILAS;f++)
                {
                    for (c=0;c<COLUMNAS;c++)
                    {
                        sumaMatriz += matriz[f][c];
                    }
                }
                promedio = (float)(sumaMatriz/(float)(COLUMNAS*FILAS));
                printf("La promedio de todos los valores de la matriz es de %.2f\n",(float)(promedio));
                break;
            }
            case 3:
            {
                //3. Informar la suma de los valores de una fila (definida por el usuario).
                printf("Ingrese una fila del 0 al %i\n",(FILAS-1));
                scanf("%i",&filaElegida);
                while(filaElegida > FILAS || filaElegida < 0)
                {
                    printf("Ingrese una fila del 1 al %i\n",(FILAS-1));
                    scanf("%i",&filaElegida);   
                }
                for (f=0;f<FILAS;f++)
                {
                    for (c=0;c<COLUMNAS;c++)
                    {
                        if (f == filaElegida)
                        {
                            sumaFila += matriz[filaElegida][c];
                        }
                    }
                }
                printf("La suma de los numeros de la fila %i es de %.2f\n",filaElegida,sumaFila);
                break;
            }
            case 4:
            {                
                //4. Informar el producto de la diagonal principal y el de la diagonal secundaria.
                for (f=0;f<FILAS;f++)
                {
                    for (c=0;c<COLUMNAS;c++)
                    {
                        if (c == f)
                        {
                            productoDiagP *= matriz[f][c];
                        }
                        else if ((c+f) == (COLUMNAS - 1))
                        {
                            /* veo que la suma de (c+f) debe ser igual a (COLUMNAS-1) */
                            productoDiagOp *= matriz[f][c];
                        }
                        
                    }
                }
                printf("El producto de la diagonal principal es de %.2f\n",productoDiagP);
                printf("El producto de la diagonal opuesta es de %.2f\n",productoDiagOp);
                break;

            }
            case 5:
            {
                //5. Informar la cantidad de números positivos y negativos en una columna (definida por el usuario).
                printf("Ingrese una columna de la 0 a la %i\n",(COLUMNAS-1));
                scanf("%i",&columnaElegida);
                while(columnaElegida < 0 || columnaElegida > COLUMNAS)
                {
                    printf("Ingrese una columna de la 0 a la %i\n",(COLUMNAS-1));
                    scanf("%i",&columnaElegida);
                }
                for (f=0;f<FILAS;f++)
                {
                    for (c=0;c<COLUMNAS;c++)
                    {
                        if (c == columnaElegida)
                        {
                            if(matriz[f][columnaElegida] >= 0)
                            {
                                positivos++;
                            }
                            else if(matriz[f][columnaElegida] < 0)
                            {
                                negativos++;
                            }
                        }
                    }
                }
                printf("La cantidad de numeros positivos en la columna %i es de %i y la cantidad de numeros negativos es de %i\n",columnaElegida,positivos,negativos);
                break;
            }
            case 6:
            {
                //6. Mostrar la matriz traspuesta.
                for (f = 0;f < FILAS;f++)
                {
                    for (c = 0;c < COLUMNAS;c++)
                    {
                        printf("%5d", matriz[c][f]);
                    }
                    printf("\n");
                }
                break;
            }
            case 7:
            {
                //7. Salir del programa.
                loop = 1;
                break;
            }
        }


    }
    return 0;
}





