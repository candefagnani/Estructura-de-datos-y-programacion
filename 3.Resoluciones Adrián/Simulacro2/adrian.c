#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    int equipo;
    char nombre[50];
    int puntos;
    int GF;
    int GE;

} Equipo;

void abrirEquipos(Equipo[]);
void punto1(Equipo[], int[10][10]);
void punto2y4(Equipo[], int[10][10]);
void punto3(Equipo[], int[10][10]);
void ordenar(Equipo[], int);
void restaurar(Equipo equipos[], int cantElementos);

int main(void)
{
    Equipo equipos[10];
    int matgoles[10][10] = {0};

    abrirEquipos(equipos);

    // Punto 1
    printf("Ejecuto el punto 1 ...\n");
    punto1(equipos, matgoles);

    printf("Ejecuto el punto 3 ...\n");
    punto3(equipos, matgoles);

    printf("Ejecuto el punto 2 ...\n");
    punto2y4(equipos, matgoles);

    //getchar();
    return 0;
}

int longitud (char cad[])
{
    int cant=0;
    while (cad[cant])
        cant++;
    return cant;
}

void copiarCadena(char destino[], char origen[])
{
    int i;
    for (i=0; i<=longitud(origen); i++)
        if (origen[i] != '\r' && origen[i] != '\n')
            destino[i] = origen[i];
}

void abrirEquipos(Equipo equipos[])
{
    FILE * fEquipo;
    int codEquipo;
    char nombreEquipo[50];
    int i = 0;

    fEquipo = fopen("/Users/candefagnani/Desktop/C/Simulacro2/equipos.txt", "rt");
    if (fEquipo != NULL)
    {
        fscanf(fEquipo, "%d", &codEquipo);
        while (!feof(fEquipo))
        {
            // Me deshago de la coma que tiene el archivo
            fgetc(fEquipo);
            // Leo el nombre del equipo
            fgets(nombreEquipo, 50, fEquipo);
            // Almacenar los datos en memoria
            equipos[i].equipo = codEquipo;
            copiarCadena(equipos[i].nombre, nombreEquipo);

            equipos[i].puntos = 0;
            equipos[i].GF = 0;
            equipos[i].GE = 0;

            i++;
            // Leo el siguiente codigo de equipo
            fscanf(fEquipo, "%d", &codEquipo);
        }
        fclose(fEquipo);
    } else
        printf("No se pudo abrir el archivo equipos.txt\n");
}

int buscarEquipo(Equipo equipo[], int codigoABuscar)
{
    int i, pos=-1;
    for (i=0; i<10; i++)
    {
        if (equipo[i].equipo == codigoABuscar)
        {
            pos = i;
            break;
        }
    }
    return pos;
}

void punto1(Equipo equipos[], int matgoles[10][10])
{
    FILE * fPartido;
    int codEquipo1, codEquipo2, pos1, pos2;
    int equipo, gol;
    int cantGolesA, cantGolesB;
    char linea[100];

    fPartido = fopen("/Users/candefagnani/Desktop/C/Simulacro2/partidos.txt", "rt");
    if (fPartido != NULL)
    {
        fgets(linea, 100, fPartido);
        while (!feof(fPartido))
        {
            sscanf(linea, "Partido: %d vs %d", &codEquipo1, &codEquipo2);
            pos1 = buscarEquipo(equipos, codEquipo1);
            pos2 = buscarEquipo(equipos, codEquipo2);
            cantGolesA = 0;
            cantGolesB = 0;
            equipo = -1;
            fgets(linea, 100, fPartido);
            while ((linea[0] != 'P') && (!feof(fPartido)))
            {
                sscanf(linea, "%d,%d", &equipo, &gol);
                if (equipo == equipos[pos1].equipo)
                    cantGolesA = cantGolesA + 1;
                if (equipo == equipos[pos2].equipo)
                    cantGolesB = cantGolesB + 1;
                fgets(linea, 100, fPartido);
            }
            matgoles[pos1][pos2] = matgoles[pos1][pos2] + cantGolesA;
            matgoles[pos2][pos1] = matgoles[pos2][pos1] + cantGolesB;

            printf("%20s%3d-%3d %s \n",    equipos[pos1].nombre, cantGolesA,
                   cantGolesB, equipos[pos2].nombre);
        }
        fclose(fPartido);
    } else
        printf("No se pudo abrir el archivo equipos.txt\n");
}

