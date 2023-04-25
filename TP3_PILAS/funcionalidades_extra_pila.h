#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilas.h"
#include "tipo_elemento.h"
// p_devolver: desapila todo lo que este en p_src y lo apila en p_dest
void p_devolver(Pila p_dest, Pila p_src);
// p_insertar: inserta un nuevo elemento en cierta posicion.
void p_insertar(Pila pila, TipoElemento elemento_nuevo , unsigned int pos);
