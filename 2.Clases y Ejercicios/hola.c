#include <stdio.h>

int main (void)
{
    printf("Hola Cande\n");
    int num1,num2,num3;
    printf("Ingrese el primer numero entero:");
    scanf("%i",&num1);
    printf("Ingrese el segundo numero entero:");
    scanf("%i",&num2);
    printf("Ingrese el tercer numero entero:");
    scanf("%i",&num3);
    if (num1>num2 && num1>num3)
    {
        printf("%i es el mayor",num1);
    }
    else if (num2>num1 && num2>num3)
    {
        printf("%i es el mayor",num2);
    }
    else
    {
        printf("%i es el mayor",num3);
    }
    printf("\n");
    return 0;
}