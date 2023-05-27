#ifndef Ejercicio_3
#define Ejercicio_3

#include "C:\Users\PC\Documents\ProgramacionII\programacionII\TP5_Arboles\Implementaciones_TAD_Arboles\nodo.h"
#include "C:\Users\PC\Documents\ProgramacionII\programacionII\TP5_Arboles\Implementaciones_TAD_Arboles\arbol-binario-busqueda.h"
#include <stdbool.h>

void a_padre_nodo(NodoArbol NA, NodoArbol* NP, TipoElemento te);
NodoArbol padre_interfaz(ArbolBinarioBusqueda a);
void a_hijos_nodo(NodoArbol N);
int nivel_nodo_interfaz(ArbolBinarioBusqueda A, NodoArbol N);
void a_hermanos_nodo(ArbolBinarioBusqueda a, NodoArbol N);
int altura_sub_arbol_interfaz(ArbolBinarioBusqueda a, NodoArbol N);
void alttura_sub_arbol(NodoArbol Q, int *h, int c);
void a_nodos_mismo_nivel(ArbolBinarioBusqueda a, NodoArbol NA, int alturaBuscada, int claveHermano);
void nodos_mismo_nivel_interfaz(ArbolBinarioBusqueda a, NodoArbol N);




#endif