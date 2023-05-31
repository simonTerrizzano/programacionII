#include "ejercicio_3.h"

void a_padre_nodo(NodoArbol NA, NodoArbol* NP, TipoElemento te){

    if (NA==NULL){
    }
    else{
        if (NA->hd->datos->clave==te->clave || NA->hi->datos->clave==te->clave)
        {
            *NP=NA;
        }
        else
        {
            a_padre_nodo(n_hijoizquierdo(NA),NP,te);
            a_padre_nodo(n_hijoderecho(NA),NP,te);
        }
    }
}

NodoArbol padre_interfaz(ArbolBinarioBusqueda a, NodoArbol N){
    NodoArbol nodoPadre;
    TipoElemento elemento;
    elemento=n_recuperar(N);
    a_padre_nodo(abb_raiz(a),&nodoPadre,elemento);
    return nodoPadre;
}

void a_hijos_nodo(NodoArbol N){

    if (N->hi==NULL && N->hd==NULL)
    {
        printf("El nodo no tiene hijos.");
    }
    if (N->hi!=NULL)
    {
        printf("El hijo izquiero de %i es %i ", N->datos->clave, N->hi->datos->clave);
    }
    if (N->hd!=NULL)
    {
        printf("El hijo derecho de %i es %i ", N->datos->clave, N->hd->datos->clave);
    } 
}


void a_hermanos_nodo(ArbolBinarioBusqueda a, NodoArbol N){
    NodoArbol padreN;
    TipoElemento elemento;
    elemento = n_recuperar(N);
    padreN=padre_interfaz(a,N);
    if (padreN->hi->datos->clave!=elemento->clave)
    {
        printf("El hermano de %i es %i ",elemento->clave, padreN->hi->datos->clave);
    }
    else{
        printf("El hermano de %i es %i ",elemento->clave, padreN->hd->datos->clave);
    }
}

void a_nodos_mismo_nivel(ArbolBinarioBusqueda a, NodoArbol NA, int alturaBuscada, int claveHermano){

    if (NA==NULL){
    }
    else{
        if (nivel_nodo(a,NA)==alturaBuscada && NA->datos->clave!=claveHermano)
        {
            printf("%i ",NA->datos->clave);
        }
        else
        {
            a_hermanos_nodo(a,n_hijoizquierdo(NA));
            a_hermanos_nodo(a,n_hijoderecho(NA));
        }
    }
}
void nodos_mismo_nivel_interfaz(ArbolBinarioBusqueda a, NodoArbol N){
    TipoElemento elemento;
    elemento = n_recuperar(N);
    int alturaBuscada;
    alturaBuscada=nivel_nodo(a,N);
    if (alturaBuscada!=-1)
    {
        printf("Nodos que están al mismo nivel que %i : ",elemento->clave);
        a_nodos_mismo_nivel(a,abb_raiz(a),alturaBuscada,elemento->clave);
    }
    else
    {
        printf("El nodo indicado no existe en el Arbol");
    }
    
}

void nivelint(NodoArbol Q, int Cbuscada, int *h, int c){
    TipoElemento X;
    if (Q != NULL) {
        X= n_recuperar(Q);
        if (X->clave == Cbuscada) {
            *h = c;
        }else{
            nivelint(n_hijoizquierdo(Q), Cbuscada, h, c+1);
            nivelint(n_hijoderecho(Q), Cbuscada, h, c+1);
        }
    }
}

int nivel_nodo(ArbolBinarioBusqueda A, NodoArbol N){
    int nivel = -1;
    nivelint(abb_raiz(A), N->datos->clave, &nivel, 0);
    return nivel;
}

void altint(NodoArbol Q, int *h, int c){
    if (Q == NULL) {
        if (c > *h) {
            *h = c;
        }
    }
    else {
        altint(n_hijoizquierdo(Q), h, c+1);
        altint(n_hijoderecho(Q), h, c+1);
    }
}

int altura_sub_arbol_interfaz(ArbolBinarioBusqueda a, NodoArbol N){
    int alt = 0;
    altint(N, &alt, 0);
    return alt;
}
