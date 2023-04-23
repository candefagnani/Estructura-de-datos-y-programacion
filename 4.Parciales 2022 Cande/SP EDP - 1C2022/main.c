#include <stdio.h>
#include "string.h"
#include "time.h"
#include <stdlib.h>
#include "librerias/listas.h"

int obtenerCantRegistros(FILE * fbin);
int longitud(char cad[]);
void cargalista(FILE *fbin, Lista *empleados, int *cantRegistros);
void simulacion(Lista * empleados, int cantRegistros);
void punto2(Lista empleados);
void punto3y4(Lista empleados);
void cortarCadena(char cad[]);
char * minusculas(char cadena[]);
char * mayusculas(char cadena[]);
void punto5(Lista empleados);
float calculaSueldo(Lista * empleados);

int main(void)
{
    int cantRegistros = 0;
    Lista empleados = NULL;

    FILE * fbin = fopen("/Users/candefagnani/Desktop/parcial/empleados.bin","rb");
    if(fbin == NULL)
        printf("El archivo no pudo ser abierto\n");
    else
    {
        printf("Se pudo abrir\n");
        cargalista(fbin, &empleados, &cantRegistros);
        printf("La lista de empleados es:\n");
        mostrarLista(empleados);
    }
    fclose(fbin);

    //Punto 1
    //simulacion(&empleados, cantRegistros);
    //tengo un prblema en la simulacion

    //Punto 2
    punto2(empleados);

    //Punto 3 y 4
    punto3y4(empleados);

    //Punto 5
    punto5(empleados);
    return 0;
}

int obtenerCantRegistros(FILE * fbin)
{
    int ncant, cantRegistros;
    int offsetActual;
    //0.Antes de hacer algo, tomo la posicion actual de donde me encuentro en el archivo
    offsetActual = ftell(fbin);
    //1. Me voy al final del archivo
    fseek(fbin, 0, SEEK_END);
    //2.Tomo el tamano que tiene el archivo (con ftell que me da el numero de byte donde me encuentro parado)
    ncant = ftell(fbin);
    //3.Calcular la cantidad de registros
    cantRegistros = ncant / sizeof (dato);
    //4.Restauro la posicion donde me encontraba
    fseek(fbin, offsetActual, SEEK_SET);
    return cantRegistros;
}

int longitud(char cad[])
{
    int cant=0;
    while (cad[cant])
        cant++;
    return cant;
}

void cargalista(FILE *fbin, Lista *empleados, int *cantRegistros)
{
    int i, j;
    (*cantRegistros) = obtenerCantRegistros(fbin);
    j = (*cantRegistros);
    dato unEmpleado;
    rewind(fbin);
    printf("%d\n",j);
    for (i = 0;i < j; i++)
    {
        fread(&unEmpleado,sizeof(dato),1,fbin);
        insertar(empleados,unEmpleado);
    }
}

float calculaSueldo(Lista * empleados)
{
    float sueldoOrg = 0;
    Nodo *aux = *empleados;
    while(aux != NULL)
    {
        sueldoOrg += aux->d.sueldo;
        aux = aux->sig;
    }
    return sueldoOrg;
}

void simulacion(Lista * empleados, int cantRegistros)
{
    float porcentaje;
    float sueldoOrg = 0;
    float sueldoAct = 0;
    int i;
    Nodo * aux = *empleados;
    //FILE * fbin = fopen("/Users/candefagnani/Desktop/parcial/empleados.bin","w+b");

    printf("Ingrese el porcentaje de aumento: ");
    scanf("%f",&porcentaje);

    while (aux != NULL)
    {
        /*
         sueldo -> 100%
         (aumento*sueldo)/100 -> aumento
         sueldoNuevo = sueldo + (aumento*100)/sueldo)
         (aux->d.sueldo + ((aux->d.sueldo *porcentaje)/100))
         */
        sueldoOrg += aux->d.sueldo;
        aux->d.sueldo += ((aux->d.sueldo *porcentaje)/100);
        sueldoAct += aux->d.sueldo;

        /*
        if(fbin != NULL)
        {
            for(i = 0; i < cantRegistros; i++)
            {
                fwrite(&aux->d,sizeof(dato),1,fbin);
            }
        }
         */
        aux = aux->sig;
    }
    printf("Lo que paga ahora la empresa es de %.2f\n",sueldoOrg);
    printf("Lo que paga ahora la empresa es de %.2f\n",sueldoAct);
    //fclose(fbin);
}

