#include "conjuntos.h"
#include "listas.h"
#include <stdlib.h>

struct ConjuntoRep {
    Lista lista;
};

Conjunto cto_crear() {
    Conjunto conjunto = (Conjunto) malloc(sizeof(struct ConjuntoRep));
    conjunto->lista = l_crear();
    return conjunto;
}

bool cto_es_vacio(Conjunto conjunto) {
    return l_es_vacia(conjunto->lista);
}

bool cto_es_lleno(Conjunto conjunto){
    return l_es_llena(conjunto->lista);
}

int cto_cantidad_elementos(Conjunto conjunto) {
    return l_longitud(conjunto->lista);
}

void cto_agregar(Conjunto conjunto, TipoElemento elemento) {
    if (l_buscar(conjunto->lista, elemento->clave) == NULL) {
        l_agregar(conjunto->lista, elemento);
    }
}

void cto_borrar(Conjunto conjunto, int clave) {
    l_borrar(conjunto->lista, clave);
}

bool cto_pertenece(Conjunto conjunto, int clave) {
    Iterador iter = iterador(conjunto->lista);
    TipoElemento elemento;
    while (hay_siguiente(iter)) {
        elemento = siguiente(iter);
        if (elemento->clave == clave) {
            break;
        }
    }
    free(iter);

    return elemento->clave == clave;
}

Conjunto cto_union(Conjunto conjunto_a, Conjunto conjunto_b) {
    Conjunto resultado = cto_crear();
    Iterador iter = iterador(conjunto_a->lista);
    while (hay_siguiente(iter)) {
        cto_agregar(resultado, siguiente(iter));
    }
    free(iter);

    iter = iterador(conjunto_b->lista);
    while (hay_siguiente(iter)) {
        cto_agregar(resultado, siguiente(iter));
    }
    free(iter);

    return resultado;
}

Conjunto cto_interseccion(Conjunto conjunto_a, Conjunto conjunto_b) {
    Conjunto resultado = cto_crear();
    Iterador iter = iterador(conjunto_a->lista);
    while (hay_siguiente(iter)) {
        TipoElemento elemento = siguiente(iter);
        if (cto_pertenece(conjunto_b, elemento->clave)) {
            cto_agregar(resultado, elemento);
        }
    }
    free(iter);
    return resultado;
}

Conjunto cto_diferencia(Conjunto conjunto_a, Conjunto conjunto_b) {
    Conjunto resultado = cto_crear();
    Iterador iter = iterador(conjunto_a->lista);
    while (hay_siguiente(iter)) {
        TipoElemento elemento = siguiente(iter);
        if (!cto_pertenece(conjunto_b, elemento->clave)) {
            cto_agregar(resultado, elemento);
        }
    }
    free(iter);
    return resultado;
}

TipoElemento cto_recuperar(Conjunto conjunto, int posicion_ordinal){
    return l_recuperar(conjunto->lista, posicion_ordinal);
}

void cto_mostrar(Conjunto conjunto){
    l_mostrarLista(conjunto->lista);
}
