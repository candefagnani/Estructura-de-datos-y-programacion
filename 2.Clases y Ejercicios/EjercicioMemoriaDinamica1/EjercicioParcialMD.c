#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int codigoBarrio;
    char cliente[20];
    float importeAAbonar;
} envio_t;

typedef struct 
{
    int codigoBarrio;
    char barrio[20];
    int comuna;
    int entregas;
    float total;
} barrio_t;



int obtenerCantRegistros(FILE * fbin);
int contarLineas(FILE * ftxt);
void CargarBarrios(barrio_t * vectorb, int cantBarrios, FILE * ftxt);
void punto1(envio_t *vector, barrio_t *vectorb, int cantRegistros, int cantBarrios);
int longitud(char cad[]);
void punto2(envio_t *vector, barrio_t *vectorb, int cantRegistros, int cantBarrios);
void punto3(envio_t *vector,int cantRegistros);
void ordenar(envio_t vector[], int cantRegistros);
void punto4(barrio_t *vectorb, int cantBarrios);

int main (void)
{
    envio_t *vector;
    barrio_t *vectorb;
    int cantRegistros, cantBarrios;
    FILE * fbin = fopen("/Users/candefagnani/Desktop/C/EjercicioMemoriaDinamica1/enviosdeldia.bin", "rb");
    FILE * ftxt = fopen("/Users/candefagnani/Desktop/C/EjercicioMemoriaDinamica1/barriosycomunas.txt", "rt");
    if(fbin != NULL)
    {
        cantRegistros = obtenerCantRegistros(fbin);
        vector = (envio_t *) malloc(cantRegistros * sizeof(envio_t));
        if(vector != NULL)
        {
            fread(vector, sizeof(envio_t), cantRegistros, fbin);
        }
        else
            printf("No se pudo reservar la memoria solicitada\n");
        fclose(fbin);
    }
    else
        printf("El archivo no pudo ser abierto\n");

    if(ftxt != NULL)
    {
        cantBarrios = contarLineas(ftxt);
        vectorb = (barrio_t*)malloc(cantBarrios * sizeof(barrio_t));
        if(vector != NULL)
        {
            CargarBarrios(vectorb,cantBarrios,ftxt);
        }
        else
            printf("No se pudo reservar la memoria solicitada\n");
        fclose(ftxt);
    }
    else
        printf("No se pudo abrir el archivo\n");
    
    //Punto 1 
    printf("Ejecuto el punto 1...\n");
    punto1(vector, vectorb, cantRegistros, cantBarrios);
    printf("\n");

    //Punto 2
    printf("Ejecuto el punto 2...\n");
    punto2(vector, vectorb, cantRegistros, cantBarrios);
    printf("\n");

    //Punto 3
    printf("Ejecuto el punto 3...\n");
    punto3(vector,cantRegistros);
    printf("\n");

    //Punto4
    printf("Ejecuto el punto 4...\n");
    punto4(vectorb,cantBarrios);
    printf("\n");

    free(vector);
    free(vectorb);

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
    cantRegistros = ncant / sizeof (envio_t);
    //4.Restauro la posicion donde me encontraba
    fseek(fbin, offsetActual, SEEK_SET);
    return cantRegistros;
};

int contarLineas(FILE * ftxt)
{
    int offsetActual, cantLineas;
    offsetActual = ftell(ftxt);
    char linea[500];
    //1.Primero voy al comienzo del archivo
    rewind(ftxt); //Esto es EQUIVALENTE a fseek(ftxt, 0, SEEK_SET);
    //2.Empiezo a contar linea por linea
    cantLineas = 0;
    fgets(linea, 500, ftxt);
    while (!feof(ftxt))
    {
        cantLineas++;
        fgets(linea, 500, ftxt);
    }
    //3.Restauro la posicion inicial
    fseek(ftxt, offsetActual, SEEK_SET);
    return cantLineas;
};

