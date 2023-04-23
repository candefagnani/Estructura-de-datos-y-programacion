#include "ListasSE.h"
#include <stdio.h>


pNodo crearNodo(tipo_d dato)
{
    pNodo nuevo;
    nuevo = (pNodo)malloc(sizeof(Nodo));
    nuevo->dato=dato;
    nuevo->sig=NULL;
    return nuevo;
}

tipo_d cargarTipoD(){
    tipo_d dato;
    printf("Ingrese un entero: ");
    scanf("%d",&dato.valor);
    return dato;
}

int leerLista(pNodo *cabeza){
    pNodo aux = *cabeza;
    if (aux == NULL) return 0;
    while(aux!=NULL) {
        printf("%d\n", aux->dato.valor);
        aux = aux->sig;
    }
    return 1;
}

int agregarPpio(pNodo *cabeza, tipo_d d){
    pNodo nuevo = crearNodo(d);
    nuevo->sig = *cabeza;
    *cabeza = nuevo;
    return 1;
}

int agregarFinal(pNodo *cabeza, tipo_d dato){
    pNodo ultimo=*cabeza;
    if(ultimo==NULL){
        *cabeza = crearNodo(dato);
        return 1;
    }
    else{
        ultimo = avanzarHastaPosicion(cabeza,len(cabeza)-1);
        ultimo->sig = crearNodo(dato);
    }
    return 1;
}

int posicion(pNodo *cabeza, tipo_d dato){
    int i=0;
    pNodo aux = *cabeza;
    if(aux==NULL) return -1;
    while(aux->dato.valor != dato.valor){
        aux = aux->sig;
        i++;
        if(aux==NULL){
            return -1;
        }
    }
    return i;
}

pNodo avanzarHastaPosicion(pNodo *cabeza, int k){
    pNodo aux = *cabeza;
    if(k<0){
        aux = NULL;
        return aux;
    }
    int i;
    for(i=0;i<k;i++){
        aux = aux->sig;
    }
    return aux;
}

int in(pNodo *cabeza, tipo_d dato){
    return posicion(cabeza,dato)+1;
}

int agregarEnK(pNodo *cabeza, tipo_d dato, int k)
{
    if (k > len(cabeza) || k<0) return 0;
    pNodo nuevo = crearNodo(dato), aux1, aux2;
    aux1 = avanzarHastaPosicion(cabeza,k-1);
    aux2 = aux1->sig;

    aux1->sig = nuevo;
    nuevo->sig = aux2;
    return 1;
}

int borrarElemento(pNodo *cabeza, int k){
    if(k == 0){
        pNodo aux = *cabeza;
        if(aux==NULL){
            return 0;
        }
        *cabeza = aux->sig;
        free(aux);
        return 1;
    }
    pNodo aux1, aux2;
    aux1 = avanzarHastaPosicion(cabeza,k-1);
    aux2 = aux1->sig;

    if(aux2 != NULL){
        aux1->sig = aux2->sig;
        return 1;
    }
    else{
        aux1 = NULL;
        return 1;
    }
}

int editarElemento(pNodo *cabeza, int k){
    if (k > len(cabeza)) return 0;

    pNodo aux;
    tipo_d nuevo_dato = cargarTipoD();

    aux = avanzarHastaPosicion(cabeza,k);
    aux->dato = nuevo_dato;
    return 1;
}

int len(pNodo *cabeza){
    if (*cabeza == NULL) return 0;

    pNodo aux = *cabeza;
    int i;
    for(i=0;aux;aux=aux->sig){
        i++;
    }
    return i;
}

