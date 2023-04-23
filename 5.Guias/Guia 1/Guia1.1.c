#include <stdio.h>
void EsMayor();
void ElPromedio();
void Division();
int main(void)
{
    //1.Imprimir un cartel que diga “Hello world”.
    printf("Hello world");
    printf("\n");
    //2. Dadas la base y altura de un rectángulo imprimir su superficie.
    int a = 3;
    int b = 4;
    printf("\n");
    printf("El area del rectangulo de %i cm y %i cm es de %i cm2",a,b,a*b);
    printf("\n");
    //3. Dado el radio de una circunferencia informar su perímetro y superficie.
    float r = 3;
    printf("El perimetro de la circunferencia es de %f y su superficie %f",r*3.14,3.14*r*r);
    printf("\n");
    //4. Ingresar tres números, informar su suma y producto.
    int entero1,entero2,entero3, suma,producto;
    printf("Ingrese el primer entero:");
    scanf("%i",&entero1);
    printf("Ingrese el segundo entero:");
    scanf("%i",&entero2);
    printf("Ingrese el tercer entero:");
    scanf("%i",&entero3);
    suma = entero1 + entero2 + entero3;
    producto = entero1*entero2*entero3;
    printf("La suma de %i con %i y %i es de %i",entero1,entero2,entero3,suma);
    printf("El producto de %i con %i y %i es de %i",entero1,entero2,entero3,producto);
    printf("\n");
    //5. Ingresar tres números, informar su promedio.
    int ent1,ent2,ent3,sum,promedio;
    printf("Ingrese el primer entero:");
    scanf("%i",&ent1);
    printf("Ingrese el segundo entero:");
    scanf("%i",&ent2);
    printf("Ingrese el tercer entero:");
    scanf("%i",&ent3);
    sum = ent1 + ent2 + ent3;
    promedio = (suma)/3;
    printf("El promedio de %i con %i y %i es de %i",ent1,ent2,ent3,promedio);
    printf("\n");
    //6. Ingresar 2 valores numericos que corresponden a hs y min y convertirlos en minutos
    int horas,minutos;
    printf("Ingrese una cantidad de horas:\n");
    scanf("%i",&horas);
    printf("Ingrese una cantidad de minutos:\n");
    scanf("%i",&minutos);
    printf("%i horas y %i minutos suman: %i",horas,minutos,((horas*60)+minutos));
    printf("\n");
    //7. Ingresar tres números, informar el Mayor.
    int num1,num2,num3;
    printf("Ingrese el primer numero entero:");
    scanf("%i",&num1);
    printf("Ingrese el segundo numero entero:");
    scanf("%i",&num2);
    printf("Ingrese el tercer numero entero:");
    scanf("%i",&num3);
    if (num1>num2 && num1>num3)
    {
        printf("%i es el mayor",num1);
    }
    else if (num2>num1 && num2>num3)
    {
        printf("%i es el mayor",num2);
    }
    else
    {
        printf("%i es el mayor",num3);
    }
    printf("\n");
    //8. Ingresar tres números, imprimirlos en Orden Descendente y Ascendente.
    EsMayor();
    printf("\n");
    //9. Ingresar 4 números, calcular su promedio e informar si el Promedio forma parte de los Números ingresados.
    ElPromedio();
    printf("\n");
    //10. Ingresar 2 Números A y B, informar la división y su resto.
    Division();
    printf("\n");
    return 0;
}

void Division()
{
    int A,B;
    int resto,div;
    printf("Ingrese A:\n");
    scanf("%i",&A);
    printf("Ingrese B:\n");
    scanf("%i",&B);
    div = A/B;
    resto = A%B;
    printf("La división de %i,%i es %i",A,B,div);
    printf("El resto es %i",resto);
}

void ElPromedio()
{
    int a,b,c,d;
    float prom;
    printf("Ingrese a:\n");
    scanf("%i",&a);
    printf("Ingrese b:\n");
    scanf("%i",&b);
    printf("Ingrese c:\n");
    scanf("%i",&c);
    printf("Ingrese d:\n");
    scanf("%i",&d);
    prom = (a+b+c+d)/4;
    printf("El promedio de los 4 números es: %f",prom);
}

void EsMayor()
{
    int n1,n2,n3;
    int mayor;
    int medio;
    int menor;
    printf("Ingrese el primer numero entero:");
    scanf("%i",&n1);
    printf("Ingrese el segundo numero entero:");
    scanf("%i",&n2);
    printf("Ingrese el tercer numero entero:");
    scanf("%i",&n3);
    if (n1>n2 && n1>n3)
    {
        mayor = n1;
        if(n2>n3)
        {
            medio = n2;
            menor = n3;
        }
        else
        {
            medio = n3;
            menor = n2;
        }
    }
    if (n2>n1 && n2>n3)
    {
        mayor = n2;
        if(n1>n3)
        {
            medio = n1;
            menor = n3;  
        }
        else
        {
            medio = n3;
            menor = n1;
        }
    }
    else
    {
        mayor = n3;
        if (n1 > n2)
        {
            medio = n1;
            menor = n2;
        }
        else
        {
            medio = n2;
            menor = n1;
        }
    }
    printf("De manera descendente: %i,%i,%i\n",mayor,medio,menor);
    printf("\n");
    printf("De manera ascendente: %i,%i,%i\n",menor,medio,mayor);
}