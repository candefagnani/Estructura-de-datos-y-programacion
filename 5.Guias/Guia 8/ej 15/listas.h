typedef struct
{
    int numero;
} dato;
//Estructuras especificas para listas
struct nodo
{
    dato num;
    struct nodo * sig; //lo hago circular al nodo
};
typedef struct nodo Nodo;
typedef Nodo * Lista; //lo hago para no usar punteros a punteros
//FIN -- Estructura especificas para listas

void agregaPrincipio(Lista *pcabeza,Lista agregado);
void mostrarLista(Lista plst);
void agregaFinal(Nodo **pcabeza,Nodo *agregado);
int eliminarPrincipio(Lista * plst);
void mostrarYVaciarLista(Lista plst);
int eliminarFinal(Lista * plst);
void producto(Lista plst);
int leeElementos(Lista plst);
void EliminarNodo(Lista *plst, int numAEliminar);
int buscaMaximo(Lista plst);
int BuscarNodo(Lista *plst, int numABuscar);
Lista creaNodo(int numero);