//hacer una funcion que reciba 20220322 y me devuelva 22; 03 y 22
#include <stdio.h>

void incrementarValor(int * n);
void SeparaFecha(int fecha, int *dd, int *mm, int *aa);


int main (void)
{
    int nro1, nro2,fecha;
    int dd,mm,aa;
	nro1 = 15;
	nro2 = 33;
	incrementarValor(&nro1);
	printf("Nro 1: %d\n", nro1);
	incrementarValor(&nro2);
	printf("Nro 2: %d\n", nro2);  
    //////////////////////////////
    printf("Ingrese una fecha (formato = AAAAMMDD):\n");
    scanf("%i",&fecha);
    SeparaFecha(fecha,&dd,&mm,&aa);
    printf("La fecha es %02d/%02d/%04d\n",dd,mm,aa);
    
    return 0;
}


void incrementarValor(int * n)
{
	(*n)++;
}

void SeparaFecha(int fecha, int *dd, int *mm, int *aa)
{
    *dd = fecha % 100;
    fecha = fecha / 100;
    *mm = fecha % 100;
    *aa = fecha / 100;  
}

