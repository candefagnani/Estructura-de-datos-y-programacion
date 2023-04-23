#include <stdio.h>
int main(void)
{
    float a,b;
    int operacion;
    printf("Ingrese el primer numero:");
    scanf("%f",&a);
    printf("Ingrese el segundo numero:");
    scanf("%f",&b);
    printf("1.Suma \n""2.Resta\n""3.Multiplicacion\n""4.Division\n");
    printf("Que operacion desea realizar?");
    scanf("%i",&operacion);
    while(operacion != 1 && operacion!= 2 && operacion != 3 && operacion!=4)
    {
        printf("1.Suma \n""2.Resta\n""3.Multiplicacion\n""4.Division\n");
        printf("Que operacion desea realizar?");
        scanf("%i",&operacion);
    }
    if (operacion == 1)
    {
        printf("La suma de %f con %f es de %f",a,b,(a+b));
    }
    else if(operacion == 2)
    {
        printf("La resta de %f con %f es %f",a,b,(a-b));
    }
    else if(operacion == 3)
    {
        printf("El producto de %f con %f es de %f",a,b,(a*b));
    }
    else
   {
       if(b != 0)
       {
           printf("la division de %f con %f es de %f",a,b,(a/b));
       }
       else
       {
           printf("La division no se puede realizar ya que el segundo numero es %f",b);
       }
   }
   printf("\n");
    return 0;
}
//suma-resta-multiplicacion-division