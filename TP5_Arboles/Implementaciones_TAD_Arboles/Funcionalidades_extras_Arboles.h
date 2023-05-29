#ifndef Funcionalidades_extra_Arboles
#define Funcionalidades_extra_Arboles


#include "C:\Users\PC\Documents\ProgramacionII\programacionII\TP5_Arboles\Implementaciones_TAD_Arboles\arbol-binario-busqueda.h"
#include "C:\Users\PC\Documents\ProgramacionII\programacionII\TP5_Arboles\Implementaciones_TAD_Arboles\arbol-avl.h"
#include "C:\Users\PC\Documents\ProgramacionII\programacionII\TP2_Listas\listas.h"
#include <stdbool.h>



Lista hoja_interfaz(ArbolBinarioBusqueda a);
void a_retornar_hojas(NodoArbol N, Lista LR);
Lista interior_interfaz(ArbolBinarioBusqueda a);
void a_retornar_interiores(NodoArbol N, Lista LR);
Lista ocurrencia_interfaz(ArbolBinarioBusqueda a,TipoElemento elemento_buscado);
void a_retornar_ocurrencias(NodoArbol N, Lista LR,TipoElemento elemento_buscado);
ArbolAVL abb_a_avl_interfaz(ArbolBinarioBusqueda a);
void abb_a_avl(NodoArbol nodo_abb,ArbolAVL* avl);
void a_padre_nodo(NodoArbol NA, NodoArbol* NP, TipoElemento te);
NodoArbol padre_interfaz(ArbolBinarioBusqueda a, NodoArbol N);
void a_hijos_nodo(NodoArbol N);
void nodos_mismo_nivel_interfaz(ArbolBinarioBusqueda a, NodoArbol N);
void a_hermanos_nodo(ArbolBinarioBusqueda a, NodoArbol N);
int altura_sub_arbol_interfaz(ArbolBinarioBusqueda a, NodoArbol N);
int nivel_nodo(ArbolBinarioBusqueda A, NodoArbol N);
void nivelint(NodoArbol Q, int Cbuscada, int *h, int c);
void altint(NodoArbol Q, int *h, int c);
void a_nodos_mismo_nivel(ArbolBinarioBusqueda a, NodoArbol NA, int alturaBuscada, int claveHermano);
void nodos_mismo_nivel_interfaz(ArbolBinarioBusqueda a, NodoArbol N);
int maximo(int a, int b);
int minimo(int a, int b);

#endif