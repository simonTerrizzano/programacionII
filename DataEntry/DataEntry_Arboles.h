#ifndef DataEntry_Arboles
#define DataEntry_Arboles

#include "C:\Users\PC\Documents\ProgramacionII\programacionII\TP5_Arboles\Implementaciones_TAD_Arboles\arbol-binario-busqueda.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool ingresoEntero(int* n);
void Cargar_Arbol(ArbolBinarioBusqueda A, int cant);

void pre_orden(NodoArbol N);
void in_orden(NodoArbol N);
void post_orden(NodoArbol N);

#endif