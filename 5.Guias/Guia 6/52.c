#include <stdio.h>
#include <stdlib.h>

int menu();
int longitud(const char* cad);
void copiar(char *cad1, char *cad2);
void sacarEnter(char cad[]);
void buscar(char *cad1, char *cad2);
void cambiar(char cad1[],char cad2[]);
void aminusc (char cad[]);
void amayusc(char cad[]);
void operar(int op,char cad[]);
void cambiar(char cad1[],char cad2[]);
void expando(char cad[]);
void agregar(char cad1[],char cad2[]);


int main(void)
{
    int loop = 0,respuesta,longitud1,longitud2, i = 0;
    char *cadena1;
    char *cadena2;
    char memoria1[100];
    char memoria2[100];
    
    while (loop == 0)
    {
        respuesta = menu();
        switch(respuesta)
        {
        case 1:
        { //Leer por teclado 2 cadenas de caracteres.
            printf("Ingrese cadena 1: ");
            fflush(stdin);
            fgets(memoria1,100,stdin);
            printf("Ingrese cadena 2: ");
            fflush(stdin);
            fgets(memoria2,100,stdin);
            longitud1 = longitud(memoria1);
            longitud2 = longitud(memoria2);
            cadena1 = (char*)malloc(longitud1);
            cadena2 = (char*)malloc(longitud2);
            for (i = 0; i < longitud1; i++)
                cadena1[i] = memoria1[i];
            for (i = 0; i < longitud2; i++)
                cadena2[i] = memoria2[i];
            break;
        }
        case 2:
        { //Imprimirlas cada cadena del derecho y al revés.
            printf("La Cadena 1 al derecho:\n%s\n",cadena1);
            printf("La cadena 1 al reves: \t");
            for (i = longitud1-1; i >= 0 ; i--)
            {
                printf("%c",cadena1[i]);
            }
            printf("\n");
            printf("La Cadena 2 al derecho:\n%s\n",cadena2);
            printf("La cadena 2 al reves: \t");
            for (i = longitud2-1; i >= 0 ; i--)
            {
                printf("%c",cadena2[i]);
            }
            printf("\n");
            break;
        }
        case 3:
        { //Dar la longitud de las cadenas, sin incluir el NULL
            printf("Longitud de la cadena 1: %d\n",longitud1);
            printf("Longitud de la cadena 2: %d\n",longitud2);
            break;
        }
        case 4:
        { //Copiar las dos cadenas, una después de la otra, mostrando el resultado por pantalla.
            copiar(cadena1,cadena2);
            break;
        }
        case 5:
        { //Buscar una cadena dentro de la otra y avisar por pantalla la posición de la 2da cadena donde empiezan a ser iguales.
            if(longitud1 >= longitud2)
                    buscar(cadena2, cadena1);
                else
                    buscar(cadena1, cadena2);
            break;
        }
        case 6:
        { //Convertir la cadena todo a Minúsculas o Mayúsculas
            cambiar(cadena1,cadena2);
            break;
        }
        case 7:
        { //Agregar a una Cadena otra cadena nueva leída por teclado
            agregar(cadena1,cadena2);
            break;
        }
        case 8:
        { ////8. Salir del programa.\n
            loop = 1;
            break;
        }
        }
    }
    free(cadena1);
    free(cadena2);
    return (0);
}

