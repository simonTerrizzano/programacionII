#include "listas.h"
#include <stdlib.h>
#include <stdio.h>

static const int TAMANIO_MAXIMO_LISTAS = 200;

struct ListaRep {
    TipoElemento *valores;
    int cantidad;
};

struct IteradorRep {
    Lista lista;
    int posicionActual;
};


//-----------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------
// Rutinas del TAD
//-----------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------

Lista l_crear() {
    Lista nueva_lista = (Lista) malloc(sizeof(struct ListaRep));
    // TODO hacer flexible y que la lista crezca sola
    nueva_lista->valores = (TipoElemento*)calloc(TAMANIO_MAXIMO_LISTAS, sizeof(TipoElemento));
    nueva_lista->cantidad = 0;
    return nueva_lista;
}

bool l_es_vacia(Lista lista) {
    return (lista->cantidad == 0);
}

bool l_es_llena(Lista lista) {
    return (lista->cantidad == TAMANIO_MAXIMO_LISTAS);
}

int l_longitud(Lista lista) {
    return lista->cantidad;
}

void l_agregar(Lista lista, TipoElemento elemento) {
    if (l_es_llena(lista)) {
        return;
    }
    lista->valores[lista->cantidad] = elemento;
    lista->cantidad++;
}

void l_borrar(Lista lista, int clave) {
    if (l_es_vacia(lista)) {
        return;
    }

    int pos = 0;
    while (pos < lista->cantidad) {
        if (lista->valores[pos]->clave == clave) {
            for (int i = pos; i < lista->cantidad - 1; i++) {
                lista->valores[i] = lista->valores[i + 1];
            }
            lista->cantidad--;
        } else {
            pos++;
        }
    }
}

TipoElemento l_buscar(Lista lista, int clave) {
    int pos = 0;
    while (pos < lista->cantidad) {
        if (lista->valores[pos]->clave == clave) {
            return lista->valores[pos];
        }
        pos++;
    }
    return NULL;
}

void l_insertar(Lista lista, TipoElemento elemento, int pos) {
    if (l_es_llena(lista)) {
        return;
    }
    // Controlo que si pos > cantidad de elementos lo agrega al final
    if (pos > l_longitud(lista)) {
        l_agregar(lista, elemento);
        return;
    }
    // Ahora si lo puede insertar
    for (int i = lista->cantidad; i >= pos && i > 0; i--) {
        lista->valores[i] = lista->valores[i - 1];
    }
    lista->valores[pos - 1] = elemento;
    lista->cantidad++;
}

void l_eliminar(Lista lista, int pos) {
    if (pos > l_longitud(lista)) {
        return;
    }
    // Ahora intento eliminar
    if (1 <= pos && pos <= l_longitud(lista)) {
        for (int i = pos - 1; i < lista->cantidad; i++) {
            lista->valores[i] = lista->valores[i + 1];
        }
        lista->cantidad--;
    }
}

TipoElemento l_recuperar(Lista lista, int pos) {
    if (pos > l_longitud(lista)) {
        return NULL;
    }
    return lista->valores[pos - 1];
}

void l_mostrarLista(Lista lista) {
    printf("Contenido de la lista: ");
    for (int i = 0; i < lista->cantidad; i++) {
        printf("%d ", lista->valores[i]->clave);
    }
    printf("\n");
}

//-----------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------
// Rutinas del Iterador
//-----------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------
Iterador iterador(Lista lista) {
    Iterador iter = (Iterador) malloc(sizeof(struct IteradorRep));
    iter->lista = lista;
    iter->posicionActual = 0;
    return iter;
}

bool hay_siguiente(Iterador iterador) {
    return iterador->posicionActual < iterador->lista->cantidad;
}

TipoElemento siguiente(Iterador iterador) {
    return iterador->lista->valores[iterador->posicionActual++];
}
