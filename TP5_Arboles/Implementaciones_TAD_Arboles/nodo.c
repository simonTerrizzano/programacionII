#include "nodo.h"


NodoArbol n_hijoizquierdo(NodoArbol N){
    return N->hi->datos;
}


NodoArbol n_hijoderecho(NodoArbol N){
    return N->hd->datos;
}


NodoArbol n_crear(TipoElemento te){
    NodoArbol nuevo_nodo = (NodoArbol) malloc(sizeof(struct NodoArbolRep));
    nuevo_nodo->datos = te;
    nuevo_nodo->hd = NULL;
    nuevo_nodo->hi = NULL;
    nuevo_nodo->FE=0;
}


TipoElemento n_recuperar(NodoArbol N){
    return N->datos;
}