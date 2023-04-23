#include <stdio.h>
void Promedio();
void Maximo();
void Datos();
void Ingresar();
void Factorial();
void Notas();
void PI();

int main(void)
{
    //21. Ingresar 10 números e informar el promedio.
    Promedio();
    printf("\n");
    //22. Ingresar 10 números e informar el número máximo.
    Maximo();
    printf("\n");
    //23. Ingresar datos finalizando con un número negativo, informar el producto.
    Datos();
    printf("\n");
    //24. Ingresar números, sumarlos.Se termina cuando se ingresó un 0, 
    //informar la cantidad de datos ingresados y los números múltiplos de 3.
    Ingresar();
    printf("\n");
    //25. Realizar un Programa que implemente el Producto de Wallis para hallar una aproximación del Número PI
    //Pi();
    printf("\n");
    //26. Calcular el Factorial de un número leído por teclado.
    Factorial();
    printf("\n");
    //27. Escribir un programa que obtenga la media de las notas obtenidas por un alumno.
    PI(); 
    //Se pueden introducir hasta 4 notas entre 0 y 100 y luego imprimir por teclado la Media y la Categoría.
    Notas();
    printf("\n");
    return 0;
}

void Promedio()
{
    int contador = 1;
    float nota,promedio,resultado;
    while (contador <= 10)
    {
        printf("Ingrese la nota del alumno: \n");
        scanf("%f",&nota);
        resultado += nota;
        contador ++;
    }
    promedio = resultado/10;
    printf("El promedio de las 10 notas fue de, %.2f",promedio);
}

void Maximo()
{
    int contador = 0;
    float maximo,numero;
    for(contador=0;contador<=9;contador++)
    {
        if(contador==0)
        {
            printf("Ingrese un numero: \n");
              scanf("%f",&numero);
              maximo = numero;
              contador ++;
        }
        else
        {
            printf("Ingrese un numero: \n");
            scanf("%f",&numero);
            if (numero > maximo)
            {    maximo = numero;
                contador ++;
            }
    }   }
    printf("El maximo de los numeros fue, %.2f",maximo);
}

void Datos()
{
    float datos,producto=1;
    while (datos >=0)
    {
        printf("Ingrese un numero:");
        scanf("%f",&datos);
        if (datos>= 0)
        {
            producto *= datos;
        }
    }
    printf("El producto de los datos entrantes es de %f",producto);
}

void Ingresar()
{
    int multiplos=0,cont=0,numeros,suma=0;
    while(numeros != 0)
    {
     printf("Ingrese un numero:");
     scanf("%i",&numeros);
     cont ++;
     suma += numeros;
     if((numeros%3)==0)
     {
         multiplos++;
     }   
    }
    printf("La suma de los %i ingresados es %i",cont,suma);
    printf("\n");
    printf("Hay %i multiplos de 3",multiplos);
}

void Factorial()
{
    int num,factorial=1,i;
    printf("Ingrese un numero:\n");
    scanf("%i",&num);
    while (num<0)
    {
        printf("Ingrese un numero:\n");
        scanf("%i",&num);
    }
    for(i=1;i<=num;i++)
    {
        factorial = factorial*i;
    }
    printf("El factorial de %i es: %i\n",num,factorial);
}

void Notas()
{
    float notas,suma,i,media;
    for (i=1;i<=4;i++)
    {
        printf("Ingrese la nota:\n");
        scanf("%f",&notas);
        while (notas<0 && notas>100)
        {
            printf("Ingrese la nota:\n");
            scanf("%f",&notas);
        }
        suma += notas;
    }
    media = suma/40.0;
    if (media<= 10 && media>=9.0)
    {
        printf("El promedio es: %.2f\n",media);
        printf("Categoria A\n");
    }
    else if (media<=8.9 && media>=8.0)
    {
        printf("El promedio es: %.2f\n",media);
        printf("Categoría B\n");
    }
    else if(media>=7.0 && media<=7.9)
    {
        printf("El promedio es: %.2f\n",media);
        printf("Categoría C\n");
    }
    else if(media<=6.9 && media>=6.0)
    {
        printf("El promedio es: %.2f\n",media);
        printf("Categoría D\n");
    }
    else
    {
        printf("El promedio es: %.2f\n",media);
        printf("Categoría E\n");
    }
}

void PI()
{
    int  p,n;
    float multi,produ=1;
    printf("ingresar el valor de p");
    scanf("%i",&p);
    while (p<1)
    {
        printf("ingresar el valor de p");
        scanf("%i",&p);
    }
    for(n=1; n <= p; n++)
    {
        multi=(float)((2*n)*(2*n))/(((2*n)-1)*((2*n)+1));
        produ*=multi;

    }
    printf("el producto es %f",(float)produ);
}