void punto2y4(Equipo equipos[], int matgoles[10][10])
{
    int eq1, eq2, pos1, pos2;
    for (eq1=0; eq1<10; eq1++)
    {
        for (eq2=0; eq2<10; eq2++)
        {
            if (eq1 != eq2)
            {
                equipos[eq1].GF = equipos[eq1].GF + matgoles[eq1][eq2];
                equipos[eq1].GE = equipos[eq1].GE + matgoles[eq2][eq1];

                if ( matgoles[eq1][eq2] >  matgoles[eq2][eq1])
                    equipos[eq1].puntos = equipos[eq1].puntos + 3;

                if ( matgoles[eq1][eq2] ==  matgoles[eq2][eq1])
                    equipos[eq1].puntos = equipos[eq1].puntos + 1;

            }
        }
    }
    ordenar(equipos, 10);
    printf("%3s %-20.20s %6s %3s %3s %s\n", "Pos", "Equipo", "Puntos", "GF", "GE", "Promedio");
    for (eq1=0; eq1<10; eq1++)
    {
        printf("%02d ", equipos[eq1].equipo);
        printf("%-20.20s", equipos[eq1].nombre);
        printf("%8d", equipos[eq1].puntos);
        printf("%4d", equipos[eq1].GF);
        printf("%4d", equipos[eq1].GE);
        printf("%6.2f\n", (float)equipos[eq1].GF/9);
    }
    pos1 = equipos[0].equipo-1;
    restaurar(equipos, 10);
    printf("Punto 4 - Todos los partidos del campeon...\n");
    for (eq1=0; eq1<10; eq1++)
    {
        pos2 = eq1;
        if (pos1 != pos2)
            printf("%20s%3d-%3d %s \n",    equipos[pos1].nombre, matgoles[pos1][pos2],
               matgoles[pos2][pos1], equipos[pos2].nombre);
    }
}

void punto3(Equipo equipos[], int matgoles[10][10])
{
    int eq1, eq2;
    int aux[10]={0};
    int max=0, pos=-1;
    //Primero cuento quien metio mas de tres goles
    for (eq1=0; eq1<10; eq1++)
    {
        for (eq2=0; eq2<10; eq2++)
        {
            if (matgoles[eq1][eq2] >= 3)
                aux[eq1]++;
        }
    }

    //Ahora busco el mayor
    pos = 0;
    max = aux[0];
    for (eq1=1; eq1<10; eq1++)
    {
        if (max < aux[eq1])
        {
            max = aux[eq1];
            pos = eq1;
        }
    }
    printf("El equipo que mas veces metio +3 goles es %s\n", equipos[pos].nombre);
}

void ordenar(Equipo equipos[], int cantElementos)
{
    int j, i=0;
    Equipo aux;

    for (j=1; j<cantElementos; j++)
    {
        for (i=0; i<cantElementos-j;i++)
        {
            if ((equipos[i].puntos<equipos[i+1].puntos) ||
            (equipos[i].puntos==equipos[i+1].puntos && equipos[i].GF<equipos[i+1].GF) ||
            (equipos[i].puntos==equipos[i+1].puntos && equipos[i].GF==equipos[i+1].GF && equipos[i].GE>equipos[i+1].GE))
            {
                aux = equipos[i];
                equipos[i] = equipos[i+1];
                equipos[i+1] = aux;
            }
        }
    }
    return;
}

void restaurar(Equipo equipos[], int cantElementos)
{
    int j, i=0;
    Equipo aux;

    for (j=1; j<cantElementos; j++)
    {
        for (i=0; i<cantElementos-j;i++)
        {
            if ((equipos[i].equipo>equipos[i+1].equipo))
            {
                aux = equipos[i];
                equipos[i] = equipos[i+1];
                equipos[i+1] = aux;
            }
        }
    }
    return;
}