#include <stdio.h>
#include <stdlib.h>
#define D 25

//Zona de prototipos
typedef struct{
    int codigo;
    char nombre[50];
    int trato;
    int claridad;
    int seguimiento;
    int consultas;
    int examenes;
    float general;
    float CantDeEvaluaciones;
} docente_t;

typedef struct{
    int codigo;
    float trato;
    float claridad;
    float seguimiento;
    float consultas;
    float examenes;
} ep1_t;

void AbrirDocentes(docente_t []);
void AbrirAlumnos(docente_t []);
void pasarApellidoMayusculas(char[]);
void copiarCadena(char[], char[]);
int longitud(char[]);
int buscarDocente(docente_t[], int);
void ordenar(docente_t[], int);
int comparaCadena(char [], char[]);

void punto1(docente_t []);
void punto2(docente_t[]);
void punto3(docente_t[]);
void punto4(docente_t[]);
void punto5(docente_t []);

//Main
int main(void)
{
    docente_t docentes[D];

    AbrirDocentes(docentes);
    AbrirAlumnos(docentes);

    //Punto 1
    printf("Ejecuto el punto 1...\n");
    punto1(docentes);

    //Punto 2
    printf("Ejecuto el punto 2...\n");
    punto2(docentes);

    //Punto 3
    printf("Ejecuto el punto 3...\n");
    punto3(docentes);

    //Punto 4
    printf("Ejecuto el punto 4...\n");
    punto4(docentes);

    //Punto 5
    printf("Ejecuto el punto 5...\n");
    punto5(docentes);
    return 0;
}

void AbrirDocentes(docente_t docentes[])
{
    FILE* fdoc;
    int codDocente = 0, i = 0;
    char NombreDocente[100];
    fdoc = fopen("/Users/candefagnani/Desktop/C/Simulacro 1/docentes.txt","rt");
    if (fdoc != NULL)
    {
        puts("Se abrio el archivo correctamente\n");
        fscanf(fdoc,"%d",&codDocente);
        while (!feof(fdoc))
        {
            fgetc(fdoc);
            fgets(NombreDocente,100,fdoc);
            //tengo que pasar el apellido a mayusculas
            pasarApellidoMayusculas(NombreDocente);
            //pongo todo en la estructura
            docentes[i].codigo = codDocente;
            copiarCadena(docentes[i].nombre, NombreDocente);
            docentes[i].trato = 0;
            docentes[i].claridad = 0;
            docentes[i].seguimiento = 0;
            docentes[i].consultas = 0;
            docentes[i].examenes = 0;
            docentes[i].general = 0;
            docentes[i].CantDeEvaluaciones = 0;
            i++;
            fscanf(fdoc,"%d",&codDocente);
        }
        fclose(fdoc);
    }
    else
    {
        puts("No se pudo abrir el archivo docentes.txt\n");
    }
    return;
}

void AbrirAlumnos(docente_t docentes[])
{
    FILE* feval;
    int pos, codAlumno, codDocente, e1, e2, e3, e4, e5;
    char linea[100];
    feval = fopen("/Users/candefagnani/Desktop/C/Simulacro 1/evaluacion.txt","rt");
    if (feval != NULL)
    {
        puts("El archivo se abrio correctamente\n");
        fgets(linea,100,feval);
        while (!feof(feval))
        {
            sscanf(linea,"%d-%d-%d-%d-%d-%d-%d",&codAlumno,&codDocente,&e1,&e2,&e3,&e4,&e5);
            pos = buscarDocente(docentes,codDocente);
            docentes[pos].trato += e1;
            docentes[pos].claridad += e2;
            docentes[pos].seguimiento += e3;
            docentes[pos].consultas += e4;
            docentes[pos].examenes += e5;
            docentes[pos].general += (float)(e1+e2+e3+e4+e5)/5;
            docentes[pos].CantDeEvaluaciones += 1;
            fgets(linea,100,feval);
        }
        fclose(feval);
    }
    else
    {
        puts("El archivo evaluacion.txt no se pudo abrir \n");
    }
}

void punto1(docente_t docentes[])
{
    FILE* fbin;
    ep1_t vector[D];
    int i = 0;

    for (i = 0; i < D; i++)
    {
        vector[i].codigo = docentes[i].codigo;
        vector[i].trato = (float)docentes[i].trato/docentes[i].CantDeEvaluaciones;
        vector[i].claridad = (float)docentes[i].claridad/docentes[i].CantDeEvaluaciones;
        vector[i].seguimiento = (float)docentes[i].seguimiento/docentes[i].CantDeEvaluaciones;
        vector[i].consultas = (float)docentes[i].consultas/docentes[i].CantDeEvaluaciones;
        vector[i].examenes = (float)docentes[i].examenes/docentes[i].CantDeEvaluaciones;
    }
    fbin = fopen("/Users/candefagnani/Desktop/C/Simulacro 1/consolidado.bin", "wb");
    if (fbin != NULL)
    {
        fwrite(vector,sizeof(ep1_t),D,fbin);
    }
    else
    {
        puts("No se pudo crear el archivo consolidado.bin \n");
    }
    fclose(fbin);
}

