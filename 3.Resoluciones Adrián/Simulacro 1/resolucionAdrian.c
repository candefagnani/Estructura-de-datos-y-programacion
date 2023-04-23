#include <stdio.h>
#include <string.h>

void sacarEnter(char []);
typedef struct
{
	int codigo;
	char nombre[50];
	int trato;
	int claridad;
	int seguimiento;
	int consultas;
	int examenes;
	float general;
	int cantidadEvaluaciones;
} Docente;

typedef struct
{
	int codigo;
	float trato;
	float claridad;
	float seguimiento;
	float consultas;
	float examenes;
} ep1;

void abrirDocentes(Docente[]);
void abrirEvaluaciones(Docente []);
void copiarCadena(char[], char[]);
void pasarApellidoMayusculas(char[]);

void punto1(Docente []);
void punto2(Docente []);
void punto3(Docente []);
void punto4(Docente []);
void punto5(Docente []);

int main(void)
{
	Docente docentes[25];

	abrirDocentes(docentes);
	abrirEvaluaciones(docentes);

	//Punto 1
	printf("Ejecuto el punto 1...\n");
	punto1(docentes);

	//punto 2
	printf("Ejecuto el punto 2...\n");
	punto2(docentes);

	//punto 3
	printf("Ejecuto el punto 3...\n");
	punto3(docentes);

	//punto 4
	printf("Ejecuto el punto 4...\n");
	punto4(docentes);

	//punto 5
	printf("Ejecuto el punto 5...\n");
	punto5(docentes);

	return 0;
}

void abrirDocentes(Docente docentes[])
{
	FILE *  fDoc;
	int codDocente;
	char nombreDocente[100];
	int i = 0;
	fDoc = fopen("/Users/candefagnani/Desktop/C/Simulacro 1/docentes.txt", "rt");
	if (fDoc != NULL)
	{
		//Leo el codigo de docente que es un numero entero
		fscanf(fDoc, "%d", &codDocente);
		while (!feof(fDoc))
		{
			//Me deshago del caracter en blanco que tiene el archivo
			fgetc(fDoc);

			//Leo el nombre del docente
			fgets(nombreDocente, 100, fDoc);
			sacarEnter(nombreDocente);
			pasarApellidoMayusculas(nombreDocente);

			docentes[i].codigo = codDocente;
			copiarCadena(docentes[i].nombre, nombreDocente);
			docentes[i].trato		= 0;
			docentes[i].claridad	= 0;
			docentes[i].seguimiento	= 0;
			docentes[i].consultas	= 0;
			docentes[i].examenes	= 0;
			docentes[i].general		= 0;
			docentes[i].cantidadEvaluaciones=0;
			i++;

			//Leo el SIGUIENTE codigo de docente
			fscanf(fDoc, "%d", &codDocente);
		}
		fclose(fDoc);
	}
	else
		printf("No se pudo abrir el archivo docentes.txt\n");
}

int buscarDocente(Docente docentes[], int codigoABuscar)
{
	int i, pos=-1;
	for (i=0; i<25; i++)
	{
		if (docentes[i].codigo == codigoABuscar)
		{
			pos = i;
			break;
		}
	}

	return pos;
}

void abrirEvaluaciones(Docente docentes[])
{
	FILE *  fEval;
	int pos, codAlu, codDocente, e1, e2, e3, e4, e5;
	char linea[100];
	fEval = fopen("/Users/candefagnani/Desktop/C/Simulacro 1/evaluacion.txt", "rt");
	//Quiero leer : 100041-12670-9-5-7-1-9
	if (fEval != NULL)
	{
		fgets(linea, 100, fEval);
		while (!feof(fEval))
		{
			sscanf(linea, "%d-%d-%d-%d-%d-%d-%d",
							&codAlu, &codDocente, &e1,&e2,&e3,&e4,&e5);
			/*
				Ahora proceso el docente
				int trato;
				int claridad;
				int seguimiento;
				int consultas;
				int examenes;
				int general;
				int cantidadEvaluaciones;
			*/
			pos = buscarDocente(docentes, codDocente);
			docentes[pos].trato 	  += e1;
			docentes[pos].claridad 	  += e2;
			docentes[pos].seguimiento += e3;
			docentes[pos].consultas   += e4;
			docentes[pos].examenes 	  += e5;
			docentes[pos].general 	  += (float)(e1 + e2 + e3 + e4 + e5)/5;
			docentes[pos].cantidadEvaluaciones++;

			fgets(linea, 100, fEval);
		}
		fclose(fEval);
	}
	else
		printf("No se pudo abrir el archivo docentes.txt\n");

}

