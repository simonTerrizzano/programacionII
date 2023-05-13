#ifndef EJERCICIO_2
#define EJERCICIO_2
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "colas.h"
// punto a)
void c_elemento_existe(Cola cola, int clave);
// punto b)
void c_insertar_elemento(Cola cola, TipoElemento elemento, int pos);
// punto c)
void c_eliminar_elemento(Cola cola, int clave);
// punto d)
void c_contar_elementos(Cola cola);
// punto e)
void c_copiar_cola(Cola cola_destino, Cola cola_src);
// punto f)
Cola c_cola_invertida(Cola cola_src);
// FUNCIONES EXTRA
void c_devolver(Cola c_dest, Cola c_src);

#endif 