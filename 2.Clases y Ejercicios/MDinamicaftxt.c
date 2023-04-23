#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int codigo;
    float porcentaje;
    char nombre[100];
} empleado;

int contarLineas(FILE *);
void cargarEmpleados(empleado * vector, int cantRegistros, FILE * ftxt);

int main() {
    FILE * ftxt;
    int cantRegistros, i;
    empleado * vector;
    ftxt = fopen("/Users/candefagnani/Desktop/C/PP EDP - 1C2022/empleados.txt", "rt");
    if (ftxt !=NULL)
    {
        cantRegistros = contarLineas(ftxt);
        vector = (empleado * ) malloc(cantRegistros * sizeof(empleado));
        cargarEmpleados(vector, cantRegistros, ftxt);
        for (i=0; i<cantRegistros; i++)
        {
            printf("Codigo %d - Comision %.2f - Empleado %s",
                                                            vector[i].codigo,
                                                            vector[i].porcentaje,
                                                            vector[i].nombre);
        }
        fclose(ftxt);
        free(vector);
    }
    return 0;
}

int contarLineas(FILE * ftxt)
{
    int offsetActual, cantRegistros;
    offsetActual = ftell(ftxt);
    char linea[500];
    //1.Primero voy al comienzo del archivo
    rewind(ftxt); //Esto es EQUIVALENTE a fseek(ftxt, 0, SEEK_SET);
    //2.Empiezo a contar linea por linea
    cantRegistros = 0;
    fgets(linea, 500, ftxt);
    while (!feof(ftxt))
    {
        cantRegistros++;
        fgets(linea, 500, ftxt);
    }
    //3.Restauro la posicion inicial
    fseek(ftxt, offsetActual, SEEK_SET);
    return cantRegistros;
}

void cargarEmpleados(empleado * vector, int cantRegistros, FILE * ftxt)
{
    int i;
    for (i=0; i<cantRegistros; i++)
    {
        fscanf(ftxt, "%d", &vector[i].codigo);
        fscanf(ftxt, "%f", &vector[i].porcentaje);
        fgets(vector[i].nombre, 100, ftxt);
    }
}