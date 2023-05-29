#include<ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include<math.h>

#include "C:\Users\PC\Documents\ProgramacionII\programacionII\TP5_Arboles\Implementaciones_TAD_Arboles\arbol-binario-busqueda.h"

#ifndef DataEntry
#define DataEntry

int ingreso_normalizado_enteros(int limite_inferior, int limite_superior);
void ingreso_normalizado_string(char cadena[100], int limite_superior);
bool ingreso_normalizado_onda_digital(char* cadena);
void quitaespacios(char* cadena);
void quitasalto(char* cadena);
int cadenatododigito(char* cadena);
bool esNeg(char* cadena);
void minus(char* cadena);
void mayus(char* cadena);
void Cargar_Arbol(ArbolBinarioBusqueda A, int cant, int rango);
void pre_orden(NodoArbol N);
void in_orden(NodoArbol N);
void post_orden(NodoArbol N);
bool numeroyaencontrado(int numero,int *arreglo,int n);
void altint(NodoArbol Q, int *h, int c);
int altura(ArbolBinarioBusqueda A);


#endif