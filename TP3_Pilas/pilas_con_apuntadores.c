#include "pilas.h"

Pila p_crear() {
    Pila nueva_pila = (Pila) malloc(sizeof(struct PilaRep));
    nueva_pila->tope = NULL;
    return nueva_pila;
}
void p_apilar (Pila pila, TipoElemento elemento) {
    struct Nodo *nuevo_nodo = malloc(sizeof(struct Nodo));
    nuevo_nodo->datos = elemento;
    nuevo_nodo->siguiente = pila->tope;
    pila->tope = nuevo_nodo;
}
TipoElemento p_desapilar (Pila pila) {
    struct Nodo *tope_actual = pila->tope;
    TipoElemento elemento = tope_actual->datos;
    pila->tope = tope_actual->siguiente;
    free(tope_actual);
    return elemento;
}
TipoElemento p_tope (Pila pila) {
    struct Nodo *tope_actual = pila->tope;
    return tope_actual->datos;
}
bool p_es_vacia (Pila pila) {
    return pila->tope == NULL;
}
void p_mostrar (Pila pila) {
    Pila Paux = p_crear();
    TipoElemento X = crear_te(0);
    printf("Contenido de la pila: ");
    // Recorro la pila desopilándola y pasándola al auxiliar
    while (p_es_vacia(pila) != true) {
        X = p_desapilar(pila);
        printf("%d ", X->clave);
    p_apilar(Paux, X);
    }
    // Recorro la pila auxiliar para pasarla a la original (o bien construyo la utilidad intercambiar)
    while (p_es_vacia(Paux) != true) {
        X = p_desapilar(Paux);
        p_apilar(pila, X);
    }
    printf("\n");
}