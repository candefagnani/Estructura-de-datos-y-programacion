#include <stdio.h>
#include <stdlib.h>
#define EQUIPOS 10 //En equipos.txt veo que hay 10 equipos

//Estructuras
typedef struct
{
    int codigo;
    char nombre[50];
    int golesAFavor;
    int golesEnContra;
    int puntos;
    int triplete;
} equipo_t;

typedef struct
{
    int posicionEquipoA;
    int posicionEquipoB;
    int golEquipoA;
    int golEquipoB;
}partido_t;

typedef struct 
{   int posicion, puntos, GE, GF;
    float promedio;
    char nombre[50];
} matriz_t;

typedef struct 
{   int posicion, puntos, GE, GF;
    float promedio;
    char nombre[50];
} auxiliar_t;

typedef struct 
{   int triples;
    char nombre[50];
} triple_t;

//Zona de prototipos
void AbreEquipos(equipo_t []);
void copiarCadena(char [], char[]);
//void AbreIntegrantes(equipo_t []);
void AbrePartidos(equipo_t [], partido_t []);
void sacarEnter(char[]);
int buscarEquipo(equipo_t[], int);
void punto1(equipo_t[], partido_t[]);
void puntaje(equipo_t[], partido_t[]);
void cargarmatriz(equipo_t[], matriz_t[]);
void ordenarmatriz(matriz_t[], auxiliar_t[]);
void mostrarmatriz(matriz_t[]);
void triple(equipo_t[], triple_t []);
void punto4(matriz_t[], partido_t[]);

//Main
int main (void)
{
    equipo_t equipos[EQUIPOS];
    partido_t partidos[45];
    matriz_t matriz[EQUIPOS];
    auxiliar_t auxiliar[EQUIPOS];
    triple_t max[1];
    AbreEquipos(equipos);
    //AbreIntegrantes(equipos);
    AbrePartidos(equipos, partidos);
    printf("\n");

    //Punto 1
    printf("Ejecuto el punto 1...\n");
    punto1(equipos, partidos);

    //Punto 2
    printf("Ejecuto el punto 2...\n");
    puntaje(equipos, partidos);
    cargarmatriz(equipos, matriz);
    ordenarmatriz(matriz,auxiliar);
    mostrarmatriz(matriz);
    printf("\n");

    //Punto3
    printf("Ejecuto el punto 3...\n");
    triple(equipos,max);
    printf("Equipo %s que mas veces metio 3 goles o mas por partido, en total %i \n", max[0].nombre, max[0].triples);
    printf("\n");

    //Punto 4
    printf("Ejecuto el punto 4...\n");
    punto4(matriz,partidos);
    printf("<3\n");
    return 0;
}

void AbreEquipos(equipo_t equipos[])
{
    FILE* fEq;
    int i = 0;
    fEq = fopen("/Users/candefagnani/Desktop/C/Simulacro2/equipos.txt","rt");
    if (fEq != NULL)
    {
        puts("El archivo equipos.txt se abrio correctamente\n");
        fscanf(fEq, "%d", &equipos[i].codigo); 
        while (!feof(fEq))
        {
            fgetc(fEq); //saco la coma
            fgets(equipos[i].nombre, 20, fEq);
            sacarEnter(equipos[i].nombre);
            equipos[i].golesAFavor = 0;
            equipos[i].golesEnContra = 0;
            i++;
            fscanf(fEq, "%d", &equipos[i].codigo);
        }
        fclose(fEq);   
    }
    else
        puts("El archivo equipos.txt no se abrio correctamente\n");
}