void punto1(Docente docentes[])
{
	ep1 vector[25];
	int i;
	FILE * fbin;

	for (i=0; i<25; i++)
	{
		vector[i].codigo = docentes[i].codigo;
		vector[i].trato = (float)docentes[i].trato/docentes[i].cantidadEvaluaciones;
		vector[i].claridad = (float)docentes[i].claridad/docentes[i].cantidadEvaluaciones;
		vector[i].seguimiento= (float)docentes[i].seguimiento/docentes[i].cantidadEvaluaciones;
		vector[i].consultas= (float)docentes[i].consultas/docentes[i].cantidadEvaluaciones;
		vector[i].examenes= (float)docentes[i].examenes/docentes[i].cantidadEvaluaciones;
	}

	fbin = fopen("/Users/candefagnani/Desktop/C/Simulacro 1/consolidado.bin", "wb");
	if (fbin != NULL)
		fwrite(vector, sizeof(ep1), 25, fbin);
	else
		printf("No se pudo crear el archivo consolidado.bin");
	fclose(fbin);
	/*
	for (i=0; i<25; i++)
	{
		vector[i].codigo = 0;
		vector[i].trato = 0;
		vector[i].claridad = 0;
		vector[i].seguimiento= 0;
		vector[i].consultas= 0;
		vector[i].examenes= 0;
	}

	fbin = fopen("Z:\\Corregir\\EDP\\Simulacro1\\consolidado.bin", "rb");
	fread(vector, sizeof(ep1), 25, fbin);
	for (i=0; i<25; i++)
		printf("%d %.2f %.2f %.2f %.2f %.2f\n", 	vector[i].codigo,
										vector[i].trato,
										vector[i].claridad,
										vector[i].seguimiento,
										vector[i].consultas,
										vector[i].examenes);
	fclose(fbin);*/

}

void ordenar(Docente vec[], int cantElementos)
{
	int j, i=0;
	Docente aux;

	for (j=1; j<cantElementos; j++)
	{
		for (i=0; i<cantElementos-j;i++)
		{
			if (strcmp(vec[i].nombre, vec[i+1].nombre) > 0)
			{
				aux = vec[i];
				vec[i] = vec[i+1];
				vec[i+1] = aux;
			}
		}
	}
}

void punto2(Docente docentes[])
{
	int i;
	FILE * ftexto = fopen("/Users/candefagnani/Desktop/C/Simulacro 1/promediogeneral.txt", "wt");
	if (ftexto != NULL)
	{
		ordenar(docentes, 25);
		for (i=0; i<25; i++)
		{
			fprintf(ftexto, "%d %s %.2f\n", docentes[i].codigo,
											docentes[i].nombre,
											(float)docentes[i].general/docentes[i].cantidadEvaluaciones);
		}
		fclose(ftexto);
	}
	else
		printf("No se pudo crear el archivo promediogeneral.txt");
}

void punto3(Docente docentes[])
{
	int i;
	int max=0, pos;
	for (i=0; i<25; i++)
	{
		if (max < docentes[i].general)
		{
			pos = i;
			max = docentes[i].general;
		}
	}
	printf("El promedio maximo es %.2f y es del docente %s\n",
				  (float) docentes[pos].general/docentes[pos].cantidadEvaluaciones,
				  docentes[pos].nombre);
}

void punto4(Docente docentes[])
{
	int i;
	float suma = 0;
	float promedioGeneral, promedio;
	for (i=0; i<25; i++)
		suma += docentes[i].general / docentes[i].cantidadEvaluaciones;

	promedioGeneral = suma / 25;
	printf("El promedio general es %.2f\n", promedioGeneral);

	for (i=0; i<25; i++)
	{
		promedio = docentes[i].general / docentes[i].cantidadEvaluaciones;
		if (promedio < promedioGeneral)
		{
			printf("%s %.2f\n", docentes[i].nombre, promedio);
		}
	}
}

void punto5(Docente docentes[])
{
	int i, pos;
	int max = 0;

	max = 0;
	printf("Evaluo trato...\n");
	for (i=0; i<25; i++)
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
	for (i=0; i<25; i++)
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
	for (i=0; i<25; i++)
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
	for (i=0; i<25; i++)
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
	for (i=0; i<25; i++)
	{
		if (max < docentes[i].examenes)
		{
			max = docentes[i].examenes;
			pos = i;
		}
	}
	printf("El mejor docente en la categoria examenes es %s\n", docentes[pos].nombre);

}



void sacarEnter(char cad[])
{
	while (*cad)
	{
		if (*cad == '\n')
			*cad = '\0';
		else
			cad++;
	}
}

int longitud(char cad[])
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
		destino[i] = origen[i];
}

void pasarApellidoMayusculas(char nombre[])
{
	int i=0;
	while (nombre[i] != ' ')
	{
		if (nombre[i] >= 'a' && nombre[i] <= 'z')
			nombre[i] -= 32;

		i++;
	}
}