#include <stdio.h>
#include "librerias/listas.h"
#include <stdlib.h>
#include <time.h>
#include "string.h"
#define VENDEDORES 5
#define VENTAS 100

typedef struct
{
    int codigo;
    int cantVendida;
}vendedor;

int contarLineas(FILE * ftxt);
Lista cargaProductos(FILE * fprod);
void copiarcadena(char *destino, char *origen, int i);
void agregaDato(Lista *productos, int *cantProd);
void modificarArchivo (Lista productos);
void ModificaDato(Lista * productos,int cantProd);
void cargarVendedores(vendedor *VectorVendedores);
void simularVentas(Lista * productos, vendedor *VectorVendedores, int cantProd);
void ordenar(vendedor vec[]);
void mostrarElemento2(dato unDato);

int main(void)
{
    srand(time(NULL));
    int cantProd;
    int i;
    vendedor * VectorVendedores;
    int opcion = 0;
    Lista productos = NULL;
    FILE *fprod = fopen("/Users/candefagnani/Desktop/Practica 2P 20220606/precios.txt","rt");
    if(fprod == NULL)
        printf("No se pudo abrir el archivo\n");
    else
    {
        cantProd = contarLineas(fprod)+1;
        productos = cargaProductos(fprod);
        printf("La lista original de los productos de la tiendo:\n");
        mostrarLista(productos);
    }
    printf("Desea: \n1.Agregar un producto\n2.Modificar precio y descripcion de un producto\n3.Arrancar con la simulacion\n");
    scanf("%d",&opcion);
    while (opcion != 3)
    {
        if (opcion == 1)
        {
            agregaDato(&productos, &cantProd);
            modificarArchivo (productos);
        }
        else if(opcion == 2)
        {
            ModificaDato(&productos,cantProd);
            modificarArchivo(productos);
        }
        printf("Desea: \n1.Agregar un producto\n2.Modificar precio y descripcion de un producto\n3.Arrancar con la simulacion\n");
        scanf("%d",&opcion);
    }
    if (opcion == 3)
    {
        printf("Su lista de productos actualizada\n");
        mostrarLista(productos);
        printf("Se comienza con la simulacion\n");
        VectorVendedores = (vendedor *) malloc(sizeof(vendedor)*VENDEDORES);
        if(VectorVendedores == NULL)
        {
            printf("No se pudo reservar la memoria solicitada\n");
            exit(9);
        }
        else
        {
            cargarVendedores(VectorVendedores);
            simularVentas(&productos, VectorVendedores, cantProd);
        }
    }
    printf("Lista de vendedores ordenado descendientemente por el total vendido\n");
    ordenar(VectorVendedores);
    for (i = 0; i < VENDEDORES; i++)
        printf("Codigo: %d - Total Vendido: %d\n",VectorVendedores[i].codigo,VectorVendedores[i].cantVendida);
    printf("Lista de ventas de productos (descripción y total vendido) ordenado descendientemente por total vendido\n");
    ordenarLista(&productos);
    Lista aux;
    aux = productos;
    while(aux != NULL)
    {
        mostrarElemento2(aux->d);
        aux = aux->sig;
    }

    fclose(fprod);
    free(VectorVendedores);
    return 0;
}

int contarLineas(FILE * f)
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
    return cantLineas;
}

void copiarcadena(char *destino, char *origen, int i)
{
    char *start = destino;
    int j = 0;
    for (j = 0; j < i; j++)
    {
        *destino = *origen;
        destino++;
        origen++;
    }
    *destino = '\0';
}

