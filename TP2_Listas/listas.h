#ifndef LISTAS_H
#define LISTAS_H

#include <stdbool.h>
#include "tipo_elemento.h"

struct ListaRep;
typedef struct ListaRep *Lista;

struct IteradorRep;
typedef struct IteradorRep *Iterador;

Lista l_crear();

bool l_es_vacia(Lista lista);

bool l_es_llena(Lista lista);

int l_longitud(Lista lista);

void l_agregar(Lista lista, TipoElemento elemento);

void l_borrar(Lista lista, int clave);

TipoElemento l_buscar(Lista lista, int clave);

void l_insertar(Lista lista, TipoElemento elemento, int pos);

void l_eliminar(Lista lista, int pos);

TipoElemento l_recuperar(Lista lista, int pos);

void l_mostrarLista(Lista lista);

// Funciones de iterador de la lista
Iterador iterador(Lista lista);

bool hay_siguiente(Iterador iterador);

TipoElemento siguiente(Iterador iterador);

#endif // LISTAS_H
