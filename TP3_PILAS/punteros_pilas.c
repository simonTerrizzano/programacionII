#include <stdio.h>
#include <stdlib.h>
#include "pilas.h"
#include "tipo_elemento.h"
#define TAMANIO_MAXIMO 100
struct Nodo{
    TipoElemento datos;
    struct Nodo *siguiente;
};
struct PilaRep{
    struct Nodo *tope;
};


Pila p_crear() {
    Pila nueva_pila = (Pila) malloc(sizeof(struct PilaRep));
    nueva_pila->tope = NULL;
    return nueva_pila;
}


void p_apilar (Pila pila, TipoElemento elemento) {
    if (p_es_llena(pila))
    {
        return;
    }
    
    struct Nodo *nuevo_nodo = malloc(sizeof(struct Nodo));
    nuevo_nodo->datos = elemento;
    nuevo_nodo->siguiente = pila->tope;
    pila->tope = nuevo_nodo;

}
TipoElemento p_desapilar (Pila pila) {
    if (p_es_vacia(pila))
    {
        return NULL;
    }
    struct Nodo *tope_actual = pila->tope;
    TipoElemento elemento = tope_actual->datos;
    pila->tope = tope_actual->siguiente;
    free(tope_actual);
    return elemento;
}
TipoElemento p_tope (Pila pila) {
    if (p_es_vacia(pila))
    {
        return NULL;
    }    
    struct Nodo *tope_actual = pila->tope;
    return tope_actual->datos;
}

int longitud(Pila pila){
    int i=0;
    struct Nodo *N = pila->tope;

    while (N != NULL)
    {
        i++;
        N=N->siguiente;
    }
    return i;
    
}

bool p_es_llena(Pila pila){
    return (longitud(pila)==TAMANIO_MAXIMO);
}
bool p_es_vacia (Pila pila) {
    return pila->tope == NULL;
}


void p_mostrar(Pila pila){
    Pila P_aux=p_crear();
    TipoElemento elemento;
    if (p_es_vacia(pila))
    {
        printf("La pila está vacia");
        return;
    }
    
    printf("Contenido de la pila: ");

    while (p_es_vacia(pila)!=true)
    {
        elemento=p_desapilar(pila);
        printf("%i ",elemento->clave);
        p_apilar(P_aux,elemento);
    }

    while (p_es_vacia(P_aux)!=true)
    {
        elemento=p_desapilar(P_aux);
        p_apilar(pila,elemento);
    }
    
    
}
