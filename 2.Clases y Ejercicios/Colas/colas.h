typedef struct 
{
    int numero;
} dato;
struct nodo
{
    dato d;
    struct nodo * sig; 
};
typedef struct nodo Nodo;
typedef Nodo * Cola;

int agregarPrincipio(Cola * plst, dato d); 
int agregar(Cola * plst, dato unDato);
int sacar(Cola * pcola, dato * d);
int eliminarPrincipio(Cola * plst);

/*
typedef Lista Cola;
int ingresar(Cola * pcola, dato d);
int sacar(Cola * pcola, dato * d);
*/