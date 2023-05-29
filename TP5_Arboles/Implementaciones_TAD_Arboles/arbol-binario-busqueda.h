#ifndef ARBOL_BINARIO_BUSQUEDA_H_INCLUDED
#define ARBOL_BINARIO_BUSQUEDA_H_INCLUDED

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nodo.h"
#include "C:\Users\PC\Documents\ProgramacionII\programacionII\TipoElemento\tipo_elemento.h"

struct ArbolBinarioBusquedaRep;
typedef struct ArbolBinarioBusquedaRep *ArbolBinarioBusqueda;

ArbolBinarioBusqueda abb_crear();

bool abb_es_vacio(ArbolBinarioBusqueda a);

bool abb_es_lleno(ArbolBinarioBusqueda a);

NodoArbol abb_raiz(ArbolBinarioBusqueda a);

int abb_cantidad_elementos(ArbolBinarioBusqueda a);

void abb_insertar(ArbolBinarioBusqueda a, TipoElemento te);

void abb_eliminar(ArbolBinarioBusqueda a, int claveABorrar);

TipoElemento abb_buscar(ArbolBinarioBusqueda a, int clave);

#endif // ARBOL_BINARIO_BUSQUEDA_H_INCLUDED
