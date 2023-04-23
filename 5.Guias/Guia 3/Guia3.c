#include <stdio.h>
#include <math.h>
int TRIANG(lado1,lado2,lado3)
{
    int respuesta;
    if(lado1==lado2 && lado2==lado3)
        respuesta = 1; //ver esto
    else if(lado1==lado2 && lado2!=lado3 || lado2==lado3 && lado3!=lado1 || lado3==lado1 && lado1!=lado2)
        respuesta = 2;
    else
        respuesta = 3;
    return (respuesta);
}
double betaf(float altura, float base, float hipot)
{
	double beta = acos(base/hipot);
	beta*=180/3.141596;
	return beta;
}
double xgammaf(double xbeta)
{
	double xgamma = 90.0-xbeta;
	return xgamma;
}
int MENU()
{
    int op;
    printf("1.Suma \n""2.Resta\n""3.Multiplicacion\n");
    printf("Que operacion desea realizar? \n");
    scanf("%i",&op);
    while(op != 1 && op!= 2 && op != 3)
    {
        printf("1.Suma \n""2.Resta\n""3.Multiplicacion\n");
        printf("Que operacion desea realizar? \n");
        scanf("%i",&op);
    }
    return op;
}

int main(void)
{
    //28. Realizar un programa que lea los lados a,b,c de un triángulo y Realizar una
    //función que informe si conforman triángulo. 
    //29. Realizar una función que lo clasifique en isósceles, equilátero o escaleno.
    int lado1,lado2,lado3,rta;
    printf("Tipos de triangulos: esquilatero, escaleno, isosceles\n");
    printf("Introduce el lado 1:\n");
    scanf("%i",&lado1);
    printf("Introduce el lado 2:\n");
    scanf("%i",&lado2);
    printf("Introduce el lado 3:\n");
    scanf("%i",&lado3);
    rta = TRIANG(lado1,lado2,lado3);
    switch(rta)
    {
        case 1:
        {
            printf("Los lados forman un trigangulo equilatero\n");
            break;
        }
        case 2:
        {
            printf("Los lados forman un triganulo isosceles\n");
            break;
        }
        case 3:
        {
            printf("Los lados forman un triangulo escaleno\n");
            break;
        }
    }
    
    //30. Dado un triángulo rectángulo cuyos lados son: base=3, altura=4, hipot=5.
    //Calcular matemáticamente los ángulos con una o más funciones.
    float base = 3, altura = 4, hipot = 5;
	double alpha, xbeta, xgamma;
	alpha = 90;
	xbeta = betaf(altura, base, hipot);
	xgamma = xgammaf(xbeta);
	printf("El angulo ab es %.2lf\nel angulo bh e %.2lf\nel anguno ah es %.2lf\n", alpha, xbeta, xgamma);
    //31. Escribir un programa que realice las siguientes tareas: Leer 2 números reales ,
    //llame a una función menú() con 4 opciones + - * /, realizar la operación 
    //correspondiente y mostrar el resultado.
    float a,b;
    int RTA;
    printf("Ingrese el primer numero: ");
    scanf("%f",&a);
    printf("Ingrese el segundo numero: ");
    scanf("%f",&b);
    RTA = MENU();
    if (RTA == 1)
    {
        printf("La suma de %.2f con %.2f es de %.2f",a,b,(a+b));
    }
    else if(RTA == 2)
    {
        printf("La resta de %.2f con %.2f es %.2f",a,b,(a-b));
    }
    else
    {
        printf("El producto de %.2f con %.2f es de %.2f",a,b,(a*b));
    }
    printf("\n");
    return 0;
}