int swap(pNodo *cabeza, int i, int j){
    if(i>j)
        return swap(cabeza,j,i);    //se diseÃ±an los casos para intercambiar un nodo con otro en una posiciÃ³n posterior
    if(i==j)
        return 1;                  //no hay nada que swappear en este caso
    if(j>=len(cabeza))
    {                 //no puedo acceder a valores fuera del rango de la lista
        printf("Error: limite de la lista excedido\n");
        return 0;
    }
    if(i==0)
    {                         //caso especial donde se modifica la cabeza
        if(j-i!=1)
        {                    //swapear la cabeza por un j generico no consecutiva
            pNodo antj, nodoj, aux, postj;

            antj = avanzarHastaPosicion(cabeza,j-1);
            nodoj = antj->sig;

            aux = *cabeza;
            postj = nodoj->sig;

            nodoj->sig = aux->sig;
            antj->sig = aux;
            aux->sig = postj;
            *cabeza = nodoj;

            return 1;
        }
        else
        {                           //caso especial doble: modifico la cabeza por su consecutivo
            pNodo aux, nodoj, postj;

            aux = *cabeza;
            nodoj = aux->sig;
            postj = nodoj->sig;

            nodoj->sig = aux;
            aux->sig = postj;
            *cabeza = nodoj;

            return 1;
        }
    }

    if(j-i==1)
    {             //caso especial: swapear un nodo por su siguiente (cuando ninguno es la cabeza)
        pNodo  nodoi, anti, nodoj, postj;

        anti = avanzarHastaPosicion(cabeza,i-1);
        nodoi = anti->sig;

        nodoj = nodoi->sig;
        postj = nodoj->sig;

        anti->sig = nodoj;
        nodoj->sig = nodoi;
        nodoi->sig = postj;

        return 1;
    }

    //CASO GENERAL: swapear un nodo i por un nodo j cuando no ocurre nada "raro"

    pNodo  nodoi, nodoj, anti, antj, postj;

    anti = avanzarHastaPosicion(cabeza,i-1);
    nodoi = anti->sig;

    antj = avanzarHastaPosicion(cabeza,j-1);
    nodoj = antj->sig;

    postj = nodoj->sig;

    anti->sig = nodoj;
    nodoj->sig = nodoi->sig;
    antj->sig = nodoi;
    nodoi->sig = postj;

    return 1;
}

int ordenarListaDecreciente(pNodo *cabeza){ //BUBBLE SORT APLICADO A LISTAS
    int i,j, largo = len(cabeza);
    if ( largo <= 1 ) return 1;

    pNodo nodoi , nodoj;
    for(i=0; i<largo-1 ; i++){
        for(j=i+1; j<largo; j++){

            nodoi = avanzarHastaPosicion(cabeza,i);
            nodoj = avanzarHastaPosicion(cabeza,j);

            if(nodoi->dato.valor < nodoj->dato.valor){
                swap(cabeza, i, j);
            }
        }
    }
    return 1;
}

int ordenarListasConjuntas(pNodo *cab1,pNodo *cab2){
    if ( len(cab1) != len(cab2) ) return 0;
    int i, j, largo = len(cab1);
    if ( largo <= 1 ) return 1;
    pNodo nodoi1, nodoj1;

    for(i=0;i<largo-1;i++){
        for(j=i+1; j<largo; j++){
            nodoi1 = avanzarHastaPosicion(cab1,i);
            nodoj1 = avanzarHastaPosicion(cab1,j);

            if(nodoi1->dato.valor < nodoj1->dato.valor){
                swap(cab1,i,j);
                swap(cab2,i,j);
            }
        }
    }
    return 1;
}

int frecuencias(pNodo *cabeza){
    if (*cabeza == NULL) return 0;
    pNodo nodo=*cabeza, valoresUnicos=NULL, frecuencias=NULL, auxVal, auxFreq;
    int k;
    tipo_d inicializador;
    inicializador.valor = 1;
    for(;nodo;nodo=nodo->sig){
        k = posicion(&valoresUnicos,nodo->dato);
        if( k == -1 ){
            agregarFinal(&valoresUnicos,nodo->dato);
            agregarFinal(&frecuencias,inicializador);
        }
        else{
            auxFreq = avanzarHastaPosicion(&frecuencias,k);
            auxFreq->dato.valor++;
        }
    }
    ordenarListasConjuntas(&frecuencias,&valoresUnicos);
    auxVal = valoresUnicos;
    auxFreq = frecuencias;

    printf("valor\tfrecuencia\n");
    for(;auxVal;auxVal=auxVal->sig, auxFreq = auxFreq->sig){
        printf("%d\t%d\n",auxVal->dato.valor,auxFreq->dato.valor);
    }
    return 1;
}
