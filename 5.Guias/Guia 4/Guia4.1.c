#include <stdio.h>
#define CANTIDAD 10
#define BUFFER 64
int main(void)
{
    //32. Ingresar un vector de 10 números e informar el promedio.
    int suma = 0,promedio = 0,i,num;
    int vector[CANTIDAD];
    printf("Ingrese los valores de su verctor\n");
    for (i = 0; i < CANTIDAD; i++)
    {
        scanf("%i",&num);
        vector[i] = num;
        suma += num;
    }
    promedio = suma/CANTIDAD;
    printf("El vector es:\n");
    for (i=0; i<CANTIDAD; i++)
	{
	    printf("%5d", vector[i]);
	}
    printf("\nSu promedio es: %i\n",promedio);
    //33. Ingresar un vector de 10 números e informar el número máximo.
    int f = 0,valor,max;
    int vec[CANTIDAD];
    printf("Ingrese los valores de su verctor\n");
    for (f = 0; f < CANTIDAD; f++)
    {
        scanf("%i",&valor);
        vec[f] = valor;
        if (f == 0)
        {
            max = valor;
        }
        else
        {
            if (valor > max)
            {
                max = valor;
            }
            
        }
    }
    printf("El vector es:\n");
    for (f = 0; f < CANTIDAD; f++)
	{
	    printf("%5d", vec[f]); 
	}
    printf("\nEl valor maximo es: %i\n",max);
    //34. Ingresar datos a un vector finalizando con un número negativo, informar el producto.
    int h = 0, producto = 1 ,condicion = 0 ,contador = 0;
    int neg[BUFFER];
    printf("Ingrese los valores de su verctor\n");

    while (condicion >= 0)
    {
        scanf("%i",&condicion);
        neg[h] = condicion;
        h++;
        if (condicion >= 0)
        {
            producto = producto * condicion;
            contador ++;
        }    
    }
    printf("El vector es:\n");
    for (h = 0; h < contador; h++)
	{
        printf("%2d", neg[h]); 
	}
    printf("\nEl producto es: %i\n",producto);
    return 0;
}



