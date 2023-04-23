#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* Tanto en el archivo empleados.txt como productos.txt veo que hay 6 empleados y //6 productos
si se agrega otro producto o se emplea a otra persona y se modifica el archivo puedo cambiar directamente 
el valor en el #define (asi n evito hacerlo 1 por 1)*/
#define VENDEDORES 6 
#define PRODUCTOS 6 

//Estructuras
typedef struct
{
    int codigoProducto;
    float precioProducto;
    char nombreProducto[50];
    int TotalProd;
} producto_t;

typedef struct
{
    int numeroVendedor;
    float comisionVendedor;
    char nombreVendedor[50];
    int CantproductosVendidos;
    float totalVendido;
} vendedor_t;


//Funciones definidas
void AbreEmpleados(vendedor_t[]);
void AbreProductos(producto_t[]);
void copiarCadena(char[],char[]);
int longitud(char[]);
void punto1(vendedor_t[],producto_t[]);
void punto2(vendedor_t[]);
void punto3(producto_t[]);
void ordenar(producto_t vec[], int cantElementos);
void punto4(producto_t[]);
void cortarCadena(char cad[]);

//Main
int main (void)
{
    producto_t productos[PRODUCTOS];
    vendedor_t vendedores[VENDEDORES];
    AbreEmpleados(vendedores);
    AbreProductos(productos);
    
    //Punto 1
    printf("Ejecuto el punto 1...\n");
    punto1(vendedores,productos);
    printf("\n");

    //Punto 2
    printf("Ejecuto el punto 2...\n");
    punto2(vendedores);
    printf("\n");

    //Punto 3
    printf("Ejecuto el punto 3...\n");
    punto3(productos);
    printf("\n");

    //Punto 4
    printf("Ejecuto el punto 4...\n");
    punto4(productos);
    printf("\n");

    return 0;
}

void AbreEmpleados(vendedor_t vendedores[])
{
    FILE* fEmpleados;
    int numEmpleado, i = 0;
    float comision;
    char nombre[50];
    fEmpleados = fopen("/Users/candefagnani/Desktop/C/PP EDP - 1C2022/empleados.txt","rt");
    if (fEmpleados != NULL)
    {
        fscanf(fEmpleados, "%d", &numEmpleado); //Tomo el Numero de empleado
        while (!feof(fEmpleados))
        {
            fgetc(fEmpleados); //Me deshago de la coma
            fscanf(fEmpleados, "%f", &comision); //Tomo la comision
            fgetc(fEmpleados); //Me deshago de la coma
            fgets(nombre, 50, fEmpleados); //Tomo el nombre
            cortarCadena(nombre);
            //Asigno los valores a la estructura
            vendedores[i].numeroVendedor = numEmpleado;
            copiarCadena(vendedores[i].nombreVendedor, nombre);
            vendedores[i].comisionVendedor = comision;
            vendedores[i].CantproductosVendidos = 0;
            vendedores[i].totalVendido = 0;
            i++;
            fscanf(fEmpleados, "%d", &numEmpleado);
        }
        fclose(fEmpleados);
    }
    else
        printf("El archivo no pudo ser abierto\n");
}

void AbreProductos(producto_t productos[])
{
    FILE* fProductos;
    int codProducto, i = 0;
    float precioProducto;
    char nombre[50];
    fProductos = fopen("/Users/candefagnani/Desktop/C/PP EDP - 1C2022/productos.txt","rt");
    if (fProductos != NULL)
    {
        fscanf(fProductos,"%d",&codProducto); //Tomo el codigo del producto
        while (!feof(fProductos))
        {
            fgetc(fProductos); //Me Deshago de la coma
            fscanf(fProductos, "%f", &precioProducto); //Tomo el precio del producto
            fgetc(fProductos); //Me Deshago de la coma
            fgets(nombre, 50, fProductos); //Tomo el nombre del producto
            cortarCadena(nombre);
            //Asigno los valores a la estructura
            productos[i].codigoProducto = codProducto;
            copiarCadena(productos[i].nombreProducto, nombre);
            productos[i].precioProducto = precioProducto;
            productos[i].TotalProd = 0;
            i++;
            fscanf(fProductos,"%d",&codProducto);
        }
        fclose(fProductos);
    }
    else
        printf("El archivo no pudo ser abierto\n");
}

