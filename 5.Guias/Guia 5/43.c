//43. Ingresar 10 números reales y almacenarlos en el archivo reales.dat y 
//verificar que el archivo contiene (10*sizeof(float)) bytes.*
//45. Leer el archivo reales.dat e informar el producto de los que se hallan en las posiciones 1,3,5,7,9.
//46. Leer el archivo reales.dat , cambiar los números de las posiciones 2, 4 y 8; 
//luego listar el vector modificado, y grabarlo con el nombre reales2.dat.

#include<stdio.h>
#include<stdlib.h>

void main()
{
    int maximo=10,i;
    float vector[10];
    char archivo[] = "reales.dat";
    FILE* pf;
    pf =fopen(archivo,"wt");
    if(pf==NULL)
    {
        puts("Error al abrir archivo \n");
    }
    else
    {
        puts("El archivo se abrio correctamente");
        for(i=0;i<10;i++)
        {
            printf("Imgrese un numero: ");
            scanf("%f",&vector[i]);
        }
    }
    fwrite(vector,sizeof(float),10,pf);
    fclose(pf);
    pf = fopen(archivo,"rt");
    if(pf==NULL)
    {
        puts("Error al abrir archivo");
    }
    else
    {
        puts("El archivo se abrio correctamente");
        fread(vector,sizeof(float),10,pf);
        for(i=0;i<10;i++)
        {
            printf("El numero [%i]: %.2f\n",i,vector[i]);
        }
    }
    fclose(pf);
    pf = fopen("reales.dat","r");
    fseek(pf,0,SEEK_END);
    printf("reales.dat ocupa %i bytes",ftell(pf));
    fclose(pf);
    return;
}