#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct 
{
    int codigo;
    char nombre[50];
    int GF;
    int GE;
    int puntos;
} equipo_t;

//Funciones Creadas
void AbrirEquipos(equipo_t[]);
void punto1(equipo_t[],int matgoles[10][10]);
void copiarCadena(char[],char[]);
int longitud(char[]);
int buscarEquipo(equipo_t[],int);
void punto2y4(equipo_t[],int matgoles[10][10]);
void ordenar(equipo_t equipos[],int cantElementos);
void punto3(equipo_t[],int matgoles[10][10]);
void punto4(equipo_t[],int matgoles[10][10]);
void restaurar(equipo_t equipos[],int cantElementos);

int main (void)
{
    equipo_t equipos[10];
    AbrirEquipos(equipos);
    int matgoles[10][10] = {0};

    //Punto 1
    printf("Resuelvo el punto 1...\n");
    punto1(equipos,matgoles);
    printf("\n");

    //Punto 3
    printf("Resuelvo el punto 3...\n");
    punto3(equipos,matgoles);
    printf("\n");
    
    //Punto 2 (como este me cambia la posicion de los equipos hago primero el 3)
    printf("Resuelvo el punto 2...\n");
    punto2y4(equipos,matgoles);
    printf("\n");

    return 0;
}