int menu()
{   
    int opcion = 0;
    printf("1. Leer por teclado 2 cadenas de caracteres.\n""2. Imprimirlas cada cadena del derecho y al revés.\n""3. Dar la longitud de las cadenas, sin incluir el NULL.\n""4. Copiar las dos cadenas, una después de la otra, mostrando el resultado por pantalla.\n""5. Buscar una cadena dentro de la otra y avisar por pantalla la posición de la 2da cadena donde empiezan a ser iguales.\n""6. Convertir la cadena todo a Minúsculas o Mayúsculas\n""7. Agregar a una Cadena otra cadena nueva leída por teclado.\n""8. Salir del programa.\n");
    scanf("%i",&opcion);
    while(opcion < 1 || opcion > 8)
    {
        printf("1. Leer por teclado 2 cadenas de caracteres.\n""2. Imprimirlas cada cadena del derecho y al revés.\n""3. Dar la longitud de las cadenas, sin incluir el NULL.\n""4. Copiar las dos cadenas, una después de la otra, mostrando el resultado por pantalla.\n""5. Buscar una cadena dentro de la otra y avisar por pantalla la posición de la 2da cadena donde empiezan a ser iguales.\n""6. Convertir la cadena todo a Minúsculas o Mayúsculas\n""7. Agregar a una Cadena otra cadena nueva leída por teclado.\n""8. Salir del programa.\n");
        scanf("%i",&opcion);
    }
    return opcion;
};

int longitud(const char* cad)
{
    int cant = 0;
    while(cad[cant])
        cant++;
    return cant;
};

void sacarEnter(char cad[])
{
    while (*cad){
        if (*cad == "\n")
            cad="\0";
        else
            *cad++;
    }
};

void copiar(char *cad1, char *cad2)
{
    sacarEnter(cad1);
    printf("%s%s",cad1,cad2);
    return;
};

void buscar(char *cad1, char *cad2)
{
    int n;
    int cont1,cont2,flag,flag1;
    sacarEnter(cad1);
    n = longitud(cad1);
    for (cont1=0 ;cont1<=longitud(cad2)-n ;cont1++)
    {
        flag = 1;
        for(cont2 = 0;cont2 < n; cont2++)
        {
            if(cad1[cont2] != cad2[cont1 + cont2])
                flag = 0;
        }
        if(flag==1) {
            printf("La cadena mas corta se encontro en la mas larga en la posicion %i\n", cont1 + 1);
            flag1 = 1;
        }
    }
    if(flag1==0) puts("No se encontro la cadena");
    return;
};

void cambiar(char cad1[],char cad2[])
{
    int op1,op2;
    puts("1. A mayusculas\n2. A minusculas\n");
    printf("Cadena 1: ");
    scanf("%i",&op1);
    printf("Resultado: ");
    operar(op1,cad1);
    printf("Cadena 2: ");
    scanf("%i",&op2);
    printf("Resultado: ");
    operar(op2,cad2);
    return;
};

void expando(char cad[])
{
    char *newcad;
    char memoriaNewCad[100];
    int c,l,i;
    printf("Ingrese la nueva cadena: ");
    fflush(stdin);
    fgets(memoriaNewCad,100,stdin);
    l = longitud(memoriaNewCad);
    for (i = 0; i < l; i++)
        newcad[i] = memoriaNewCad[i];
    sacarEnter(newcad);
    sacarEnter(cad);
    l=longitud(cad);
    cad = (char*) realloc(cad,(l+longitud(newcad)+1)*sizeof(char));
    for (c=l;c<l+longitud(newcad);c++) cad[c]=newcad[c-l];
    printf("Resultado: %s\n",cad);
};

void amayusc (char cad[])
{
    int c = 0;
    while (cad[c])
    {
        if (cad[c]>='a'&& cad[c]<='z') cad[c]=cad[c]+'A'-'a';
        c+=1;
    }
    printf ("%s\n",cad);
    return;
}

void aminusc (char cad[])
{
    int c = 0;
    while (cad[c])
    {
        if (cad[c]>='A'&& cad[c]<='Z') cad[c]=cad[c]+'a'-'A';
        c+=1;
    }
    printf ("%s\n",cad);
    return;
}

void operar(int op,char cad[])
{
    switch (op)
    {
        case 1:
            amayusc(cad);
            break;
        case 2:
            aminusc(cad);
            break;
    }
    return;
}

void agregar(char cad1[],char cad2[])
{
    int op;
    printf("1. Agregar a la cadena 1\n2. Agregar a la cadena 2\n");
    scanf("%i",&op);
    switch (op)
    {
        case 1:
            expando(cad1);
            break;
        case 2:
            expando(cad2);
            break;
    }
    return;
}
