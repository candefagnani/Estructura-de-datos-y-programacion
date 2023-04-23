#include <stdio.h>
void Mayor(); 
int main(void)
{
    //11. Ingresar 2 números, si a < b informar a*b , en caso contrario a/b
    Mayor();
    printf("\n");
    //12. Ingresar la base y altura de un triángulo y el diámetro de una circunferencia. informar cual es el de mayor superficie.
    float base,altura,diametro,radio;
    float ST,SC;
    printf("Ingrese la altura del triangulo:");
    scanf("%f",&altura);
    printf("Ingrese la base del triangulo:");
    scanf("%f",&base);
    printf("Ingrese el diametro de un circulo:");
    scanf("%f",&diametro);
    ST = (base*altura)/2;
    radio = diametro/2;
    SC = radio*radio*3.14;
    printf("La superficie del trigangulo:%f\n",ST);
    printf("La superficie de la circunferencia:%f\n",SC);
    if (ST > SC)
    {
        printf("El triangulo tiene mayor superficie\n");
    }
    else
    {
        printf("El circulo tiene mayor superficie\n");
    }
    printf("\n");
    //13. Ingresar un número y determinar si pertenece al intervalo -2<x<4
    int num;
    printf("Ingrese un número:");
    scanf("%i",&num);
    if (num>-2 && num<4)
        printf("%i esta en el intervalo (-2,4)",num);
    else
        printf("%i no se escuentra en el intervalo (-2,4)",num);
    printf("\n");
    //14. Ingresar un número e informar si es múltiplo de 7.
    int multiplo;
    printf("Ingrese un número:");
    scanf("%i",&multiplo);
    if (!(multiplo%7))
    {
        printf("El número es multiplo de 7");
    }
    else
        printf("El número no es múltiplo de 7");
    printf("\n");
    //15. Ingresar 4 números enteros e imprima el Mayor de todos.
    int n1,n2,n3,n4,mayor;
    printf("Ingrese un número:");
    scanf("%i",&n1);
    printf("Ingrese un número:");
    scanf("%i",&n2);
    printf("Ingrese un número:");
    scanf("%i",&n3);
    printf("Ingrese un número:");
    scanf("%i",&n4);
    if (n1>n2 && n1>n3 && n1>n4)
        mayor = n1;
    else if (n2>n1 && n2>n3 && n2>n4)
        mayor = n2;
    else if (n3>n1 && n3>n2 && n3>n4)
        mayor = n3;
    else
        mayor = n4;
    printf("El mayor de los números es: %i",mayor);
    printf("\n");
    //16. Ingresar 4 números enteros e imprima el menor de todos.
    int nu1,nu2,nu3,nu4,menor;
    printf("Ingrese un número:");
    scanf("%i",&nu1);
    printf("Ingrese un número:");
    scanf("%i",&nu2);
    printf("Ingrese un número:");
    scanf("%i",&nu3);
    printf("Ingrese un número:");
    scanf("%i",&nu4);
    if (nu1<n2 && nu1<nu3 && nu1<nu4)
        menor = nu1;
    else if (n2<n1 && nu2<nu3 && nu2<nu4)
        menor = n2;
    else if (nu3<nu1 && nu3<nu2 && nu3<nu4)
        menor = nu3;
    else
        menor = nu4;
    printf("El menor de los números es: %i",menor);
    printf("\n");
    //17. Ingresar 4 números enteros e imprimirlos de menor a Mayor.
    return 0;
}
void Mayor()
{
    int a,b;
    printf("Ingrese a:");
    scanf("%i",&a);
    printf("Ingrese b:");
    scanf("%i",&b);
    if(a<b)
        printf("La multiplicacion es: %i",a*b);
    else
        printf("La division es: %i",a/b);
}






//18. Lea 3 Números por teclado y descubra si uno de ellos, es la suma de los otros dos. Debe informar por pantalla indicando qué Número es la suma de los otros dos.
//19. Construir un programa que permita ingresar un Número por teclado y nos diga: Si es positivo, igual que cero o negativo, Si es Par o Impar, Si es Primo.
//20. Ingresar un Dígito por teclado, del 0 al 10, e imprimirlo en Letras: Si Ingreso 1, imprimir “Uno”, si ingreso 2, imprimir “Dos”, y así sucesivamente.