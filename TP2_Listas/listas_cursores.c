#include "listas.h"
#include <stdlib.h>
#include <stdio.h>

static const int TAMANIO_MAXIMO_LISTAS = 100;
static const int NULO = -1;
struct Nodo {
    TipoElemento datos;
    int siguiente; // Cambia el apuntador por un “int”
};
struct ListaRep {
    struct Nodo *cursor; // Apuntador al Arreglo de Nodos
    int inicio;
    int libre; // Contendrá los nodos libres o disponibles
    int cantidad;
};
struct IteradorRep {
    Lista lista;
    int posicionActual;
};

bool l_es_vacia(Lista lista){
    return lista->libre==0;
}

bool l_es_llena(Lista lista){
    return lista->libre==TAMANIO_MAXIMO_LISTAS;
}

int l_longitud(Lista lista){
    return lista->cantidad;
}

TipoElemento l_buscar(Lista lista, int clave){
    int q = lista->inicio;
    while (lista->cursor[q].siguiente != NULO) {
        q = lista->cursor[q].siguiente;
        if(lista->cursor[q].datos->clave==clave){
            return lista->cursor[q].datos;
        }
    }
    return NULL;
    }
TipoElemento l_recuperar(Lista lista, int pos){
    if (1 <= pos && pos <= l_longitud(lista)) { 
        int q = lista->inicio;
        int i=0;
        if (i=pos-1)
        {
            return lista->cursor[q].datos;
        }

        while (lista->cursor[q].siguiente != NULO) {
            i++;
            if (i=pos-1)
            {
            return lista->cursor[q].datos;
            }
            q = lista->cursor[q].siguiente;
        }
    }
    else{
        return NULL;
    }
}


Lista l_crear () {
    Lista nueva_lista = (Lista) malloc(sizeof(struct ListaRep));
    nueva_lista->cursor = (struct Nodo*)calloc(TAMANIO_MAXIMO_LISTAS, sizeof(struct Nodo));
    nueva_lista->cantidad = 0;
    nueva_lista->inicio = NULO;
    // Encadeno todos los libres
    for (int i = 0; i < TAMANIO_MAXIMO_LISTAS-2; i++) {
    nueva_lista->cursor[i].siguiente = i + 1;
    }
    nueva_lista->libre = 0; //Toma todos los nodos como libres
    nueva_lista->inicio = NULO;
    nueva_lista->cursor[TAMANIO_MAXIMO_LISTAS-1].siguiente = NULO;
    // retorno la lista creada
    return nueva_lista;
}

void l_agregar (Lista lista, TipoElemento elemento) {
    if (l_es_llena(lista)) {
        return;
        } //Controlo la lista llena
    int p;
    p = lista->libre; // Tomo el primer libre
    lista->libre = lista->cursor[p].siguiente;
    lista->cursor[p].datos = elemento; // Asigno el dato
    lista->cursor[p].siguiente = NULO;
    // Controlo que no sea el primero de la lista
    if (lista->inicio == NULO) {
    lista->inicio = p;
    } else {
    // lo ubico al final
    int q = lista->inicio;
    while (lista->cursor[q].siguiente != NULO) {
    q = lista->cursor[q].siguiente;
    }
    lista->cursor[q].siguiente = p; // Lo conecto con el ultimo
    }
    lista->cantidad++;
}

void l_borrar (Lista lista, int clave) {
    if (l_es_vacia(lista)){
        return;
        } // Controlo la lista vacia
    int q; int p = lista->inicio;
    // borro las claves que coinciden con el inicio
    while ((p != NULO) && (lista->cursor[p].datos->clave == clave)) {
        q = p;
        lista->inicio = lista->cursor[p].siguiente;
        // recupero el nodo en el libre para no perderlo
        lista->cursor[q].siguiente = lista->libre;
        lista->libre = q;
        // Descuento 1 y arranco de nuevo desde el inicio
        lista->cantidad--;
        p = lista->inicio; // Vuelvo a intentar desde el inicio
    }
    // Borro las claves en el resto de la lista
    p = lista->inicio;
    while ((p != NULO) && (lista->cursor[p].siguiente != NULO)) {//Similar a punteros, solo no olvidar encadenar el libre
        if (lista->cursor[p].datos->clave==clave)
        {
            struct Nodo *temp = li
        }
        
    }
}

void l_insertar (Lista lista, TipoElemento elemento, int pos) {
    if (l_es_llena(lista)) {return;} //Control de lista llena
    int p = lista->libre; // Toma la primer posición libre
    lista->libre = lista->cursor[p].siguiente;
    lista->cursor[p].datos = elemento;
    lista->cursor[p].siguiente = NULO;
    // Controla si cambia el INICIO
    if (pos == 1) {
    lista->cursor[p].siguiente = lista->inicio;
    lista->inicio = p;
    } else {
    int temp = lista->inicio; // Busca la posición del resto de la lista
    for (int i = 0; i < pos - 2; i++) {
    temp = lista->cursor[temp].siguiente;
    }
    lista->cursor[p].siguiente = lista->cursor[temp].siguiente;
    lista->cursor[temp].siguiente = p;
    }
    lista->cantidad++;
}

void l_eliminar (Lista lista, int pos) {
    int p; // Falta controlar lista vacia
    int actual = lista->inicio;
    if (1 <= pos && pos <= l_longitud(lista)) {
    if (pos == 1) { // borra la primer posicion hay que cambiar el Inicio
        p = actual;
        lista->inicio = lista->cursor[actual].siguiente;
        lista->cursor[p].siguiente = lista->libre;
        lista->libre = p; // Devuelvo al libre el nodo que elimine (saque de la lista)
    } 
    else {
        for (int i = 0; i < pos - 2; i++) {
            actual = lista->cursor[actual].siguiente;
        } // actual apunta al nodo en posición (pos - 1)
        p = lista->cursor[actual].siguiente; // nodo en pos
        lista->cursor[actual].siguiente = lista->cursor[p].siguiente; // nodo en pos + 1
        lista->cursor[lista->libre].siguiente = p;
        lista->libre = p; // Devuelvo al libre el nodo que elimine (saque de la lista)
    }
    lista->cantidad--;
    }
}

Iterador iterador(Lista lista){
    Iterador iter = (Iterador) malloc(sizeof(struct IteradorRep));
    iter->lista=lista;
    iter->posicionActual=0;
    return iter;
}

bool hay_siguiente(Iterador iterador){
    return iterrador->cantidad < iterador->lista->cantidad;
}


TipoElemento siguiente(Iterador iterador) {
    int i=0;
    int q;
    while (i<=iterador->posicionActual) {
            q = lista->cursor[q].siguiente;
            i++;
        }
    return iterador->lista->cursor[q+1];
}