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
	FILE * falu;
	falu = fopen("c:\\temp\\alumnos.bin", "wb");
	if (falu != NULL)
	{
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
		/*
		fwrite(	que grabo,
				tamaño del tipo de dato,
				cantidad de elementos que grabo,
				en qué archivo);*/
		//grabo todo el contenido del vector
		fwrite(alumnos, sizeof(alumno), CANT_ALUMNOS, falu);
		fclose(falu);
	}
	getch();
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
typedef struct
{
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

	FILE * falu;



	falu = fopen("c:\\temp\\alumnos.bin", "rb");



	if (falu != NULL)

	{

		//Leo todo el contenido del archivo de una vez

		fread(alumnos, sizeof(alumno), CANT_ALUMNOS, falu);



		for (i=0; i<CANT_ALUMNOS; i++)

		{

			printf(	"El alumno de legajo %d y dni %d se llama %s\n",

					alumnos[i].legajo,

					alumnos[i].dni,

					alumnos[i].nombre);

		}



		fclose(falu);

	}



	getch();



	return 0;

}

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

	alumno alu;

	int i;

	FILE * falu;



	falu = fopen("c:\\temp\\alumnos.bin", "rb");



	if (falu != NULL)

	{

		//Leo todo el contenido del archivo de una vez

		fread(&alu, sizeof(alumno), 1, falu);

		while (!feof(falu))

		{

			printf(	"El alumno de legajo %d y dni %d se llama %s\n",

					alu.legajo,

					alu.dni,

					alu.nombre);

			fread(&alu, sizeof(alumno), 1, falu);

		}



		fclose(falu);

	}



	getch();



	return 0;

}

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

	alumno alu;

	int i;

	FILE * falu;



	falu = fopen("c:\\temp\\alumnos.bin", "rb");



	if (falu != NULL)

	{

		/*

			fseek(	archivo,

					cuanto hay que moverse,

					desde donde***)



			***

			SEEK_CUR permite "moverse" x bytes DESDE DONDE ESTÉ en el archivo

			SEEK_SET permite "moverse" x bytes DESDE EL COMIENZO del archivo

			SEEK_END permite "moverse" x bytes DESDE EL FIN del archivo





		*/

		fseek(falu, 0, SEEK_END);

		printf("Posicion %d \n", ftell(falu));

		printf("Cantidad de alumnos en el archivo %d \n", ftell(falu)/sizeof(alumno));



		fclose(falu);

	}



	getch();



	return 0;

}


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

	alumno alu;

	int i, opc;

	FILE * falu;



	falu = fopen("c:\\temp\\alumnos.bin", "r+b");



	if (falu != NULL)

	{

		//Leo todo el contenido del archivo de una vez

		fread(&alu, sizeof(alumno), 1, falu);

		while (!feof(falu))

		{

			printf(	"El alumno de legajo %d y dni %d se llama %s\n",

					alu.legajo,

					alu.dni,

					alu.nombre);



			printf("Ingrese 1 para modificar:");

			scanf("%d", &opc);

			if (opc == 1)

			{

				alu = cargarAlumno();



				fseek(falu, 0, SEEK_CUR);

				fwrite(&alu, sizeof(alumno), 1, falu);



				fclose(falu);

				return 0;

			}



			fread(&alu, sizeof(alumno), 1, falu);

		}



		fclose(falu);

	}



	getch();



	return 0;

}



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

	scanf("%d/%d/%d",  &unAlumno.fchNacimiento.d,

						&unAlumno.fchNacimiento.m,

						&unAlumno.fchNacimiento.a);



	printf("Fecha de ingreso (DD/MM/AAAA):");

	scanf("%d/%d/%d",  &unAlumno.fchIngreso.d,

						&unAlumno.fchIngreso.m,

						&unAlumno.fchIngreso.a);

	return unAlumno;

 }