#include <stdio.h>
#include "librerias/listas.h"
#include <time.h>
#include "stdlib.h"
#include "string.h"

#define MAX_LEN 50
#define TOT_HORAS 9

typedef struct{
    int codigo;
    float precio;
    char descripcion[MAX_LEN];
    float totalVendido;
}Producto;

//Prototipo de funciones
int cantidadLineas(FILE *);
void leerProductos(FILE *pf, Producto array[], int cantProd);
void leerVendedores(FILE *pf, Lista *ptrlista, int *cantVend);
void simularVentas(Producto arrayProductos[], Lista listaVendedores, int cp, int cv, int matriz[TOT_HORAS][2]);
Nodo * obtenerNodo(Lista lst, int vendedorElegido);
void ordenarTotalVendido(Producto arrayProductos[], int cantProd);
float totalVendidoProd(Producto array[], int cantProd);
float totalVendidoVend(Lista lista);
void cortarCadena(char cad[]);

int main(void)
{
    int i, matrizHoraClientes[TOT_HORAS][2] = {{13,60},{14,100},{15,100},{16,60},{17,40},{18,100},{19,120},{20,80},{21,40}};
    int cantProd, cantVend = 0;
    Producto *arrayProductos;
    Lista listaVendedores = NULL; //Lista de vendedores
    FILE *pfProductos, *pfEmpleados;

    srand(time(NULL));

    //LECTURA DE PRODUCTOS
    pfProductos = fopen("/Users/candefagnani/Desktop/Resolucion Adian 1.2/productos.txt","rt");
    if(pfProductos != NULL)
    {
        cantProd = cantidadLineas(pfProductos);
        arrayProductos = (Producto*) malloc(sizeof(Producto)*cantProd);
        if(arrayProductos == NULL)
        {
            printf("No se pudo reservar la memoria solicitada\n");
            exit(9);
        }
        else
        {
            leerProductos(pfProductos,arrayProductos,cantProd);
        }
    }

    //LECTURA DE EMPLEADOS
    pfEmpleados = fopen("/Users/candefagnani/Desktop/Resolucion Adian 1.2/empleados.txt","rt");
    if(pfEmpleados != NULL)
    {
        leerVendedores(pfEmpleados, &listaVendedores, &cantVend);
        //funciones que cambian la lista les paso el puntero
        //funciones que o buscan o leen elementos no les paso el puntero
    }
    simularVentas(arrayProductos,listaVendedores,cantProd,cantVend,matrizHoraClientes);

    printf("VENTAS POR VENDEDORES:\n");
    printf("Nombre\tCant. Vend.\tTot. Fact.\tTot. Comision\n");
    mostrarLista(listaVendedores);
    puts("\n");
    printf("VENTAS POR PRODUCTOS:\n");
    ordenarTotalVendido(arrayProductos, cantProd);
    printf("Nombre\t\tTot. Vendido\n");
    for(i = 0; i < cantProd; i++)
    {
        printf("Producto %s\t $%f\n",arrayProductos[i].descripcion,arrayProductos[i].totalVendido);
    }

    printf("\nTotal vendido segun productos: $%f\n", totalVendidoProd(arrayProductos,cantProd));
    printf("Total vendido segun vendedores: $%f\n",totalVendidoVend(listaVendedores));

    fclose(pfProductos);
    fclose(pfEmpleados);

    free(arrayProductos);
    return 0;
}

int cantidadLineas(FILE * f)
{
    int cantLineas = 0;
    char linea[500];
    fgets(linea,500,f);
    while(!feof(f))
    {
        cantLineas++;
        fgets(linea,500,f);
    }
    rewind(f); //vuelve al comienzo del archivo
              //Va a volver a la posicion inicial
    return cantLineas;
}