void punto2(Lista empleados)
{
    int A = 0, B = 0, C = 0, D = 0;
    float sueldoA, sueldoB, sueldoC, sueldoD;
    Nodo *aux = empleados;
    while(aux != NULL)
    {
        if(aux->d.categoria == 'A')
        {
            A++;
            sueldoA += aux->d.sueldo;
        }
        else if(aux->d.categoria == 'B')
        {
            B++;
            sueldoB += aux->d.sueldo;
        }
        else if(aux->d.categoria == 'C')
        {
            C++;
            sueldoC += aux->d.sueldo;
        }
        else
        {
            D++;
            sueldoD += aux->d.sueldo;
        }
        aux = aux->sig;
    }
    printf("La cantidad de empleados en la categoría A es de: %d y el promedio del sueldo es de %.2f\n",A,sueldoA/A);
    printf("La cantidad de empleados en la categoría B es de: %d y el promedio del sueldo es de %.2f\n",B,sueldoA/B);
    printf("La cantidad de empleados en la categoría C es de: %d y el promedio del sueldo es de %.2f\n",C,sueldoA/C);
    printf("La cantidad de empleados en la categoría D es de: %d y el promedio del sueldo es de %.2f\n",D,sueldoA/D);
}

void cortarCadena(char cad[])
{
    int i = 0;
    for(i = 0; i < longitud(cad); i++)
    {
        if (cad[i] == ' ' && cad[i+1] == ' ')
            cad[i] = '\0';
    }
}

char * minusculas(char cadena[])
{
    int i;
    for (i = 0; i < longitud(cadena); i++)
    {
        if (cadena[i]>='A' && cadena[i]<='Z')
            cadena[i] = cadena[i] + 32;
    }
    return cadena;
}

char * mayusculas(char cadena[])
{
    int i;
    for (i = 0; i < longitud(cadena); i++)
    {
        if (cadena[i]>='a' && cadena[i]<='z')
            cadena[i] = cadena[i] - 32;
    }
    return cadena;
}

void punto3y4(Lista empleados)
{
    int A = 0, B = 0, C = 0, D = 0;
    float sueldoMaxA, sueldoMinA, sueldoMaxB, sueldoMinB, sueldoMaxC, sueldoMinC, sueldoMaxD, sueldoMinD;
    char NombreMaxA[51], NombreMinA[51], NombreMaxB[51], NombreMinB[51], NombreMaxC[51], NombreMinC[51], NombreMaxD[51], NombreMinD[51];
    Nodo *aux = empleados;
    while(aux != NULL)
    {
        if(aux->d.categoria == 'A')
        {
            A++;
            if(A == 1)
            {
                sueldoMaxA = aux->d.sueldo;
                strcpy(NombreMaxA,aux->d.empleado);
                sueldoMinA = aux->d.sueldo;
                strcpy(NombreMinA,aux->d.empleado);
            }
            else
            {
                if(aux->d.sueldo > sueldoMaxA)
                {
                    sueldoMaxA = aux->d.sueldo;
                    strcpy(NombreMaxA,aux->d.empleado);
                }
                if(aux->d.sueldo < sueldoMinA)
                {
                    sueldoMinA = aux->d.sueldo;
                    strcpy(NombreMinA,aux->d.empleado);
                }
            }

        }
        if(aux->d.categoria == 'B')
        {
            B++;
            if(B == 1)
            {
                sueldoMaxB = aux->d.sueldo;
                strcpy(NombreMaxB,aux->d.empleado);
                sueldoMinB = aux->d.sueldo;
                strcpy(NombreMinB,aux->d.empleado);
            }
            else
            {
                if(aux->d.sueldo > sueldoMaxB)
                {
                    sueldoMaxB = aux->d.sueldo;
                    strcpy(NombreMaxB,aux->d.empleado);
                }
                if(aux->d.sueldo < sueldoMinB)
                {
                    sueldoMinB = aux->d.sueldo;
                    strcpy(NombreMinB,aux->d.empleado);
                }
            }

        }
        if(aux->d.categoria == 'C')
        {
            C++;
            if(C == 1)
            {
                sueldoMaxC = aux->d.sueldo;
                strcpy(NombreMaxC,aux->d.empleado);
                sueldoMinC = aux->d.sueldo;
                strcpy(NombreMinC,aux->d.empleado);
            }
            else
            {
                if(aux->d.sueldo > sueldoMaxC)
                {
                    sueldoMaxC = aux->d.sueldo;
                    strcpy(NombreMaxC,aux->d.empleado);
                }
                if(aux->d.sueldo < sueldoMinC)
                {
                    sueldoMinC = aux->d.sueldo;
                    strcpy(NombreMinC,aux->d.empleado);
                }
            }

        }
        if(aux->d.categoria == 'D')
        {
            D++;
            if(D == 1)
            {
                sueldoMaxD = aux->d.sueldo;
                strcpy(NombreMaxD,aux->d.empleado);
                sueldoMinD = aux->d.sueldo;
                strcpy(NombreMinD,aux->d.empleado);
            }
            else
            {
                if(aux->d.sueldo > sueldoMaxD)
                {
                    sueldoMaxD = aux->d.sueldo;
                    strcpy(NombreMaxD,aux->d.empleado);
                }
                else if(aux->d.sueldo < sueldoMinD)
                {
                    sueldoMinD = aux->d.sueldo;
                    strcpy(NombreMinD,aux->d.empleado);
                }
            }

        }
        aux = aux->sig;
    }
    cortarCadena(NombreMaxA);
    mayusculas(NombreMaxA);
    cortarCadena(NombreMinA);
    minusculas(NombreMinA);

    cortarCadena(NombreMaxB);
    mayusculas(NombreMaxB);
    cortarCadena(NombreMinB);
    minusculas(NombreMinB);

    cortarCadena(NombreMaxC);
    mayusculas(NombreMaxC);
    cortarCadena(NombreMinC);
    minusculas(NombreMinC);

    cortarCadena(NombreMaxD);
    mayusculas(NombreMaxD);
    cortarCadena(NombreMinD);
    minusculas(NombreMinD);

    printf("Categoria A el sueldo maximo lo tiene %s y es de %.2f\n",NombreMaxA,sueldoMaxA);
    printf("Categoria A el sueldo minimo lo tiene %s y es de %.2fs\n",NombreMinA,sueldoMinA);
    printf("Categoria B el sueldo maximo lo tiene %s y es de %.2f\n",NombreMaxB,sueldoMaxB);
    printf("Categoria B el sueldo minimo lo tiene %s y es de %.2fs\n",NombreMinB,sueldoMinB);
    printf("Categoria C el sueldo maximo lo tiene %s y es de %.2f\n",NombreMaxC,sueldoMaxC);
    printf("Categoria C el sueldo minimo lo tiene %s y es de %.2fs\n",NombreMinC,sueldoMinC);
    printf("Categoria D el sueldo maximo lo tiene %s y es de %.2f\n",NombreMaxD,sueldoMaxD);
    printf("Categoria D el sueldo minimo lo tiene %s y es de %.2fs\n",NombreMinD,sueldoMinD);

    printf("\n");
    printf("Punto 4...\n");
    if(sueldoMaxA > (4*sueldoMinA))
    {/*
         sueldoMax - SueldoMin > 3SueldoMin
         sueldoMax > 3SueldoMin + sueldoMin
         sueldoMax > 4SueldoMin
         */
        printf("En la categoría A la diferencia entre el sueldo máximo y mínimo sea mayor a tres veces el sueldo mínimo: %.2f + %.2f > %.2f\n", sueldoMaxA, sueldoMinA, (3*sueldoMinA));
    }
    if(sueldoMaxB > (4*sueldoMinB))
    {
        printf("En la categoría B la diferencia entre el sueldo máximo y mínimo sea mayor a tres veces el sueldo mínimo: %.2f + %.2f > %.2f\n", sueldoMaxB, sueldoMinB, (3*sueldoMinB));
    }
    if(sueldoMaxC > (4*sueldoMinC))
    {
        printf("En la categoría C la diferencia entre el sueldo máximo y mínimo sea mayor a tres veces el sueldo mínimo: %.2f + %.2f > %.2f\n", sueldoMaxC, sueldoMinC, (3*sueldoMinC));
    }
    if(sueldoMaxD > (4*sueldoMinD))
    {
        printf("En la categoría D la diferencia entre el sueldo máximo y mínimo sea mayor a tres veces el sueldo mínimo: %.2f + %.2f > %.2f\n", sueldoMaxD, sueldoMinD, (3*sueldoMinD));
    }

}

