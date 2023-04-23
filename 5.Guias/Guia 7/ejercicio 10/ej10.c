#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Estructura que tiene el dato que quiero guardar en la lista
typedef struct 
{
    int numero;
} dato;

//Estructuras especificas para listas
struct nodo
{
    dato d;
    struct nodo * sig; //lo hago circular al nodo
};
typedef struct nodo Nodo;
typedef Nodo * Lista; //lo hago para no usar punteros a punteros
//FIN -- Estructura especificas para listas

int MENU();
int agregarPrincipio(Lista * plst, dato unDato);
void mostrarLista(Lista plst);
int agregarFinal(Lista * plst, dato unDato);
void producto(Lista plst);
int leeElementos(Lista plst);
void EliminarNodo(Lista *plst, int numAEliminar);
int buscaMaximo(Lista plst);
int BuscarNodo(Lista *plst, int numABuscar);
int calculaFrecuencia(Lista *plst);
int presencia(int *cadena, int dato);

int main (void)
{
    Lista lista = NULL;
    Lista Elementos = NULL, frecuencias = NULL;
    dato unNumero;
    int opcion, numABuscar, numAEliminar, elementos,max;

    printf("Ingrese numero para agregar  a lista, -1 para finalizar:\t");
    scanf("%d",&unNumero.numero);
    while(unNumero.numero != -1)
    {
        agregarFinal(&lista, unNumero);
        printf("Ingrese nuevo numero:\t");
        scanf("%d",&unNumero.numero);
    }
    printf("Los elementos de la lista son:\n");
    mostrarLista(lista);
    opcion = MENU();
    while (opcion <=9)
    {
        switch (opcion)
        {
            case 1: //Agregar un Elemento
            {
                printf("Ingrese numero para agregar  a lista:\t");
                scanf("%d",&unNumero.numero);
                agregarFinal(&lista, unNumero);
                break;
            }
            case 2: //Borrar un Elemento
            {
                printf("Que numero desea borrar de su lista\n");
                scanf("%d",&numAEliminar);
                EliminarNodo(&lista,numAEliminar);
                printf("Ahora la lista queda:\n");
                mostrarLista(lista);
                break;
            }
            case 3: //Buscar un Elemento
            {
                printf("Que numero desea buscar?\n");
                scanf("%d",&numABuscar);
                if(BuscarNodo(&lista,numABuscar))
                {
                    printf("El numero %d fue encontrado en la lista\n",numABuscar);
                }
                else
                {
                    printf("El numero %d no fue encontrado en la lista\n",numABuscar);
                }
                break;
            }
            case 4: //Mostrar los Elementos de la Lista
            {
                mostrarLista(lista);
                break;
            }
            case 5: //informar el número máximo.
            {
                max = buscaMaximo(lista);
                printf("El numero maximo de la lista es: %d\n",max);
                break;
            }
            case 6: //informar el producto.
            {
                producto(lista);
                break;
            }
            case 7: //Cantidad de Elementos Leídos
            {
                elementos = leeElementos(lista);
                printf("La cantidad de elementos de su lista es de %d\n",elementos);
                break;
            }
            case 8: //Frecuencia de los elementos
            {
                calculaFrecuencia(&lista);
                break;
            }
        }
        opcion = MENU();
        if(opcion==9) 
        {
            puts("Programa finalizado.\n");
            break;
        }
    }
    return 0;
}

int agregarPrincipio(Lista * plst, dato unDato)
{
    Nodo * nvo;
    nvo = (Nodo *) malloc(sizeof(Nodo));
    if (!nvo)
        return 0;
    nvo->d = unDato;
    nvo->sig = * plst;
    *plst = nvo;

    return 1;
};

int agregarFinal(Lista * plst, dato unDato)
{
    Nodo * nvo, *aux;
    if (*plst == NULL)
        return agregarPrincipio(plst, unDato);

    nvo = (Nodo*) malloc(sizeof(Nodo));
    if (!nvo) return 0;
    nvo->d = unDato;
    nvo->sig = NULL;
    aux = *plst;
    while (aux->sig != NULL)
        aux = aux->sig;
    aux->sig = nvo;
    return 1;
};

