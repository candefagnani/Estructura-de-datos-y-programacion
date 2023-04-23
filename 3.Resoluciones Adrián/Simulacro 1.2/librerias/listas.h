#define LISTAS_STRUCT

#ifdef  LISTAS_STRUCT
typedef struct
{
    int numeroVendedor;
    float comisionVendedor;
    char nombreVendedor[50];
    int CantproductosVendidos;
    float totalVendido;
} dato;
#endif
//-------------FIN Definicion tipo de dato a trabajar

//Estructuras especificas para listas
struct nodo
{
    dato d;
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

int esIgual(dato d1,dato d2);
int insertarAqui(dato d1,dato d2);

void mostrarLista(Lista plst);
void mostrarYVaciarLista(Lista plst);
void mostrarElemento(dato d);

void producto(Lista plst);
int leeElementos(Lista plst);
void EliminarNodo(Lista *plst, int numAEliminar);
int buscaMaximo(Lista plst);
int BuscarNodo(Lista *plst, int numABuscar);

