#include "Ejercicio_9.h"

ArbolAVL abb_a_avl_interfaz(ArbolBinarioBusqueda a){
    ArbolAVL avl=avl_crear();
    NodoArbol raiz_abb;
    raiz_abb=abb_raiz(a);
    abb_a_avl(raiz_abb,&avl);

    return avl;
}

void abb_a_avl(NodoArbol nodo_abb,ArbolAVL* avl){
    TipoElemento elemento;
    if (nodo_abb == NULL) {
    }
    else {
        elemento = n_recuperar(nodo_abb);
        avl_insertar(*avl,elemento);
        abb_a_avl(n_hijoizquierdo(nodo_abb), avl);
        abb_a_avl(n_hijoderecho(nodo_abb), avl);
    }
}