void CargarBarrios(barrio_t * vectorb, int cantBarrios, FILE * ftxt)
{
    int i, j, longitudBarrio;
    for(i = 0; i < cantBarrios; i++)
    {
        fscanf(ftxt, "%d, %s ,%d",&vectorb[i].codigoBarrio, &vectorb[i].barrio, &vectorb[i].comuna);
        longitudBarrio = longitud(vectorb[i].barrio);
        for(j = 0; j < longitudBarrio; j++)
        {
            if(vectorb[i].barrio[j] == '_')
                vectorb[i].barrio[j] = ' ';
        }
        vectorb[i].entregas = 0;
        vectorb[i].total = 0;
    }
};

int longitud(char cad[])
{
    int cant = 0;
    while(cad[cant])
        cant++;
    return cant;
};

void punto1(envio_t *vector, barrio_t *vectorb, int cantRegistros, int cantBarrios)
{
    int i, j;
    for(i = 0; i < cantRegistros; i++)
    {
        for(j = 0; j < cantBarrios; j++)
        {
            if(vector[i].codigoBarrio == vectorb[j].codigoBarrio)
            {
                vectorb[j].entregas += 1;
                vectorb[j].total += vector[i].importeAAbonar;
                break;
            }
        }
    }
    for(i = 0; i < cantBarrios; i++)
        printf("Codigo de barrio: %d - Nombre del barrio: %s - Cant de entregas a realizar: %d - total a abonar: %.2f\n",vectorb[i].codigoBarrio,vectorb[i].barrio, vectorb[i].entregas, vectorb[i].total);
};

void punto2(envio_t *vector, barrio_t *vectorb, int cantRegistros, int cantBarrios)
{
    /*Mostrar la cantidad de entregas que superan en más de un 15% el promedio de venta y
    la cantidad de entregas por debajo de un 15% del promedio de venta*/
    int i = 0, sup = 0, inf = 0;
    float promedio, suma;
    for (i = 0; i < cantRegistros; i++)
    {
        suma += vector[i].importeAAbonar;
    } 
    promedio = suma/(cantRegistros);
    printf("\nEl promedio de todas las ventas es %.2f\nEl 15 porciento del promedio es de %.2f\n",promedio,(1.15*promedio));
    for (i = 0; i < cantRegistros; i++)
    {
        if(vector[i].importeAAbonar > (1.15*promedio))
            sup++;
        if(vector[i].importeAAbonar < (0.85*promedio))
            inf++;
    }
    printf("Entregas mayores al 15 porciento %d\n",sup);
    printf("Entregas menores al 15 porciento %d\n",inf);
};

void punto3(envio_t *vector, int cantRegistros)
{
    /*Mostrar el nombre de los 10 clientes cuyo pedido haya sido el de mayor valor, 
    ordenado descendientemente por importe pagado */
    int i = 0;
    ordenar(vector, cantRegistros);
    printf("Clientes cuyo pedido haya sido el de mayor valor...\n");
    for(i = 0; i < 10; i++)
        printf("El ciente %s - Importe de pago: %.2f\n",vector[i].cliente,vector[i].importeAAbonar);
};

void ordenar(envio_t vector[], int cantRegistros)
{
	int j = 1, i=0;
	envio_t aux;

	for (j = 1; j < cantRegistros; j++)
	{
		for (i = 0; i < cantRegistros-j;i++)
		{
			if ((vector[i].importeAAbonar < vector[i+1].importeAAbonar))
			{
				aux = vector[i];
				vector[i] = vector[i+1];
				vector[i+1] = aux;
			}
		}
	}
};

void punto4(barrio_t *vectorb, int cantBarrios)
{
    //Mostrar la comuna más rentable y los barrios que la componen
    float max = 0;
    float suma;
    int comuna, i, j;
    for (i = 0; i < cantBarrios; i++)
    {
        suma = 0;
        for (j = 0; j< cantBarrios; j++)
        {
            if (vectorb[i].comuna == vectorb[j].comuna)
                suma+=vectorb[j].total;
        }
        if (suma>max)
        {
            max = suma;
            comuna = vectorb[i].comuna;
        }
    }
    printf("La comuna mas rentable es la %d y los barrios que la componen son:\n",comuna);
    for (i = 0; i < cantBarrios; i++)
    {
        if (vectorb[i].comuna==comuna)
            printf("%s\n",vectorb[i].barrio);
    }
}