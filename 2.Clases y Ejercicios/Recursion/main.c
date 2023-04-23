//RECURSION
/*5! = 5x4x3x2x1
 5! = 5x4!
 4! = 4x3!*/
#include <stdio.h>
#include "string.h"

int factorial(int nro);
int factorial2(int nro);
int fibo(int nro);
int multiplicacion(int nro1, int nro2);
int cociente(int nro1, int nro2);
int CadenaDadaVuelta(char *cadena);

int main(void)
{
    int nro1, nro2;
    char cadena[50];

    printf("Ingrese el primer numero: ");
    scanf("%d",&nro1);
    while (nro1 < 0)
    {
        printf("Ingrese el primer numero: ");
        scanf("%d",&nro1);
    }
    printf("Ingrese el segundo numero: ");
    scanf("%d",&nro2);
    while (nro2 < 0)
    {
        printf("Ingrese el segundo numero: ");
        scanf("%d",&nro2);
    }
    printf("El %d! = %d\n",nro1,factorial(nro1));
    printf("El %d! = %d\n",nro2,factorial(nro2));
    //printf("El %d! = %d\n",nro,factorial2(nro));
    printf("El numero %d de la serie de Fibonacci es %d\n",nro1,fibo(nro1));
    printf("El numero %d de la serie de Fibonacci es %d\n",nro2,fibo(nro2));
    printf("La multiplicacion entre %d y %d es %d\n",nro1,nro2,multiplicacion(nro1,nro2));
    printf("La division entre %d y %d es %d\n",nro1,nro2,cociente(nro1,nro2));

    printf("Ingrese una cadena: ");
    fflush(stdin);
    gets(cadena);
    printf("La cadena dada vuelta es: %s\n",CadenaDadaVuelta(&cadena));

    return 0;
}

int factorial(int nro)
{
    if (nro == 0)
        return 1;
    else
        return nro * factorial(nro-1);
    //funcion que se llama a si misma-> recursion
}

int factorial2(int nro)
{
    int res = 1, i = 1;
    for (i = 1; i <= nro; i++)
    {
        res *= i;
    }
    return res;
    //No usa recursividad
}

int fibo(int nro)
{
    if (nro == 0 || nro == 1)
        return nro;
    else
        return(fibo(nro-1)+fibo(nro-2));
    //arranca el 0 y no me lo toma entonces el nro 10 que es 34 acá tendría que poner 9
}

int multiplicacion(int nro1, int nro2)
{
    if (nro2 == 0 || nro1 == 0)
        return 0;
    else
        return nro1 + (multiplicacion(nro1, (nro2-1)));
}

int cociente(int nro1, int nro2)
{

    if(nro1 < nro2)
        return 0;
    else
        return 1+cociente((nro1-nro2),nro2);
}

int CadenaDadaVuelta(char *cadena)
{
    int longitud;
    longitud = strlen(cadena);
    if (longitud <= 1)
        return 0;
    else
    {
        char temporal = *cadena;
        *cadena = *(cadena + (longitud-1));
        *(cadena + (longitud-1)) = '\0';
        CadenaDadaVuelta(cadena+1);
        *(cadena + (longitud-1)) = temporal;
    }
    //CANDE/0
    //EDNCA/0
}

/*
 void Reverse(char* string) {
    int len = strlen(string);
    if (strlen (string) <= 1) {// Fin de la condición de inserción
        return;
    }
    char tmp = *string;
    * string = * (string + len-1); // primer caracter = ultimo caracter
    * (string + len-1) = '\ 0'; // Carácter de cola = '\ 0'
    Reverse (string + 1); // Empuje la pila, continúe intercambiando
    * (string + len-1) = tmp; // Eliminar la pila y restaurar el original '\ 0' al carácter original
}

*/