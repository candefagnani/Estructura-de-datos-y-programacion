#include <stdio.h>
#include <math.h>
#define BUFFER 64
//35. Calcular las estadísticas de un conjunto de N Elementos de un Vector (media,
//varianza, desvío y frecuencia de los elementos) e informarla por pantalla.

int main (void)
{
    int N[BUFFER], numero, i = 0, contador;
    float desvio; 
    double media = 0, var = 0;
    printf("Ingrese su verctor N:\n");
    while (numero >= 0)
    {
        scanf("%i",&numero);
        N[i] = numero;
        i++;
        if (numero >= 0)
        {
            media += N[i];
            contador++;
        }
    }
    printf("El verctor es:\n");
    for (i = 0; i < contador; i++)
    {
        printf("%2d",N[i]);
    }
    printf("\n");
    media = media/(double) N[i];
    for (i = 0; i < contador; i++)
    {
        var += ((N[i]-media)*(N[i]-media));
    }
    var = var/contador;
    desvio = sqrt(var);
    printf("La media es %.2f\n",media);
    printf("La varianza es de %.2f\n",var);
    printf("La varianza es de %.2f\n",desvio);
    return 0;
}