void AbrePartidos(equipo_t equipos[], partido_t partidos[])
{
    FILE* fPartidos;
    int t = -1, A, B, numgol, jugador;
    char linea[16];
    fPartidos = fopen("/Users/candefagnani/Desktop/C/Simulacro2/partidos.txt","rt");
    if (fPartidos != NULL)
    {
        puts("El archivo partidos.txt se pudo abrir correctamente\n");
        while (!feof(fPartidos))
        {   
            fgets(linea, 20, fPartidos);
            sacarEnter(linea);
            printf("%s",linea);
            if(linea[0] == 'P')
            {
                sscanf(linea,"Partido:%d vs %d", &A, &B);
                t++;
                partidos[t].golEquipoA = 0;
                partidos[t].golEquipoB = 0;
                numgol = -1;
            }
            else
                sscanf(linea, "%d,%d", &numgol, &jugador);
            partidos[t].posicionEquipoA = buscarEquipo(equipos, A);
            partidos[t].posicionEquipoB = buscarEquipo(equipos, B);
            if (numgol == A)
            {
                partidos[t].golEquipoA++;
                equipos[partidos[t].posicionEquipoA].golesAFavor++;
                equipos[partidos[t].posicionEquipoB].golesEnContra++;
            }
            else if(numgol == B)
            {
                partidos[t].golEquipoB++;
                equipos[partidos[t].posicionEquipoB].golesAFavor++;
                equipos[partidos[t].posicionEquipoA].golesEnContra++;  
            }
        }
        fclose(fPartidos);
    }
    else
        puts("El archivo partidos.txt no se pudo abrir correctamente\n");
    
    if (t < 45)
    {
        sscanf(linea, "%d,%d", &numgol, &jugador);
        if (numgol == A)
            {
                partidos[t].golEquipoA++;
                equipos[partidos[t].posicionEquipoA].golesAFavor++;
                equipos[partidos[t].posicionEquipoB].golesEnContra++;
            }
            else if(numgol == B)
            {
                partidos[t].golEquipoB++;
                equipos[partidos[t].posicionEquipoB].golesAFavor++;
                equipos[partidos[t].posicionEquipoA].golesEnContra++;  
            }
    }
}

void punto1(equipo_t equipos[], partido_t partidos[])
{
    int i = 0;
    printf("Resultados de los partidos:");
    for (i = 0; i < 45; i++)
    {
        printf("\n%s <%d> - <%d> %s", equipos[partidos[i].posicionEquipoA].nombre, partidos[i].golEquipoA, partidos[i].golEquipoB, equipos[partidos[i].posicionEquipoB].nombre);
    }
}

void puntaje(equipo_t equipos[], partido_t partidos[])
{
    int i = 0;
    for (i = 0; i < 45; i++)
    {
        equipos[partidos[i].posicionEquipoA - 1].puntos = 0;
        equipos[partidos[i].posicionEquipoB - 1].puntos = 0;
    }
    for (i = 0; i < 45; i++)
    {
        if(partidos[i].golEquipoA > partidos[i].golEquipoB)
        {
            equipos[partidos[i].posicionEquipoA - 1].puntos += 3;
        }
        else if(partidos[i].golEquipoA < partidos[i].golEquipoB)
        {
            equipos[partidos[i].posicionEquipoB - 1].puntos += 3;
        }
        else if(partidos[i].golEquipoA == partidos[i].golEquipoB )
        {
            equipos[partidos[i].posicionEquipoB - 1].puntos += 1;
            equipos[partidos[i].posicionEquipoA - 1].puntos += 1;
        }
    }
}

void cargarmatriz(equipo_t equipos[], matriz_t matriz[])
{
    int i = 0;
    for(i = 0; i < EQUIPOS; i++)
    {
        matriz[i].posicion = i+1;
        copiarCadena(matriz[i].nombre, equipos[i].nombre);
        sacarEnter(matriz[i].nombre);
        matriz[i].puntos = equipos[i].puntos;
        matriz[i].GF = equipos[i].golesAFavor;
        matriz[i].GE = equipos[i].golesEnContra;
        matriz[i].promedio = (float)equipos[i].golesAFavor/9;
    }
}

