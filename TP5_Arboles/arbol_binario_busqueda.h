#ifndef ARBOL_BINARIO_H_INCLUDED
#define ARBOL_BINARIO_H_INCLUDED
#include <stdbool.h>
#include "nodo.h"
#include "tipo_elemento.h"
struct ArbolBinarioBusquedaRep;
typedef struct ArbolBinarioBusquedaRep *ArbolBinarioBusqueda;
ArbolBinarioBusqueda abb_crear();
bool abb_es_vacio (ArbolBinarioBusqueda a);
int abb_cantidad_elementos (ArbolBinarioBusqueda a);
bool abb_es_rama_nula (NodoArbol pa);
NodoArbol abb_raiz (ArbolBinarioBusqueda a);
NodoArbol abb_establecer_raiz (ArbolBinarioBusqueda a, TipoElemento te);
NodoArbol abb_conectar_hi (ArbolBinarioBusqueda a, NodoArbol pa, TipoElemento te);
NodoArbol abb_conectar_hd (ArbolBinarioBusqueda a, NodoArbol pa, TipoElemento te);
void abb_eliminar_nodo (ArbolBinarioBusqueda, NodoArbol);
#endif // ARBOL_BINARIO_H_INCLUDED