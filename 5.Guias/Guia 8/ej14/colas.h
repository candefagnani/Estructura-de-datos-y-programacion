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
void sumaColas(Cola cola1, Cola cola2, Cola *colaSuma);

/*
typedef Lista Cola;
int ingresar(Cola * pcola, dato d);
int sacar(Cola * pcola, dato * d);
*/