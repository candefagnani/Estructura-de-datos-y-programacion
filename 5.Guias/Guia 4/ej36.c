#include <stdio.h>
#include<stdlib.h>
#define BUFFER 64

int MENU()
{
    int OP;
    printf("Escriba la opcion que desee:\n");
    printf("1. Leer por teclado 2 cadenas de caracteres\n""2. Imprimirlas cada cadena del derecho y al revés\n" "3. Dar la longitud de las cadenas\n" "4. Copiar las dos cadenas,\n" "5. Buscar una cadena dentro de la otra\n" "6. Convertir la cadena todo a Minúsculas o Mayúsculas\n" "7. Salir del programa\n");
    scanf("%i",&OP);
    while(OP < 1 || OP > 7)
    {
        printf("1. Leer por teclado 2 cadenas de caracteres\n""2. Imprimirlas cada cadena del derecho y al revés\n" "3. Dar la longitud de las cadenas\n" "4. Copiar las dos cadenas,\n" "5. Buscar una cadena dentro de la otra\n" "6. Convertir la cadena todo a Minúsculas o Mayúsculas\n" "7. Salir del programa\n");
        scanf("%i",&OP);
    }
    return OP;
}

int longitud(const char* cad)
{
    int cuenta = 0;
    while(cad[cuenta])
    {
        cuenta++;
    }
    return cuenta;
}

int same(char Larga[], char Corta[])
{   int l1, l2, Hit=0, i, j, pos=0;
    l1=longitud(Larga);     l2=longitud(Corta);
    for(i = 0; i <= l1; i++)
    {
        if (Larga[i] == Corta[0])
        {   
            pos=i;
            for(j=0;j<l2;j++, i++)
            {
                if (Larga[i]==Corta[j]) 
                    Hit=1;
                else 
                    Hit=0; break;
            }
        }
        if (Hit) 
            break;
    }
    if (Hit) 
        return pos;
    else 
        return -1;
}

void minusculas(char cadena[])
{
    int i;
    for (i = 0; i < longitud(cadena); i++)
    {
        if (cadena[i]>='A' && cadena[i]<='Z') 
            cadena[i] = cadena[i] + 32;
    }
    printf("cadena en minusculas: %s\n",cadena);      
}

void mayusculas(char cadena[])
{
    int i;
    for (i = 0; i < longitud(cadena); i++)
    {
        if (cadena[i]>='a' && cadena[i]<='z') 
            cadena[i] = cadena[i] - 32;
    }
    printf("cadena en mayusculas: %s\n",cadena);      
}

int main (void)
{
    //36. Escribir un programa que posea un menú con las siguientes opciones:
    int respuesta,l1 = 0, l2 = 0,numero = 0,loop = 0, i,pos,Mm;
    char cadena1[BUFFER];
    char cadena2[BUFFER];
    char subcadena[BUFFER];
    while (loop == 0)
    {
        respuesta = MENU();
        switch(respuesta)
        {
            case 1:
            {
                //1. Leer por teclado 2 cadenas de caracteres.
                printf("Ingrese cadena 1: ");
                fflush(stdin);
                gets(cadena1);
                printf("Ingrese cadena 2: ");
                fflush(stdin);
                gets(cadena2);
                l1 = longitud(cadena1);
                l2 = longitud(cadena2);
                break;
            }
            case 2:
            {
                //2. Imprimirlas cada cadena del derecho y al revés.
                printf("La Cadena 1 al derecho: %s\n",cadena1);
                printf("La cadena 1 al reves: \n");
                for (i = l1-1; i >= 0 ; i--)
                {
                    printf("%c",cadena1[i]);
                }
                printf("La Cadena 2 al derecho: %s\n",cadena2);
                printf("La cadena 2 al reves: \n");
                for (i = l2-1; i >= 0 ; i--)
                {
                    printf("%c",cadena2[i]);
                }
                printf("\n");
                break;
            }
            case 3:
            {
                //3. Dar la longitud de las cadenas, sin incluir el NULL.
                printf("La longitud de la cadena 1 es de %i\n",l1);
                printf("La longitud de la cadena 2 es de %i\n",l2);
                break;
            }
            case 4:
            {
                //4. Copiar las dos cadenas, una después de la otra, mostrando el resultado por pantalla.
                for (i = 0; i < l1; i++)
                {
                    subcadena[i] = cadena1[i];
                }
                for (i = 0; i < l2; i++)
                {
                    subcadena[i+l1] = cadena2[i];
                }
                printf("%s\n",subcadena);
                printf("\n");
                break;
            }
            case 5:
            {
                //5. Buscar una cadena dentro de la otra y avisar por pantalla la posición de la 2da cadena donde empiezan a ser iguales.
                if (l1 > l2)
                {
                    pos = same(cadena1,cadena2);
                }
                else
                {
                    pos = same(cadena2,cadena1);
                }
                printf("La posicion en la que empiezan a ser iguales es la %i\n",pos);
                printf("\n");
                break;
            }
            case 6:
            {
                //6. Convertir la cadena todo a Minúsculas o Mayúsculas, según lo desee el usuario.
                printf("Ingrese 1 para pasar a mayusculas. Ingrese 2 para pasar a minusculas\n");
                scanf("%i",&Mm);
                if(Mm==1)
              {
                  mayusculas(cadena1);
                  printf("\n");
                  mayusculas(cadena2);
                  printf("\n");
              }
              else
              {
                  minusculas(cadena1);
                  printf("\n");
                  minusculas(cadena2);
                  printf("\n");
              }
              break;
            }
            case 7:
            {
                //7. Salir del programa. (el programa se repite hasta que se seleccione esta opción).
                loop = 1;
                printf("\n");
                break;
            }
        }
    }
    return 0;
}










