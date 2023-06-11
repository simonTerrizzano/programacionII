#include "ejercicio_2.h"

Lista hoja_interfaz(ArbolBinarioBusqueda a){
    Lista LR = l_crear();
    a_retornar_hojas(abb_raiz(a),LR);

    return LR;
}

void a_retornar_hojas(NodoArbol N, Lista LR){

    TipoElemento elemento;

    if (N == NULL) {
    }
    else {
        if ((n_hijoizquierdo(N) == NULL) && (n_hijoderecho(N) == NULL)) {
            elemento = n_recuperar(N);
            l_agregar(LR,elemento);
        }
        a_retornar_hojas(n_hijoizquierdo(N),LR);
        a_retornar_hojas(n_hijoderecho(N),LR);
    }

}

Lista interior_interfaz(ArbolBinarioBusqueda a){
    Lista LR = l_crear();
    a_retornar_interiores(abb_raiz(a),LR);
    l_eliminar(LR,1);
    return LR;
}

void a_retornar_interiores(NodoArbol N, Lista LR){

    TipoElemento elemento;


    if (N == NULL) {
    }
    else {
        if ((n_hijoizquierdo(N) == NULL) ^ (n_hijoderecho(N) == NULL)) {
            
            elemento = n_recuperar(N);
            l_agregar(LR,elemento);
        }
        a_retornar_interiores(n_hijoizquierdo(N),LR);
        a_retornar_interiores(n_hijoderecho(N),LR);
    }

}

Lista ocurrencia_interfaz(ArbolBinarioBusqueda a,TipoElemento elemento_buscado){
    Lista LR = l_crear();
    a_retornar_ocurrencias(abb_raiz(a),LR, elemento_buscado);

    return LR;
}

void a_retornar_ocurrencias(NodoArbol N, Lista LR,TipoElemento elemento_buscado){
    TipoElemento elemento;


    if (N == NULL) {
    }
    else {
        if (N->datos==elemento) {
            
            elemento = n_recuperar(N);
            l_agregar(LR,elemento);
        }
        a_retornar_ocurrencias(n_hijoizquierdo(N),LR,elemento_buscado);
        a_retornar_ocurrencias(n_hijoderecho(N),LR,elemento_buscado);
    }
}
