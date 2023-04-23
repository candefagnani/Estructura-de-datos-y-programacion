#include <stdio.h>
#include <stdlib.h>

/*51. Ingresar datos Dinámicamente en un vector finalizando con un número
negativo, informar el producto. Se debe ir redimensionando el vector, en tanto
se requiere más espacio para más números.

int main(void)
{
    int i = 0, producto = 1, num = 0, j = 1;
    int *vector;
    vector = (int *) malloc(sizeof(int));
    while (num >= 0)
    {
        scanf("%i",&num);
        if (num >= 0)
        {
            vector[i] = num;
            i++;
            vector = (int*) realloc(vector, j * sizeof(int));
            producto *= num;
        }
    }
    printf("El vector es:\n");
    for (j = 0; j < (i); j++)
        printf("%i ",vector[j]);
    printf("\nEl producto del vector es: %i\n", producto);
    free(vector);
    return 0;
}
*/


int main()
{
    int * vector;
    int i, j, salto=3,producto = 1;
    int num;
    vector = (int*) malloc(salto * sizeof(int));
    if (vector == NULL)
    {
        printf("no se pudo disponibilizar la memoria...\n");
        return 0;
    }
    i = 0;
    printf("Ingrese un numero natural:");
    scanf("%d", &num);
    while (num > 0)
    {
        vector[i] = num;
        i++;
        if (i % salto == 0) //son multiplos, osea, me quede sin espacio
        {
            vector = realloc(vector, (i + salto) * sizeof(int));
            if (vector == NULL)
            {
                printf("no se pudo disponibilizar la memoria...\n");
                return 0;
            }
        }
        producto *= num;
        printf("Ingrese un numero natural:");
        scanf("%d", &num);
    }

    for (j=0; j<i; j++)
        printf("%d ", vector[j]);
    printf("\nEl producto es: %d\n",producto);
    free(vector);
    return 0;
}
