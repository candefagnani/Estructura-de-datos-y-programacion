#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "librerias/listas.h"

typedef struct
{
    int codigoProducto;
    float precioProducto;
    char nombreProducto[50];
    float TotalProd;
    int cantVendida;
} producto_t;

int contarLineas(FILE * ftxt);
void CargarProd(producto_t * VectorProd, int cantProductos, FILE * ftxt);
int longitud(char cad[]);
void cortarCadena(char cad[]);
Lista CargarEmpleados(FILE * fempleados);
int decidirClientes(int hs);
float buscarProducto(producto_t *VectorProd, int codigo, int cantProductos);
int buscarEmpleado(Lista *empleados, int vendedor, float producto);
void punto1(Lista *empleados, producto_t *VectorProd, int cantEmpleados, int cantProductos);
void punto2(Lista *empleados);
void punto3(producto_t *VectorProd, int cantProductos);
void ordenar(producto_t *VectorProd, int cantProductos);


int main(void)
{
    int cantProductos;
    int cantEmpleados;

    producto_t *VectorProd;
    Lista empleados = NULL;

    FILE *fempleados = fopen("/Users/candefagnani/Desktop/Simulacro 1.2/empleados.txt", "rt");
    FILE *fproductos = fopen("/Users/candefagnani/Desktop/Simulacro 1.2/productos.txt", "rt");

    //Para productos.txt
    if(fproductos != NULL)
    {
        cantProductos = contarLineas(fproductos);
        VectorProd = (producto_t *)malloc(cantProductos * sizeof(producto_t));
        if(VectorProd != NULL)
        {
            CargarProd(VectorProd,cantProductos,fproductos);
        }
        else
            printf("No se pudo reservar la memoria solicitada\n");
        fclose(fproductos);
    }
    else
        printf("No se pudo abrir el archivo\n");

    //para empleados.txt
    if(fempleados != NULL)
    {
        empleados = CargarEmpleados(fempleados);
        cantEmpleados = contarLineas(fempleados);
        fclose(fempleados);
    }
    else
        printf("No se pudo abrir el archivo\n");

    //---------------------------------------------------
    printf("Antes del inicio de la simulacion\n");
    mostrarLista(empleados);
    int i;
    for (i = 0; i < cantProductos; i++)
    {
        printf("------------------\n");
        printf("Codigo del Producto: %d\n", VectorProd[i].codigoProducto);
        printf("Precio del producto: %.2f\n",VectorProd[i].precioProducto);
        printf("Nombre del producto: %s\n",VectorProd[i].nombreProducto);
    }
    //---------------------------------------------------

    //Punto 1
    printf("\n\nINICIO LA SIMULACION...\n\n");
    printf("Ejecuto el punto 1...\n");
    punto1(&empleados,VectorProd,cantEmpleados,cantProductos);
    mostrarLista(empleados);

    //Punto 2
    printf("\nEjecuto el punto 2...\n");
    punto2(&empleados);

    //Punto 3 y 4
    printf("\nEjecuto el punto 3 y 4...\n");
    punto3(VectorProd,cantProductos);


    free(VectorProd);
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
    //Va a volver a la posicion inicial
    return cantLineas;
}