void leerProductos(FILE *pf, Producto array[], int cantProd)
{
    int i = 0;
    fseek(pf,0,SEEK_SET);
    for(i = 0; i < cantProd; i++)
    {
        fscanf(pf,"%d",&array[i].codigo);
        fgetc(pf); //Me Deshago de la coma
        fscanf(pf, "%f", &array[i].precio); //Tomo el precio del producto
        fgetc(pf); //Me Deshago de la coma
        fgets(array[i].descripcion, 50, pf); //Tomo el nombre del producto
        cortarCadena(array[i].descripcion);
        array[i].totalVendido = 0;
    }
}

void cortarCadena(char cad[])
{
    int i = 0;
    for(i = 0; i < strlen(cad); i++)
    {
        if (cad[i] == ' ' && cad[i+1] == ' ')
            cad[i] = '\0';
    }
}

void leerVendedores(FILE *pf, Lista *ptrlista, int *cantVend)
{
    int i = 0;
    dato vendedorX;
    fseek(pf, 0, SEEK_SET);
    fscanf(pf,"%d %f ",&vendedorX.numeroVendedor,&vendedorX.comisionVendedor);
    while(!feof(pf))
    {
        vendedorX.comisionVendedor = vendedorX.comisionVendedor/100.0;
        fgets(vendedorX.nombreVendedor,MAX_LEN,pf);
        vendedorX.totalComision = 0;
        vendedorX.CantproductosVendidos = 0;
        vendedorX.totalFacturado = 0;
        insertar(ptrlista,vendedorX);
        i++; //indico que inserto un elemento en la lista
        fscanf(pf,"%d %f ",&vendedorX.numeroVendedor,&vendedorX.comisionVendedor);
    }
    *cantVend = i;
}

void simularVentas(Producto arrayProductos[], Lista listaVendedores, int cp, int cv, int matriz[TOT_HORAS][2])
{
    int i, cliente, productoElegido, vendedorElegido;
    float precioElegido, comisionElegida;
    Nodo * nodoVendedor;

    for(i=0;i<TOT_HORAS;i++)
    {
        for(cliente=0;cliente<matriz[i][1];cliente++)
        {
            //limInf + random()%(limsup-liminf+1)
            productoElegido = random()%cp;
            if(productoElegido != -1)
            {
                vendedorElegido = 1 + random()%cv;

                nodoVendedor = obtenerNodo(listaVendedores, vendedorElegido);

                precioElegido = arrayProductos[productoElegido].precio;
                comisionElegida = nodoVendedor->d.comisionVendedor;
                arrayProductos[productoElegido].totalVendido += precioElegido;
                nodoVendedor->d.CantproductosVendidos += 1;
                nodoVendedor->d.totalFacturado += precioElegido;
                nodoVendedor->d.totalComision += precioElegido*comisionElegida;
            }
        }
    }
}

Nodo * obtenerNodo(Lista lst, int vendedorElegido)
{
    Lista aux;
    aux = lst;
    while(aux != NULL)
    {
        if(aux->d.numeroVendedor == vendedorElegido)
            return aux; //devuelvo el nodo en donde encontre los datos cuyo numero es igual al numero elegido
        aux = aux->sig;
    }
}

void ordenarTotalVendido(Producto arrayProductos[], int cantProd)
{
    int i, j;
    Producto aux;
    for(i = 0; i < cantProd-1; i++)
    {
        for(j = i; j < cantProd; j++)
        {
            if(arrayProductos[i].totalVendido < arrayProductos[j].totalVendido)
            {
                aux = arrayProductos[j];
                arrayProductos[j] = arrayProductos[i];
                arrayProductos[i] = aux;
            }
        }
    }
}

float totalVendidoProd(Producto array[], int cantProd)
{
    int i;
    float acumulador = 0;
    for(i = 0;i < cantProd; i++)
    {
        acumulador += array[i].totalVendido;
    }
    return acumulador;
}

float totalVendidoVend(Lista lista)
{
    Lista aux;
    aux = lista;
    float acumulador;
    while(aux != NULL)
    {
        acumulador += aux->d.totalFacturado;
        aux = aux->sig;
    }
    return acumulador;
}
