#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int same(char Larga[], char Corta[]);

int main(void)
{
    char parrafo[200], buscar[20], reemplazo[20], subcadena[200],resto[200];
    int b,pos,i;
    for (b=0; buscar[b]!='\0'; b++);
    printf("Empezemos por el texto\n");
    gets(parrafo);
    printf("Palabra a reemplazar\n");
    gets(buscar);
    printf("Lo reemplazamos con: ");
    gets(reemplazo);
    pos=same(parrafo, buscar);

    if(strlen(buscar) == strlen(reemplazo))
    //Aca la palabra buscar tiene la misma cantidad de letras que la palabra reemplazo
    {
        for(i = 0, b = pos; parrafo[b]; b++, i++)
        {
            if (reemplazo[i]) 
                parrafo[b]=reemplazo[i];
            else 
                break;
        }
        printf("%s", parrafo);
    }
    else if(strlen(reemplazo) < strlen(buscar)) 
    //Aca la palabra buscar es mas larga que la palabra reemplazo, hay que "eliminar" caracteres
    {
        for (i = 0; i < pos; i++)
        {
            subcadena[i] = parrafo[i];
        }
        for (i = 0; i <  strlen(reemplazo); i++)
        {
            subcadena[i+pos] = reemplazo[i];
        }  
        for (i = (pos+strlen(reemplazo)) ; i < strlen(parrafo); i++)
        {
            subcadena[i] = parrafo[i+(strlen(buscar)-strlen(reemplazo))];
        }
        printf("%s",subcadena);
    }
    else if (strlen(reemplazo) > strlen(buscar)) 
    //Aca la palabra reemplazo es mas larga que la palabra buscar, hay que "añadir" caracteres
    {
        for (i = 0; i < pos; i++ )
        {
            subcadena[i] = parrafo[i];
        }
        for(i = 0; i < strlen(reemplazo); i++)
        {
            subcadena[i+pos] = reemplazo[i];
        }
        for (i = 0; i < strlen(parrafo); i++)
        {
            resto[i] = parrafo[i+pos+strlen(buscar)];
        }
        for (i = 0; i < strlen(parrafo)+(strlen(reemplazo)-strlen(buscar)); i++)
        {
            subcadena[i+pos+strlen(reemplazo)] = resto[i];
        }
        printf("%s",subcadena);
    }
    printf("\n");
    return 0;
}

int same(char Larga[], char Corta[])
{
    int l1, l2, Hit=0, i, j, pos=0;
    l1=strlen(Larga);     l2=strlen(Corta);
    for(i=0;i<=l1;i++)
        {
         if (Larga[i]==Corta[0])
          {   pos=i;
              for(j=0;j<l2;j++, i++)
                if (Larga[i]==Corta[j]) Hit=1;
                else {Hit=0; break;}
          }
         if (Hit) break;
        }
    if (Hit) return pos;
    else return -1;
}