void punto5(Lista empleados)
{
    FILE * categoría_A = fopen("/Users/candefagnani/Desktop/parcial/categoría_A.txt","wt");
    FILE * categoría_B = fopen("/Users/candefagnani/Desktop/parcial/categoría_B.txt","wt");
    FILE * categoría_C = fopen("/Users/candefagnani/Desktop/parcial/categoría_C.txt","wt");
    FILE * categoría_D = fopen("/Users/candefagnani/Desktop/parcial/categoría_D.txt","wt");

    if(empleados == NULL)
        return;

    Lista aux = empleados;
    while(aux != NULL)
    {
        if(aux->d.categoria == 'A')
        {
            if(categoría_A != NULL)
            {
                cortarCadena(aux->d.empleado);
                fprintf(categoría_A,"%s;%.2f\n", mayusculas(aux->d.empleado),aux->d.sueldo);
            }
        }
        if(aux->d.categoria == 'B')
        {
            if(categoría_B != NULL)
            {
                cortarCadena(aux->d.empleado);
                fprintf(categoría_B,"%s;%.2f\n", mayusculas(aux->d.empleado),aux->d.sueldo);
            }
        }
        if(aux->d.categoria == 'C')
        {
            if(categoría_C != NULL)
            {
                cortarCadena(aux->d.empleado);
                fprintf(categoría_C,"%s;%.2f\n", mayusculas(aux->d.empleado),aux->d.sueldo);
            }
        }
        if(aux->d.categoria == 'D')
        {
            if(categoría_D != NULL)
            {
                cortarCadena(aux->d.empleado);
                fprintf(categoría_D,"%s;%.2f\n", mayusculas(aux->d.empleado),aux->d.sueldo);
            }
        }
        aux = aux->sig;
    }
    fclose(categoría_A);
    fclose(categoría_B);
    fclose(categoría_C);
    fclose(categoría_D);
}