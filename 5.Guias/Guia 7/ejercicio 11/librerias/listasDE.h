//LISTAS DOBLEMENTE ENLAZADAS
//Estructura que tiene el dato que quiero guardar en la lista
//Aca definimos el tipo de dato que vamos a trabajar
typedef struct{
    char string[100];
} dato;
//-------------FIN Definicion tipo de dato a trabajar

//Estructuras especificas para listas
struct nodo
{
    dato d;
    struct nodo * ant;
    struct nodo * sig;
};
typedef struct nodo Nodo;
typedef Nodo * Lista;
//---FIN Estructuras especificas para listas

int agregarPrincipio(Lista * plst, dato d);
int agregarFinal(Lista * plst, dato d);
int eliminarPrincipio(Lista * plst);
int eliminarFinal(Lista * plst);
int insertar(Lista *pLst,dato d);
int eliminar(Lista *plst,dato d);

int Siguiente(Lista *plst);
int Anterior(Lista *plst);

int esIgual(dato d1,dato d2);
int insertarAqui(dato d1,dato d2);

void mostrarLista(Lista plst);
void mostrarYVaciarLista(Lista plst);
void mostrarElemento(dato d);

//Del ejercicio 11
int leeElementos(Lista plst);
int BuscarNodo(Lista *plst, char *StringABuscar);
void mayusculas(char cadena[]);
void minusculas(char cadena[]);
int longitud(char cad[]);