void ordenarmatriz(matriz_t matriz[], auxiliar_t auxiliar[])
{
    int i = 0, j = 0;
    for(i = 0; i < (EQUIPOS-1); i++)
    {
        for(j = (i+1); j < EQUIPOS; j++)
        {
            if(matriz[i].puntos < matriz[j].puntos)
            {
                copiarCadena(auxiliar[0].nombre, matriz[i].nombre);
                copiarCadena(matriz[i].nombre, matriz[j].nombre);
                copiarCadena(matriz[j].nombre, auxiliar[0].nombre);
                auxiliar[0].posicion = matriz[j].posicion;
                matriz[j].posicion = matriz[i].posicion;
                matriz[i].posicion = auxiliar[0].posicion;
                auxiliar[0].puntos = matriz[j].puntos;
                matriz[j].puntos = matriz[i].puntos;
                matriz[i].puntos = auxiliar[0].puntos;
                auxiliar[0].GE = matriz[j].GE;
                matriz[j].GE = matriz[i].GE;
                matriz[i].GE = auxiliar[0].GE;
                auxiliar[0].GF = matriz[j].GF;
                matriz[j].GF = matriz[i].GF;
                matriz[i].GF = auxiliar[0].GF;
                auxiliar[0].promedio = matriz[j].promedio;
                matriz[j].promedio = matriz[i].promedio;
                matriz[i].promedio = auxiliar[0].promedio;
            }
        }
    }
    for(i = 0; i < (EQUIPOS-1); i++)
    {
        for(j = (i+1); j < EQUIPOS; j++)
        {
            if(matriz[i].puntos == matriz[j].puntos)
            {
                if(matriz[i].GF < matriz[j].GF)
                {
                    copiarCadena(auxiliar[0].nombre, matriz[i].nombre);
                    copiarCadena(matriz[i].nombre, matriz[j].nombre);
                    copiarCadena(matriz[j].nombre, auxiliar[0].nombre);
                    auxiliar[0].posicion = matriz[j].posicion;
                    matriz[j].posicion = matriz[i].posicion;
                    matriz[i].posicion = auxiliar[0].posicion;
                    auxiliar[0].puntos = matriz[j].puntos;
                    matriz[j].puntos = matriz[i].puntos;
                    matriz[i].puntos = auxiliar[0].puntos;
                    auxiliar[0].GE = matriz[j].GE;
                    matriz[j].GE = matriz[i].GE;
                    matriz[i].GE = auxiliar[0].GE;
                    auxiliar[0].GF = matriz[j].GF;
                    matriz[j].GF = matriz[i].GF;
                    matriz[i].GF = auxiliar[0].GF;
                    auxiliar[0].promedio = matriz[j].promedio;
                    matriz[j].promedio = matriz[i].promedio;
                    matriz[i].promedio = auxiliar[0].promedio;
                }
            }
        }
    }
    for(i = 0; i < (EQUIPOS-1); i++)
    {
        for(j = (i+1); j < EQUIPOS; j++)
        {
            if(matriz[i].puntos == matriz[j].puntos)
            {
                if(matriz[i].GF == matriz[j].GF)
                {
                    if(matriz[i].GE < matriz[j].GE)
                    {
                        copiarCadena(auxiliar[0].nombre, matriz[i].nombre);
                        copiarCadena(matriz[i].nombre, matriz[j].nombre);
                        copiarCadena(matriz[j].nombre, auxiliar[0].nombre);
                        auxiliar[0].posicion = matriz[j].posicion;
                        matriz[j].posicion = matriz[i].posicion;
                        matriz[i].posicion = auxiliar[0].posicion;
                        auxiliar[0].puntos = matriz[j].puntos;
                        matriz[j].puntos = matriz[i].puntos;
                        matriz[i].puntos = auxiliar[0].puntos;
                        auxiliar[0].GE = matriz[j].GE;
                        matriz[j].GE = matriz[i].GE;
                        matriz[i].GE = auxiliar[0].GE;
                        auxiliar[0].GF = matriz[j].GF;
                        matriz[j].GF = matriz[i].GF;
                        matriz[i].GF = auxiliar[0].GF;
                        auxiliar[0].promedio = matriz[j].promedio;
                        matriz[j].promedio = matriz[i].promedio;
                        matriz[i].promedio = auxiliar[0].promedio;
                    }
                }
            }
        }
    }
    for(i = 0; i < (EQUIPOS-1); i++)
    {
        for(j = (i+1); j < EQUIPOS; j++)
        {
            if(matriz[i].puntos == matriz[j].puntos)
            {
                if(matriz[i].GF == matriz[j].GF)
                {
                    if(matriz[i].GE == matriz[j].GE)
                    {
                        if(matriz[i].promedio < matriz[j].promedio)
                        {
                            copiarCadena(auxiliar[0].nombre, matriz[i].nombre);
                            copiarCadena(matriz[i].nombre, matriz[j].nombre);
                            copiarCadena(matriz[j].nombre, auxiliar[0].nombre);
                            auxiliar[0].posicion = matriz[j].posicion;
                            matriz[j].posicion = matriz[i].posicion;
                            matriz[i].posicion = auxiliar[0].posicion;
                            auxiliar[0].puntos = matriz[j].puntos;
                            matriz[j].puntos = matriz[i].puntos;
                            matriz[i].puntos = auxiliar[0].puntos;
                            auxiliar[0].GE = matriz[j].GE;
                            matriz[j].GE = matriz[i].GE;
                            matriz[i].GE = auxiliar[0].GE;
                            auxiliar[0].GF = matriz[j].GF;
                            matriz[j].GF = matriz[i].GF;
                            matriz[i].GF = auxiliar[0].GF;
                            auxiliar[0].promedio = matriz[j].promedio;
                            matriz[j].promedio = matriz[i].promedio;
                            matriz[i].promedio = auxiliar[0].promedio;
                        }
                    }
                }
            }
        }
    }
}

