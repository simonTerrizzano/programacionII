#include "pilas.h"
#include "tipo_elemento.c"



struct Nodo{
    TipoElemento datos;
    struct Nodo *siguiente;
};
struct PilaRep{
    struct Nodo *tope;
    unsigned int cant;
};


Pila p_crear() {
    Pila nueva_pila = (Pila) malloc(sizeof(struct PilaRep));
    nueva_pila->tope = NULL;
    nueva_pila->cant=0;
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
    pila->cant++;
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
    pila->cant--;
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

bool p_es_llena(Pila pila){
    return pila->cant==TAMANIO_MAXIMO;
}
bool p_es_vacia (Pila pila) {
    return pila->tope == NULL;
}
void p_mostrar (Pila pila) {
    Pila Paux = p_crear();
    int num=0;
    TipoElemento X;
    printf("Contenido de la pila: ");
    // Recorro la pila desopilándola y pasándola al auxiliar
    while (p_es_vacia(pila) != true) {
        X = p_desapilar(pila);
        printf("%d ", X->clave);
        p_apilar(Paux, X);
    }
    // Recorro la pila auxiliar para pasarla a la original (o bien construyo la utilidad intercambiar)
    while (p_es_vacia(Paux))
    {
        X=p_desapilar(Paux);
        p_apilar(pila,X);
    }
    
    printf("\n");
}