#ifndef Ejercicio_2
#define Ejercicio_2

#include "C:\Users\PC\Documents\ProgramacionII\programacionII\TP5_Arboles\Implementaciones_TAD_Arboles\arbol-binario-busqueda.h"
#include "C:\Users\PC\Documents\ProgramacionII\programacionII\TP2_Listas\listas.h"
#include <stdbool.h>

Lista hoja_interfaz(ArbolBinarioBusqueda a);
void a_retornar_hojas(NodoArbol N, Lista LR);
Lista interior_interfaz(ArbolBinarioBusqueda a);
void a_retornar_interiores(NodoArbol N, Lista LR);
Lista ocurrencia_interfaz(ArbolBinarioBusqueda a,TipoElemento elemento_buscado);
void a_retornar_ocurrencias(NodoArbol N, Lista LR,TipoElemento elemento_buscado);



#endif