void CargarProd(producto_t * VectorProd, int cantProductos, FILE * ftxt)
{
    int i = 0;
    for(i = 0; i < cantProductos; i++)
    {
        fscanf(ftxt,"%d",&VectorProd[i].codigoProducto);
        fgetc(ftxt); //Me Deshago de la coma
        fscanf(ftxt, "%f", &VectorProd[i].precioProducto); //Tomo el precio del producto
        fgetc(ftxt); //Me Deshago de la coma
        fgets(VectorProd[i].nombreProducto, 50, ftxt); //Tomo el nombre del producto
        cortarCadena(VectorProd[i].nombreProducto);
        VectorProd[i].TotalProd = 0;
        VectorProd[i].cantVendida = 0;
    }
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

int longitud(char cad[])
{
    int cant = 0;
    while(cad[cant])
        cant++;
    return cant;
}

Lista CargarEmpleados(FILE * fempleados)
{
    int cantEmpleados = contarLineas(fempleados);
    Lista empleados = NULL;
    dato UnEmpleado;
    int i;
    for(i = 0; i < cantEmpleados; i++)
    {
        fscanf(fempleados, "%d", &UnEmpleado.numeroVendedor);
        fgetc(fempleados); //Me deshago de la coma
        fscanf(fempleados, "%f", &UnEmpleado.comisionVendedor); //Tomo la comision
        fgetc(fempleados); //Me deshago de la coma
        fgets(UnEmpleado.nombreVendedor, 50, fempleados); //Tomo el nombre
        cortarCadena(UnEmpleado.nombreVendedor);
        UnEmpleado.CantproductosVendidos = 0;
        UnEmpleado.totalVendido = 0;
        insertar(&empleados,UnEmpleado);
    }
    return empleados;
}

int decidirClientes(int hs)
{
    srand(time(NULL));
    if (hs == 13 ||hs == 16)
        return rand()% 60;
    if (hs== 14 || hs == 15 || hs == 18)
        return rand()% 100;
    if (hs ==17 || hs== 21)
        return rand()% 40;
    if (hs == 19)
        return rand()% 120;
    else
        return rand()% 80;
}

float buscarProducto(producto_t *VectorProd, int codigo, int cantProductos)
{
    int i;
    for(i = 0; i < cantProductos; i++)
    {
        if(VectorProd[i].codigoProducto == codigo)
        {
            VectorProd[i].cantVendida++;
            VectorProd[i].TotalProd += VectorProd[i].precioProducto;
            break;
        }
    }
    return VectorProd[i].precioProducto;
}

int buscarEmpleado(Lista *empleados, int vendedor, float producto)
{
    Nodo *aux = *empleados;
    while(aux != NULL && aux->d.numeroVendedor != vendedor)
    {
        aux = aux->sig;
    }
    if(aux == NULL)
        return -1;
    aux->d.CantproductosVendidos++;
    aux->d.totalVendido += producto;
    return 1;
}

void punto1(Lista *empleados, producto_t *VectorProd, int cantEmpleados, int cantProductos)
{
    int j, horas, MaxClientes, producto, vendedor, decision;
    float precio;
    for (horas = 13; horas < 22; horas++)
    {
        MaxClientes = decidirClientes(horas);
        for(j = 0; j < MaxClientes; j++)
        {
            producto = rand()% (cantProductos+1);
            vendedor = rand()% (cantEmpleados+1);
            decision = rand()% 2;
            if (decision != 0)
            {
                precio = buscarProducto(VectorProd,producto,cantProductos);
                buscarEmpleado(empleados,vendedor,precio);
            }
        }
    }
}

void punto2(Lista *empleados)
{
    Lista aux;
    aux = *empleados;
    while(aux != NULL)
    {
        printf("Nombre:%s - Productos Vendids: %d - Total Vendido: %.2f - A cobrar: %.2f\n",aux->d.nombreVendedor,aux->d.CantproductosVendidos,aux->d.totalVendido,aux->d.totalVendido*(aux->d.comisionVendedor/100));
        aux = aux->sig;
    }
}

void ordenar(producto_t *VectorProd, int cantProductos)
{
    int j = 1, i=0;
    producto_t aux;

    for (j = 1; j < cantProductos; j++)
    {
        for (i = 0; i < cantProductos-j;i++)
        {
            if (VectorProd[i].TotalProd < VectorProd[i+1].TotalProd)
            {
                aux = VectorProd[i];
                VectorProd[i] = VectorProd[i+1];
                VectorProd[i+1] = aux;
            }
        }
    }
}

void punto3(producto_t *VectorProd, int cantProductos)
{
    int i;
    float total = 0;
    ordenar(VectorProd, cantProductos);
    for (i = 0; i < cantProductos; i++)
    {
        printf("%s %.2f\n",VectorProd[i].nombreProducto,VectorProd[i].TotalProd);
        total += VectorProd[i].TotalProd;
    }
    printf("El total vendido es %.2f\n",total);
}