void mostrarmatriz(matriz_t matriz[])
{
    int i = 0;
    printf("Posicion      Equipo      Puntos      GF    GE    Promedio\n");
    for (i = 0; i < EQUIPOS; i++)
    {
        printf("%d\t", matriz[i].posicion);
        printf("%s\t", matriz[i].nombre);
        printf("%d\t", matriz[i].puntos);
        printf("%d\t", matriz[i].GF);
        printf("%d\t", matriz[i].GE);
        printf("%.2f\t", matriz[i].promedio);
    }
}

int buscarEquipo(equipo_t equipos[], int codigoABuscar)
{
	int i = 0, pos=-1;
	for (i=0; i<10; i++)
	{
		if (equipos[i].codigo == codigoABuscar)
		{
			pos = i;
			break;
		}
	}
	return pos;
}

void copiarCadena(char destino[],char origen[])
{
    int i;
	for (i=0; origen[i] != '\0' ; i++)
		destino[i] = origen[i];
}

void sacarEnter(char cad[])
{
    while (*cad){
        if (*cad == "\n")
            cad="\0";
        else
            *cad++;
    }
}

void triple(equipo_t equipos[], triple_t max[])
{
   int i = 0;
   max[0].triples = equipos[0].triplete;
   copiarCadena(max[0].nombre, equipos[0].nombre);
   for(i = 0; i < EQUIPOS; i++)
   {
       if(equipos[i].triplete > max[0].triples)
       {
           max[0].triples = equipos[i].triplete;
           copiarCadena(max[0].nombre, equipos[i].nombre);
       }
   }
}

void punto4(matriz_t matriz[], partido_t partidos[]) //no me lo imprime ver que onda
{
    int i = 0;
    for (i = 0; i < 45; i++)
    {
        if(matriz[0].posicion == partidos[i].posicionEquipoA)
        {
            printf("goles anotados <%i> vs <%i> goles recibidos \n", partidos[i].golEquipoA, partidos[i].golEquipoB);
        }
        else if(matriz[0].posicion == partidos[i].posicionEquipoB)
        {
            printf("goles anotados <%i> vs <%i> goles recibidos \n", partidos[i].golEquipoB, partidos[i].golEquipoA);
        }
    }
}


/*
void AbreIntegrantes(equipo_t equipos[])
{
    FILE* fIntegrantes; 
    fIntegrantes = fopen("/Users/candefagnani/Desktop/C/Simulacro2/integrantes.txt","rt");
    if (fIntegrantes != NULL)
    {
        puts("El archivo integrantes.txt se pudo abrir correctamente\n");
    }
    else
        puts("El archivo integrantes.txt no se pudo abrir correctamente\n");
}
*/