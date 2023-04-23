#include <stdio.h>
#include <stdlib.h>

//FUNCIONES AUXILIARES//
int menu();
char leer(char *cad);
int len(char *cad);
void sacarEnter(char *cad);
void reves(char *cad);
void copiar(char *cad1, char *cad2);
void buscar(char *cad1, char *cad2);
void aminusc (char cad[]);
void amayusc(char cad[]);
void operar(int op,char cad[]);
void cambiar(char cad1[],char cad2[]);
void expando(char cad[]);
void agregar(char cad1[],char cad2[]);



//FUNCION PRINCIPAL//
void main()
{
    int opcion;
    char *cad1, *cad2;

    opcion = menu();
    while(opcion!=8)
    {
        switch(opcion)
        {
            case 1:
                cad1 = leer(cad1);
                cad2 = leer(cad2);
                break;
            case 2:
               printf("Cadena 1:\t %s\n",cad1);
               printf("Cadena 1 de reves:\t");
               reves(cad1);
               printf("Cadena 2:\t%s\n",cad2);
               printf("Cadena 2 de reves:\t");
               reves(cad2);
               break;
            case 3:
                printf("Longitud de cadena 1: %i\n",len(cad1));
                printf("Longitud de cadena 2: %i\n",len(cad2));
                break;
            case 4:
               copiar(cad1, cad2);
               break;
            case 5:
                if(len(cad1)>=len(cad2))
                    buscar(cad2, cad1);
                else
                    buscar(cad1, cad2);
                break;
            case 6:
                cambiar(cad1,cad2);
                break;
            case 7:
                agregar(cad1,cad2);
                break;
        }
        opcion = menu();
    }
    free(cad1);
    free(cad2);
}


int menu()
{
    int op;
    puts("MENU:");
    puts("1. Leer por teclado 2 cadenas de caracteres.");
    puts("2. Imprimirlas cada cadena del derecho y al revés.");
    puts("3. Dar la longitud de las cadenas, sin incluir el NULL.");
    puts("4. Copiar las dos cadenas, una después de la otra, mostrando el resultado por pantalla.");
    puts("5. Buscar una cadena dentro de la otra y avisar por pantalla la posición de la 2da cadena donde empiezan a ser iguales.");
    puts("6. Convertir la cadena todo a Minúsculas o Mayúsculas, según lo desee el usuario.");
    puts("7. Agregar a una Cadena otra cadena nueva leída por teclado.");
    puts("8. Salir del programa.");
    scanf("%i",&op);
    return(op);
}

char leer(char *cad)
{
    int c;
    char buffer[100];
    puts("Ingresar cadena: ");
    fflush(stdin);
    fgets(buffer,100,stdin);
    cad = (char*) malloc(sizeof(char)*(len(buffer)+1));
    for(c=0;c<len(buffer);c++)
        cad[c] = buffer[c];
    cad[c] = '\0';
    return (cad);
}

int len(char *cad)
{
    int c=0;
    while (cad[c])
        c+=1;
    return(c);
}

void sacarEnter(char *cad)
{
    int l=0;
    while (cad[l])
    {
        l+=1;
        if (cad[l]=='\n')
            cad[l]='\0';
    }
    return;
}

void reves(char *cad)
{
    int n;
    for (n=len(cad);n>0;n--)
        printf("%c",cad[n-1]);
    puts("");
    return;
}

void copiar(char *cad1, char *cad2)
{
    sacarEnter(cad1);
    printf("%s%s",cad1,cad2);
    return;
}

void buscar(char *cad1, char *cad2)
{
    int n;
    int cont1,cont2,flag,flag1;
    sacarEnter(cad1);
    n = len(cad1);
    for (cont1=0 ;cont1<=len(cad2)-n ;cont1++)
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
}

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
}

void expando(char cad[])
{
    char *newcad;
    int c,l;

    newcad = leer (newcad);
    sacarEnter(newcad);
    sacarEnter(cad);
    l=len(cad);
    cad = (char*) realloc(cad,(l+len(newcad)+1)*sizeof(char));
    for (c=l;c<l+len(newcad);c++) cad[c]=newcad[c-l];
    printf("Resultado: %s\n",cad);
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