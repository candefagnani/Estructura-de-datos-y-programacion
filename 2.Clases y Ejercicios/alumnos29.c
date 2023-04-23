#include <stdio.h>
/*
	typedef permite asociar un ALIAS a un tipo de dato.
	formato typedef <tipo de dato original> <alias>
*/
//typedef int entero;
typedef struct {
	int d;
	int m;
	int a;
} fecha;

typedef struct{
	int legajo;
	int dni;
	char nombre[50];
	fecha fchNacimiento;
	fecha fchIngreso;
} alumno;

#define CANT_ALUMNOS 3

/*
	Repaso de archivos binarios
*/
//Zona de prototipos
alumno cargarAlumno();

int main(void)
{
	alumno alumnos[CANT_ALUMNOS];
	int i;
	for (i=0; i<CANT_ALUMNOS; i++)
	{
		printf("Ingrese el alumno %d\n", i+1);
		alumnos[i] = cargarAlumno();
	}
	for (i=0; i<CANT_ALUMNOS; i++)
	{
		printf(	"El alumno de legajo %d y dni %d se llama %s\n",
				alumnos[i].legajo,
				alumnos[i].dni,
				alumnos[i].nombre);
	}

	return 0;

}

//<dato que devuelve> nombre_de_la_funcion(parametro(s))

alumno cargarAlumno()

{
	alumno unAlumno;
	printf("Ingrese el legajo:");
	scanf("%d", &unAlumno.legajo);
	printf("Ingrese el DNI:");
	scanf("%d", &unAlumno.dni);
	//Borra todo lo pendiente de lectura del buffer del teclado
	fflush(stdin);
	//Uso el fgetc -funcion que lee UN CARACTER- para leer el enter
	//fgetc(stdin);
	printf("Ingrese el nombre:");
	gets(unAlumno.nombre);
	printf("Fecha de nacimiento (DD/MM/AAAA):");
	scanf("%d/%d/%d", 	&unAlumno.fchNacimiento.d,

						&unAlumno.fchNacimiento.m,

						&unAlumno.fchNacimiento.a);

	printf("Fecha de ingreso (DD/MM/AAAA):");
	scanf("%d/%d/%d", 	&unAlumno.fchIngreso.d,

						&unAlumno.fchIngreso.m,

						&unAlumno.fchIngreso.a);

	return unAlumno;
}