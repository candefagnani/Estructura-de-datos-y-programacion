//RECOPILACION DE FUNCIONES QUE ME VAN A SERVIR PARA EL PARCIAL
#include <stdio.h>

/* CARGAR MATRIZ
void cargarMatriz(float matriz[FILAS][COLUMNAS])
{
    int f,c;
    for (f = 0; f < FILAS; f++)
    {
        for (c = 0; c < COLUMNAS; c++) 
        {
            printf("Ingrese el valor [%i][%i] de la matriz: ", f + 1, c + 1);
            scanf("%f", &matriz[f][c]);
        }
    }
}
*/

/* MOSTRAR MATRIZ
void mostrarMatriz(float matriz[FILAS][COLUMNAS])
{
    int f,c;
    for(f = 0; f < FILAS; f++)
    {
        for(c = 0; c < COLUMNAS; c++)
        {
            printf("%f \t",matriz[f][c]);
        }
        printf("\n");
    }
}
*/

/* BUSCO COSAS
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
*/

/* LONGITUD CADENA
int longitud(char cad[])
{
    int cant = 0;
    while(cad[cant])
        cant++;
    return cant;
}
*/

/* COPIAR CADENA
void copiarCadena(char destino[], char origen[])
{
    int i = 0;
    for (i = 0; i <= longitud(origen); i++)
    {
        if(origen[i] != '\r' && origen[i] != '\n')
            destino[i] = origen[i];
    }
}
*/

/* SACAR ENTER
void sacarEnter(char cad[])
{
    while (*cad){
        if (*cad == "\n")
            cad="\0";
        else
            *cad++;
    }
}
*/

/* COMPARA CADENAS
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
                return 1;
            else
                return -1;
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
                return 1;
            else
                return -1;
        }
        return 0;
    }
}
*/

/* ORDENAR
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
*/

/* PASAR MAYUSCULAS
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
*/

/* PASAR MINUSCULAS
void minusculas(char cadena[])
{
    int i;
    for (i = 0; i < longitud(cadena); i++)
    {
        if (cadena[i]>='A' && cadena[i]<='Z') 
            cadena[i] = cadena[i] + 32;
    }
    printf("cadena en minusculas: %s\n",cadena);      
}
*/

/* BUSQUEDA BINARIA
int busquedaBinaria(int vec[], int cantElementos, int valorABuscar)
{
	int posIni, posFin, medio;
	posIni = 0;
	posFin = cantElementos - 1;
	medio = (posIni + posFin) / 2;
	while (vec[medio] != valorABuscar && posIni <= posFin)
	{
		if (vec[medio] < valorABuscar)
			posIni = medio + 1;
		else
			posFin = medio -1;
		medio = (posIni + posFin) / 2;
	}
	if (posIni <= posFin)
		return medio;
	else
		return -1;
}
*/

/* MI FGETS
void mifgets(char * cad, int lon)
{
	int i;
	fgets( cad, lon, stdin);
	for (i=0; i<lon; i++)
	{
		if (cad[i] == '\n')
			cad[i] = '\0';
	}
	return;
}
*/

/* SAME
int same(char Larga[], char Corta[])
{
    int l1, l2, Hit=0, i, j, pos=0;
    l1=strlen(Larga);     l2=strlen(Corta);
    for(i=0;i<=l1;i++)
        {
         if (Larga[i]==Corta[0])
          {   pos=i;
              for(j=0;j<l2;j++, i++)
                if (Larga[i]==Corta[j]) Hit=1;
                else {Hit=0; break;}
          }
         if (Hit) break;
        }
    if (Hit) return pos;
    else return -1;
}
*/