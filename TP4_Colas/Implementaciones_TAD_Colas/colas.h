#ifndef COLAS_H
#define COLAS_H

#include <stdbool.h>
#include "tipo_elemento.h"

static const int TAMANIO_MAXIMO = 10;

struct ColaRep;
typedef struct ColaRep *Cola;

Cola c_crear();
bool c_es_vacia(Cola cola);
bool c_es_llena (Cola cola);

void c_encolar(Cola cola, TipoElemento elemento);
void c_mostrar(Cola cola);

TipoElemento c_desencolar(Cola cola);
TipoElemento c_recuperar (Cola cola);
int c_longitud (Cola C);
#endif // COLAS_H