void punto1(vendedor_t vendedores[],producto_t productos[])
{
    int hora = 13, j = 0;
    srand(time(NULL));
    int compradores, producto, vendedor, COMPRA;
    for (hora = 13; hora < 22; hora++)
    {
        printf("\nHora: %d...\n",hora);
        if (hora == 13 || hora == 16)
        {
            compradores = rand() % 61;
            printf("Ingresaron %d compradores\n",compradores);
            for (j = 0; j < compradores; j++)
            {
                COMPRA = rand() % 2; //si COMPRA == 0 no compro nada, si COMPRA == 1 compró algo
                if (COMPRA != 1)
                {
                    vendedor = rand() %(VENDEDORES);
                    printf("El cliente %d no compró nada y fue atendido por %s\n",(j+1),vendedores[vendedor].nombreVendedor);
                }
                else
                {
                    vendedor = rand() %(VENDEDORES);
                    producto = rand() %(PRODUCTOS);
                    printf("El cliente %d compró el producto %s y fue atendido por %s\n",(j+1),productos[producto].nombreProducto,vendedores[vendedor].nombreVendedor);
                    vendedores[vendedor].CantproductosVendidos++;
                    vendedores[vendedor].totalVendido += productos[producto].precioProducto;
                    productos[producto].TotalProd++;
                }
            }
        }
        if (hora == 14 || hora == 15 || hora == 18)
        {
            compradores = rand() % 101;
            printf("Ingresaron %d compradores\n",compradores);
            for (j = 0; j < compradores; j++)
            {
                COMPRA = rand() % 2; //si COMPRA == 0 no compro nada, si COMPRA == 1 compró algo
                if (COMPRA != 1)
                {
                    vendedor = rand() %(VENDEDORES);
                    printf("El cliente %d no compró nada y fue atendido por %s\n",(j+1),vendedores[vendedor].nombreVendedor);
                }
                else
                {
                    vendedor = rand() %(VENDEDORES);
                    producto = rand() %(PRODUCTOS);
                    printf("El cliente %d compró el producto %s y fue atendido por %s\n",(j+1),productos[producto].nombreProducto,vendedores[vendedor].nombreVendedor);
                    vendedores[vendedor].CantproductosVendidos++;
                    vendedores[vendedor].totalVendido += productos[producto].precioProducto;
                    productos[producto].TotalProd++;
                }
            }
        }
        if (hora == 17 || hora == 21)
        {
            compradores = rand() % 41;
            printf("Ingresaron %d compradores\n",compradores);
            for (j = 0; j < compradores; j++)
            {
                COMPRA = rand() % 2; //si COMPRA == 0 no compro nada, si COMPRA == 1 compró algo
                if (COMPRA != 1)
                {
                    vendedor = rand() %(VENDEDORES);
                    printf("El cliente %d no compró nada y fue atendido por %s\n",(j+1),vendedores[vendedor].nombreVendedor);
                }
                else
                {
                    vendedor = rand() %(VENDEDORES);
                    producto = rand() %(PRODUCTOS);
                    printf("El cliente %d compró el producto %s y fue atendido por %s\n",(j+1),productos[producto].nombreProducto,vendedores[vendedor].nombreVendedor);
                    vendedores[vendedor].CantproductosVendidos++;
                    vendedores[vendedor].totalVendido += productos[producto].precioProducto;
                    productos[producto].TotalProd++;
                }
            }
        }
        if (hora == 19)
        {
            compradores = rand() % 121;
            printf("Ingresaron %d compradores\n",compradores);
            for (j = 0; j < compradores; j++)
            {
                COMPRA = rand() % 2; //si COMPRA == 0 no compro nada, si COMPRA == 1 compró algo
                if (COMPRA != 1)
                {
                    vendedor = rand() %(VENDEDORES);
                    printf("El cliente %d no compró nada y fue atendido por %s\n",(j+1),vendedores[vendedor].nombreVendedor);
                }
                else
                {
                    vendedor = rand() %(VENDEDORES);
                    producto = rand() %(PRODUCTOS);
                    printf("El cliente %d compró el producto %s y fue atendido por %s\n",(j+1),productos[producto].nombreProducto,vendedores[vendedor].nombreVendedor);
                    vendedores[vendedor].CantproductosVendidos++;
                    vendedores[vendedor].totalVendido += productos[producto].precioProducto;
                    productos[producto].TotalProd++;
                }
            }
        }
        if (hora == 20)
        {
            compradores = rand() % 81;
            printf("Ingresaron %d compradores\n",compradores);
            for (j = 0; j < compradores; j++)
            {
                COMPRA = rand() % 2; //si COMPRA == 0 no compro nada, si COMPRA == 1 compró algo
                if (COMPRA != 1)
                {
                    vendedor = rand() %(VENDEDORES);
                    printf("El cliente %d no compró nada y fue atendido por %s\n",(j+1),vendedores[vendedor].nombreVendedor);
                }
                else
                {
                    vendedor = rand() %(VENDEDORES);
                    producto = rand() %(PRODUCTOS);
                    printf("El cliente %d compró el producto %s y fue atendido por %s\n",(j+1),productos[producto].nombreProducto,vendedores[vendedor].nombreVendedor);
                    vendedores[vendedor].CantproductosVendidos++;
                    vendedores[vendedor].totalVendido += productos[producto].precioProducto;
                    productos[producto].TotalProd++;
                }
            }
        }
    }
}

void punto2(vendedor_t vendedores[])
{
    int i = 0;
    for (i = 0; i < VENDEDORES; i++)
    {
        printf("Nombre: %s\nCantidad de productos vendidos: %d\nTotal vendido: $%.2f\nComsion a cobrar: %.2f\n\n",vendedores[i].nombreVendedor, vendedores[i].CantproductosVendidos, vendedores[i].totalVendido, ((vendedores[i].comisionVendedor)*vendedores[i].totalVendido)/(float)100);
    }
}

void punto3(producto_t productos[])
{
    int i = 0;
    ordenar(productos,PRODUCTOS);
    for (i = 0; i < PRODUCTOS; i++)
        printf("Producto: %s\nTotal Vendido: %d\n\n",productos[i].nombreProducto,productos[i].TotalProd);
}

void punto4(producto_t productos[])
{
    int i = 0;
    int sumaProductos = 0;
    for (i = 0; i < PRODUCTOS; i++)
        sumaProductos += productos[i].TotalProd;
    printf("El total vendido por toda la tienda es de: %d\n",sumaProductos);
}

void copiarCadena(char destino[], char origen[])
{
    int i = 0;
    for (i = 0; i <= longitud(origen); i++)
    {
        if(origen[i] != '\r' && origen[i] != '\n')
            destino[i] = origen[i];
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

void ordenar(producto_t vec[], int cantElementos)
{
	int j = 1, i=0;
	producto_t aux;

	for (j = 1; j < cantElementos; j++)
	{
		for (i = 0; i < cantElementos-j;i++)
		{
			if (vec[i].TotalProd < vec[i+1].TotalProd)
			{
				aux = vec[i];
				vec[i] = vec[i+1];
				vec[i+1] = aux;
			}
		}
	}
}