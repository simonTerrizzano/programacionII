#include "listas.h"
#include <stdlib.h>
#include <stdio.h>
static const int TAMANIO_MAXIMO_LISTAS = 100;
struct Nodo { // Se agrega el concepto de Nodo
    TipoElemento datos;
    struct Nodo *siguiente;
};
struct ListaRep { // Esta es la lista en esta implementación
    struct Nodo *inicio;
    int cantidad;
};
struct IteradorRep {
    struct Nodo *posicionActual;
};
Lista l_crear () {
    Lista nueva_lista = (Lista) malloc(sizeof(struct ListaRep));
    nueva_lista->inicio = NULL;
    nueva_lista->cantidad = 0;
    return nueva_lista;
}
bool l_es_vacia (Lista lista) { return lista->cantidad == 0; }
bool l_es_llena (Lista lista) {return lista->cantidad == TAMANIO_MAXIMO_LISTAS;}
int l_longitud (Lista lista) {
    return lista->cantidad;
}
TipoElemento l_recuperar (Lista lista, int pos) {
    struct Nodo *temp2 = lista->inicio;
    for (int i = 0; i < pos - 1; i++) {
        temp2 = temp2->siguiente;
    }
    return temp2->datos;
}
void l_agregar (Lista lista, TipoElemento elemento) {
    if (l_es_llena(lista)) {return;} // si esta llena no agrega
    struct Nodo *nuevo_nodo = malloc(sizeof(struct Nodo));
    nuevo_nodo->datos = elemento;
    nuevo_nodo->siguiente = NULL;
    if (lista->inicio == NULL) {
        lista->inicio = nuevo_nodo;
    }
    else {
        struct Nodo *temp2 = lista->inicio;
        while (temp2->siguiente != NULL) { // Busco el Nodo Final
        temp2 = temp2->siguiente;
    }
        temp2->siguiente = nuevo_nodo; // Lo conecto al final
    }
    lista->cantidad++;
}
void l_borrar (Lista lista, int clave) {
    if (l_es_vacia(lista)) {
    return;
    }
    struct Nodo *actual = lista->inicio;
    while (actual != NULL && actual->datos->clave == clave) { //Borra las claves del inicio
        lista->inicio = actual->siguiente;
        free(actual);
        lista->cantidad--;
        actual = lista->inicio;
    }
    while (actual != NULL && actual->siguiente != NULL) { //Borra en el resto de la lista
    if (actual->siguiente->datos->clave == clave) {
        struct Nodo *temp = actual->siguiente;
        actual->siguiente = temp->siguiente;
        free(temp);
        lista->cantidad--;
    } else {
        actual = actual->siguiente;
    }
    }
}
void l_insertar (Lista lista, TipoElemento elemento, int pos) {
if (l_es_llena(lista)) {return;} // Si esta llena no inserta
struct Nodo *nuevo_nodo = malloc(sizeof(struct Nodo));
nuevo_nodo->datos = elemento;
nuevo_nodo->siguiente = NULL;
if (pos == 1) {
nuevo_nodo->siguiente = lista->inicio;
lista->inicio = nuevo_nodo;
} else {
struct Nodo *temp2 = lista->inicio;
for (int i = 0; i < pos - 2; i++) { // Busca la posición de inserción
temp2 = temp2->siguiente;
}
nuevo_nodo->siguiente = temp2->siguiente;
temp2->siguiente = nuevo_nodo;
}
lista->cantidad++;
}
void l_eliminar (Lista lista, int pos) {
if (l_es_vacia(lista)) {return;} // Si esta vacia sale de la rutina
struct Nodo *actual = lista->inicio;
if (1 <= pos && pos <= l_longitud(lista)) {
if (pos == 1) {
lista->inicio = actual->siguiente;
free(actual);
} else {
for (int i = 0; i < pos - 2; i++) { // Busca la posición para eliminar
actual = actual->siguiente;
}
// actual apunta al nodo en posición (pos - 1)
struct Nodo *temp = actual->siguiente; // nodo en pos
actual->siguiente = temp->siguiente; // nodo en pos + 1
free(temp);
}
lista->cantidad--;
}
}
TipoElemento l_buscar (Lista lista, int clave) {
struct Nodo *actual = lista->inicio;
while (actual != NULL) {
if (actual->datos->clave == clave) {
return actual->datos;
}
actual = actual->siguiente;
}
return NULL;
}
void l_mostrarLista (Lista lista) {
struct Nodo *temp2 = lista->inicio;
printf("Contenido de la lista: ");
while (temp2 != NULL) {
printf("%d ", temp2->datos->clave);
temp2 = temp2->siguiente;
}
printf("\n");
}
Iterador iterador (Lista lista) {
Iterador iter = (Iterador) malloc(sizeof(struct IteradorRep));
iter->posicionActual = lista->inicio;
return iter;
}
bool hay_siguiente (Iterador iterador) {
return (iterador->posicionActual != NULL);
}
TipoElemento siguiente (Iterador iterador) {
TipoElemento actual = iterador->posicionActual->datos;
iterador->posicionActual = iterador->posicionActual->siguiente;
return actual;
}