void punto2(docente_t docentes[])
{
    FILE* txt;
    int i = 0;
    txt = fopen("/Users/candefagnani/Desktop/C/Simulacro 1/promediogeneral.txt", "wt");
    if (txt != NULL)
    {
        ordenar(docentes,D);
        for (i = 0; i < D; i++)
        {
            fprintf(txt, "%d %s %.2f \n", docentes[i].codigo, docentes[i].nombre, (float)docentes[i].general/(float)docentes[i].CantDeEvaluaciones);
        }
        fclose(txt);
    }
    else
    {
        puts("No se pudo crear el archivo promediogeneral.txt\n");
    }
}

void punto3(docente_t docentes[])
{
    int i = 0, max = 0, pos = 0;
    for (i = 0; i < D; i++)
    {
        if (max < docentes[i].general)
        {
            max = docentes[i].general;
            pos = i;
        }
    }
    printf("El docente que tiene mayor promedio es %s, con un promedio de %.2f \n", docentes[pos].nombre, (float)docentes[pos].general/docentes[pos].CantDeEvaluaciones);
}

void punto4(docente_t docentes[])
{
    int i = 0;
    float suma = 0.0, promedioGeneral = 0, promedio = 0;
    for (i = 0; i < D; i++)
    {
        suma += docentes[i].general / docentes[i].CantDeEvaluaciones;
    }
    promedioGeneral = suma / (float)D;
    printf("El promedio general es de %.2f\n", promedioGeneral);
    for (i = 0; i < D; i++)
    {
        promedio = docentes[i].general / docentes[i].CantDeEvaluaciones;
        if (promedio < promedioGeneral)
        {
            printf("%s %.2f \n", docentes[i].nombre, promedio);
        }
    }
}

void punto5 (docente_t docentes[])
{
    int i, pos, max = 0;
    printf("Evaluo trato...\n");
    for (i = 0; i < D; i++)
    {
        if (max < docentes[i].trato)
        {
            max = docentes[i].trato;
            pos = i;
        }
    }
    printf("El mejor docente en la categoria trato es %s\n", docentes[pos].nombre);

    max = 0;
    printf("Evaluo claridad...\n");
    for (i = 0; i < D; i++)
    {
        if (max < docentes[i].claridad)
        {
            max = docentes[i].claridad;
            pos = i;
        }
    }
    printf("El mejor docente en la categoria claridad es %s\n", docentes[pos].nombre);

    max = 0;
    printf("Evaluo seguimiento...\n");
    for (i = 0; i < D; i++)
    {
        if (max < docentes[i].seguimiento)
        {
            max = docentes[i].seguimiento;
            pos = i;
        }
    }
    printf("El mejor docente en la categoria seguimiento es %s\n", docentes[pos].nombre);

    max = 0;
    printf("Evaluo consultas...\n");
    for (i = 0; i < D; i++)
    {
        if (max < docentes[i].consultas)
        {
            max = docentes[i].consultas;
            pos = i;
        }
    }
    printf("El mejor docente en la categoria consultas es %s\n", docentes[pos].nombre);

    max = 0;
    printf("Evaluo examenes...\n");
    for (i = 0; i < D; i++)
    {
        if (max < docentes[i].examenes)
        {
            max = docentes[i].examenes;
            pos = i;
        }
    }
    printf("El mejor docente en la categoria examentes es %s\n", docentes[pos].nombre);
}

int buscarDocente(docente_t docentes[], int codigoABuscar)
{
    int i = 0, pos = -1;
    for (i = 0; i < D; i++)
    {
        if(docentes[i].codigo == codigoABuscar)
        {
            pos = i;
            break;
        }
    }
    return pos;
}

void pasarApellidoMayusculas(char nombre[])
{
    int i = 0;
    while (nombre[i] != ' ')
    {
        if (nombre[i] >= 'a' && nombre[i] <= 'z')
        {
            nombre[i] -= 32;
        }
        i++;
    }
}

void copiarCadena(char destino[],char origen[])
{
    int i;
	for (i=0; origen[i] != '\0' ; i++)
		destino[i] = origen[i];
}

int longitud(char cad[])
{
    int cant =0;
    while (cad[cant])
    {
        cant++;
    }
    return cant;
}

void ordenar(docente_t vec[], int cantElementos)
{
	int j = 1, i=0;
	docente_t aux;

	for (j = 1; j < cantElementos; j++)
	{
		for (i = 0; i < cantElementos-j;i++)
		{
			if (comparaCadena(vec[i].nombre, vec[i+1].nombre) > 0)
			{
				aux = vec[i];
				vec[i] = vec[i+1];
				vec[i+1] = aux;
			}
		}
	}
}

int comparaCadena(char vector1[], char vector2[])
{
    int i = 0;
    int longitud1 = 0 , longitud2 = 0;
    longitud1 = longitud(vector1);
    longitud2 = longitud(vector2);
    if (longitud1 > longitud2)
    {
        for (i = 0; i < longitud2; i++)
        {
            if (vector1[i] == vector2[i])
            {
    
            }
            else if (vector1[i] > vector2[i])
            {
                return 1;
            }
            else
            {
                return -1;
            }
        }
        return 0;
    }
    else
    {
        for (i = 0; i < longitud1; i++)
        {
            if (vector1[i] == vector2[i])
            {
    
            }
            else if (vector1[i] > vector2[i])
            {
                return 1;
            }
            else
            {
                return -1;
            }
        }
        return 0;
    }
}