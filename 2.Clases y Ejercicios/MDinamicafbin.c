#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int codigoBarrio;
    char cliente[20];
    float importeAAbonar;
} envio;

int obtenerCantRegistros(FILE *);

int main() {
    envio * vector;
    int cantRegistros, i;
    FILE * fbin = fopen("/Users/candefagnani/Desktop/C/EjercicioMemoriaDinamica1/enviosdeldia.bin", "rb");
    if (fbin != NULL)
    {
        //Voy a averiguar cuantos elementos tiene el archivo enviosdeldia.bin
        cantRegistros = obtenerCantRegistros(fbin);
        vector = (envio*) malloc(cantRegistros * sizeof(envio));
        if (vector != NULL)
        {
            fread(vector, sizeof(envio), cantRegistros, fbin);
            for (i=0; i<cantRegistros; i++)
                printf("#%d - Codigo de Barrio %d \n...Cliente %s\n...A pagar %.2f\n", i+1,
                                                                                        vector[i].codigoBarrio,
                                                                                        vector[i].cliente,
                                                                                        vector[i].importeAAbonar);
            free(vector);
        }
        else
            printf("No se pudo reservar la memoria solicitada\n");
        fclose(fbin);
    }
    else
        printf("El archivo no pudo ser abierto\n");
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
    cantRegistros = ncant / sizeof (envio);
    //4.Restauro la posicion donde me encontraba
    fseek(fbin, offsetActual, SEEK_SET);
    return cantRegistros;
};