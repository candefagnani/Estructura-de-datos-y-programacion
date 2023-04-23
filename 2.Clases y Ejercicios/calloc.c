#include <stdio.h>
#include <stdlib.h>


int main() 
{
    int * matriz;
    int f, c;
    matriz = calloc(3 * 3, sizeof(int));
    if (matriz == NULL)
    {
        printf("La memoria no se pudo disponibilizar...");
        return 1;
    }
    for (f=0; f<3; f++)
    {
        for (c=0; c<3; c++)
        {
            matriz[f+c] = f + c;
        }
    }
    for (f=0; f<3; f++) {
        for (c = 0; c < 3; c++)
        {
            printf("%5d", matriz[f+c]);
        }
        printf("\n");
    }
    free(matriz);
    return 0;
}