void mostrarLista(Lista plst)
{
    Lista aux;
    aux = plst;
    while (aux != NULL)
    {
        printf("%d\t", aux->d.numero);
        aux = aux->sig;
    }
};

int MENU()
{
    int opcion;
    printf("\nElija una de las siguientes opciones\n");
    printf("1) Agregar un Elemento\n2) Borrar un Elemento\n3) Buscar un Elemento\n4) Mostrar los Elementos de la Lista\n5) informar el número máximo\n6) informar el producto\n7) Cantidad de Elementos Leídos\n8) Frecuencia de los elementos\n9) Salir del programa\n");
    scanf("%d",&opcion);
    while(opcion < 1 || opcion > 9)
    {
        printf("Elija una de las siguientes opciones\n");
        printf("1) Agregar un Elemento\n2) Borrar un Elemento\n3) Buscar un Elemento\n4) Mostrar los Elementos de la Lista\n5) informar el número máximo\n6) informar el producto\n7) Cantidad de Elementos Leídos\n8) Frecuencia de los elementos\n9) Salir del programa\n");
        scanf("%d",&opcion);
    }
    return opcion;
};

void producto(Lista plst)
{
    int producto = 1;
    Lista aux;
    aux = plst;
    while(aux != NULL)
    {
        producto *= (aux->d.numero);
        aux = aux->sig;
    }
    printf("El producto es %d\n",producto);
};

int leeElementos(Lista plst)
{
    int elementos = 0;
    Lista aux;
    aux = plst;
    while(aux != NULL)
    {
        elementos++;
        aux = aux->sig;
    }
    return elementos;
};

void EliminarNodo(Lista *plst, int numAEliminar)
{
    Nodo *aux;
    Nodo *prev;
    aux = *plst;
    if(aux != NULL && aux->d.numero == numAEliminar)
    {
        *plst = aux->sig;
        free(aux);
        return;   
    }
    while(aux != NULL && aux->d.numero != numAEliminar)
    {
        prev = aux;
        aux = aux->sig;
    }
    if (aux == NULL)
        return;
    prev->sig = aux->sig;
    free(aux);
};

int buscaMaximo(Lista plst)
{
    Lista aux;
    int max;
    aux = plst;
    max = aux->d.numero;
    while(aux != NULL)
    {
        if((aux->d.numero) > max)
            max = aux->d.numero;
        aux = aux->sig;
    }
    return max;
};

int BuscarNodo(Lista *plst, int numABuscar)
{
        Nodo *aux;
        aux = *plst;
        while(aux != NULL)
        {
            if(aux->d.numero == numABuscar)
                return 1;
            aux = aux->sig;
        }
        return 0;
};

int presencia(int *cadena, int dato)
{
    int i=0;
    int hit;
    while (cadena[i] != '\0'){
        if (dato == cadena[i]){
            hit =0;
            return hit;
        }
        i++;
    }
    hit=1;
    return hit;
};

int calculaFrecuencia(Lista *plst)
{
    int *numeros;
    int principio = 1;
    numeros=(int *) malloc(sizeof(int));
    int i=0;
    Nodo *aux1,*aux2;
    aux1 = *plst;
    aux2 = *plst;
    int dato, contador = 0;
    while (aux1 != NULL){
        dato = aux1->d.numero;
        if (presencia(numeros,dato) || principio)
        {
            if (principio)
            {
                principio = 0;
                numeros[i] = dato;
            }
            else
            {
                i++;
                numeros = (int *)realloc(numeros,sizeof(int)*(i+1));
                numeros[i] = dato;
            }
            while(aux2 != NULL){
                if (dato == aux2->d.numero){
                    contador++;
                }
                aux2=aux2->sig;
            }
            printf("El elemento %d se repite %d veces\n",dato,contador);
            contador=0;
            aux2=*plst;
        }
        aux1=aux1->sig;
    }
    return 1;
};