void AbrirEquipos(equipo_t equipos[])
{
    FILE* fEquipo;
    int codEquipo, i = 0;
    char nombreEquipo[50];
    fEquipo = fopen("/Users/candefagnani/Desktop/C/Simulacro2/equipos.txt","rt");
    if (fEquipo != NULL)
    {
        fscanf(fEquipo,"%d",&codEquipo);
        while(!feof(fEquipo))
        {
            //me deshago de la coma que tiene el archivo (llega un carac que me molesta y lo salteo)
            fgetc(fEquipo);
            //leo el nombre del equipo
            fgets(nombreEquipo,50,fEquipo);
            //almaceno los datos en memoria
            equipos[i].codigo = codEquipo;
            copiarCadena(equipos[i].nombre,nombreEquipo);
            equipos[i].puntos = 0;
            equipos[i].GF = 0;
            equipos[i].GE = 0;
            i++;
            //Leo el siguiente codigo de equipo
            fscanf(fEquipo,"%d",&codEquipo);
        }
        fclose(fEquipo);
    }
    else
        printf("No se pudo abrir correctamente equipos.txt\n");
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

int longitud(char cad[])
{
    int cant = 0;
    while(cad[cant])
        cant++;
    return cant;
}

void punto1(equipo_t equipos[], int matgoles[10][10])
{
    FILE* fPartidos;
    int codEquipo1, codEquipo2, pos1, pos2;
    int equipo, gol;
    int cantGolesA, cantGolesB;
    char linea[100];

    fPartidos = fopen("/Users/candefagnani/Desktop/C/Simulacro2/partidos.txt","rt");
    if(fPartidos != NULL)
    {
        fgets(linea,100,fPartidos);
        while(!feof(fPartidos))
        {
            sscanf(linea,"Partido:%d vs %d",&codEquipo1,&codEquipo2);
            pos1 = buscarEquipo(equipos,codEquipo1);
            pos2 = buscarEquipo(equipos,codEquipo2);
            cantGolesA = 0;
            cantGolesB = 0;
            fgets(linea,100,fPartidos);
            while ((linea[0] != 'P') && !feof(fPartidos))
            {
                sscanf(linea,"%d,%d", &equipo, &gol);
                if (equipo == equipos[pos1].codigo)
                    cantGolesA++;
                if(equipo == equipos[pos2].codigo)
                    cantGolesB++;
                fgets(linea,100,fPartidos);
            }
            matgoles[pos1][pos2] = matgoles[pos1][pos2] + cantGolesA; //cuando el equipo1 jugo contra el equipo2
            matgoles[pos2][pos1] = matgoles[pos2][pos1] + cantGolesB; //cuando el equipo2 jugo contra el equipo1
            printf("%s <%d> - <%d> %s\n", equipos[pos1].nombre,cantGolesA,cantGolesB,equipos[pos2].nombre);
        }
        fclose(fPartidos);
    }
    else
        printf("No se pudo abrir el archivo partidos.txt\n");
}

int buscarEquipo(equipo_t equipos[], int codigoABuscar)
{
    int i = 0, pos = -1;
    for (i = 0; i < 10; i++)
    {
        if(equipos[i].codigo == codigoABuscar)
        {
            pos = i;
            break;
        }
    }
    return pos;
}

void punto2y4(equipo_t equipos[],int matgoles[10][10])
{
    int equipo1, equipo2;
    int pos1,pos2;

    for (equipo1 = 0; equipo1 < 10; equipo1++)
    {
        for(equipo2 = 0; equipo2 < 10; equipo2++)
        {
            if(equipo1 != equipo2)
            {
                equipos[equipo1].GF = equipos[equipo1].GF + matgoles[equipo1][equipo2];
                equipos[equipo1].GE = equipos[equipo1].GE + matgoles[equipo2][equipo1];
                if(matgoles[equipo1][equipo2] > matgoles[equipo2][equipo1])
                    equipos[equipo1].puntos += 3;
                else if (matgoles[equipo1][equipo2] == matgoles[equipo2][equipo1])
                    equipos[equipo1].puntos += 1;
            }
        }
    }
    ordenar(equipos,10);
    printf("%3s %-20.20s %6s %3s %3s %s\n", "Pos", "Equipo", "Puntos","GF", "GE", "Promedio");
    for (equipo1 = 0; equipo1 < 10; equipo1++)
    {
        printf("%02d ",equipos[equipo1].codigo);
        printf("%-20.20s",equipos[equipo1].nombre);
        printf("%8d",equipos[equipo1].puntos);
        printf("%4d",equipos[equipo1].GF);
        printf("%4d",equipos[equipo1].GE);
        printf("%6.2f\n",(float)equipos[equipo1].GF/9);
    }
    pos1 = (equipos[0].codigo-1);
    restaurar(equipos,10);
    printf("Punto 4 - Todos los partidos del campeon...\n");
    for (equipo1 = 0; equipo1 < 10; equipo1++)
    {
        pos2 = equipo1;
        if (pos1 != pos2)
            printf("%s <%d> - <%d> %s\n", equipos[pos1].nombre,matgoles[pos1][pos2],matgoles[pos2][pos1],equipos[pos2].nombre);
    }
}

void ordenar(equipo_t equipos[],int cantElementos)
{
    int j, i = 0;
    equipo_t aux;
    for (j = 1; j < cantElementos; j++)
    {
        for (i = 0; i < cantElementos-j; j++)
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

void punto3(equipo_t equipos[],int matgoles[10][10])
{
    int eq1, eq2;
    int aux[10] ={0};
    int max = 0, pos = -1;
    //primero veo quien metio mas de 3 goles
    for (eq1 = 0; eq1 < 10; eq1++)
    {
        for(eq2 = 0; eq2 < 10; eq2++)
        {
            if(matgoles[eq1][eq2] >= 3)
                aux[eq1]++; 
        }
    }
    //ahora calculo el max
    pos = 0;
    max = aux[0];
    for(eq1 = 1; eq1 < 9; eq1++)
    {
        if(max < aux[eq1])
        {
            max = aux[eq1];
            pos = eq1;
        }
    }
    printf("El equipo que mas veces metio +3 goles es %s\n",equipos[pos].nombre);
}

void restaurar(equipo_t equipos[],int cantElementos)
{
    int j, i = 0;
    equipo_t aux;
    for (j = 1; j < cantElementos; j++)
    {
        for (i = 0; i < cantElementos-j; j++)
        {
            if (equipos[i].codigo > equipos[i+1].codigo)
            {
                aux = equipos[i];
                equipos[i] = equipos[i+1];
                equipos[i+1] = aux;
            }
        }
    }
    return;
}