Lista cargaProductos(FILE * fprod)
{
    int cantProductos = contarLineas(fprod) + 1;
    int j = 0, p = 0;
    Lista productos = NULL;
    dato unProducto;
    char linea[50];
    char precio[10];
    int i;
    for (i = 0; i < cantProductos; i++)
    {
        fscanf(fprod,"%d;",&unProducto.codigo);
        fgets(linea,50,fprod);
        while(linea[j] != ';'){
            j++;
        }
        copiarcadena(unProducto.descripcion,linea,j);
        j++;
        while(linea[j] != '\0')
        {
            precio[p] = linea[j];
            p++;
            j++;
        }
        sscanf(precio,"%d", &unProducto.precio);
        unProducto.totalvendido = 0;
        insertar(&productos,unProducto);
        j = 0;
        p = 0;
    }
    return productos;
}

void agregaDato(Lista *productos, int *cantProd)
{
    dato ProductoAgregado;
    int original, codigo;
    char nombre[50];
    original = *cantProd;
    codigo = original + 1;
    ProductoAgregado.codigo = codigo;
    printf("Ingrese el nombre de su nuevo producto:");
    fflush(stdin);
    gets(nombre);
    strcpy(ProductoAgregado.descripcion,nombre);
    printf("Ingrese el precio de su producto:");
    scanf("%d",&ProductoAgregado.precio);
    insertar(productos,ProductoAgregado);
    *cantProd = codigo;
    codigo = 0;
}

void modificarArchivo (Lista productos)
{
    FILE * fproductos;
    fproductos = fopen("/Users/candefagnani/Desktop/Practica 2P 20220606/precios.txt","w+t");
    if(fproductos == NULL)
        return;
    Lista aux = productos;
    while (aux != NULL)
    {
        fprintf(fproductos,"%d;%s;%d\n",aux->d.codigo,aux->d.descripcion,aux->d.precio);
        aux = aux->sig;
    }
    fclose(fproductos);
}

void ModificaDato(Lista * productos,int cantProd)
{
    int productoElegido = 0, precio = 0;
    char nombre[50];
    Nodo * nodoProducto;
    Lista aux = *productos;
    printf("Cual es el producto que desea modificar?");
    scanf("%d",&productoElegido);
    while(productoElegido < 1 || productoElegido > cantProd)
    {
        printf("El codigo del producto no existe\n");
        printf("Cual es el producto que desea modificar?");
        scanf("%d",&productoElegido);
    }
    nodoProducto = obtenerNodo(aux,productoElegido);
    printf("Cual es el nuevo nombre del producto?\n");
    fflush(stdin);
    gets(nombre);
    strcpy(nodoProducto->d.descripcion,nombre);
    printf("Cual es el nuevo precio del producto?\n");
    scanf("%d",&precio);
    nodoProducto->d.precio = precio;
}

void cargarVendedores(vendedor * VectorVendedores)
{
    int i;
    for(i = 0; i < VENDEDORES; i++)
    {
        VectorVendedores[i].codigo = i+1;
        VectorVendedores[i].cantVendida = 0;
    }
}

void simularVentas(Lista * productos, vendedor *VectorVendedores, int cantProd)
{
    int vendedorElegido;
    int productoElegido;
    int i;
    Nodo *nodoProducto;
    Lista aux = *productos;
    for(i = 0; i < VENTAS; i++)
    {
        vendedorElegido = rand()%VENDEDORES;
        productoElegido = 1+ rand()%cantProd;
        VectorVendedores[vendedorElegido].cantVendida++;
        nodoProducto = obtenerNodo(aux,productoElegido);
        nodoProducto->d.totalvendido++;
    }
}

void ordenar(vendedor vec[])
{
    int j, i=0;
    vendedor aux;

    for (j=1; j<VENDEDORES; j++)
    {
        for (i=0; i<VENDEDORES-j;i++)
        {
            if (vec[i].cantVendida < vec[i+1].cantVendida)
            {
                aux = vec[i];
                vec[i] = vec[i+1];
                vec[i+1] = aux;
            }
        }
    }
}

void mostrarElemento2(dato unDato)
{
    printf("Nombre: %s - Cantidad Vendida: %d\n",unDato.descripcion,unDato.totalvendido);
}