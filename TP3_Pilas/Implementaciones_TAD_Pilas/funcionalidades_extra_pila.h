#ifndef funcionalidades_extra_pila
#define funcionalidades_extra_pila

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "C:\Users\PC\Documents\ProgramacionII\programacionII\programacionII\TP3_Pilas\Implementaciones_TAD_Pilas\pilas.h"
#include "C:\Users\PC\Documents\ProgramacionII\programacionII\programacionII\TP3_Pilas\Implementaciones_TAD_Pilas\tipo_elemento.h"

// p_devolver: desapila todo lo que este en p_src y lo apila en p_dest
void p_devolver(Pila p_dest, Pila p_src);
// p_insertar: inserta un nuevo elemento en cierta posicion.
void p_insertar(Pila pila, TipoElemento elemento_nuevo , unsigned int pos);
// p_eliminar_elemento: Elimina de una pila un elemento dado (primera ocurrencia encontrada por la clave).
void p_eliminar_elemento(Pila pila, int clave);
// p_intercambiar: A partir de una pila y dos posciones ordinales se intercambiaran posicionalmente los elementos pertenecientes a las posiciones(mientras esto sea posible). 
void p_intercambiar(Pila pila, unsigned int posicion_1, unsigned int posicion_2);
// p_duplicar: a partir de una pila(fuente) se devolvera una pila que es su duplicado.
Pila p_duplicar(Pila p_src);
// p_buscar_clave: busca si existe cierta clave en la pila. Muestra en pantalla el resultado
bool p_buscar_clave(Pila pila, int clave);
// p_contar_elementos: Recibe una pila, y retorna la cantidad de elementos contados
unsigned int p_contar_elementos(Pila p_src);


#endif