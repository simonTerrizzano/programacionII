#ifndef COLAS_H
#define COLAS_H
#include <stdbool.h>
#include "tipo_elemento.h"

struct ColaRep;
typedef struct ColaRep *Cola;

Cola c_crear(); // Retorna una cola creada (vacia)
bool c_es_vacia(Cola cola); // determina si se encuentra vacia 
bool c_es_llena(Cola cola); // determina si se encuentra llena
void c_encolar(Cola cola, TipoElemento elemento); // pone en la cola un elemento
TipoElemento c_desencolar(Cola cola); // retira de la cola un elemento
TipoElemento c_recuperar(Cola cola); // retorna el frente de la cola (sin desencolarlo)
void c_mostrar(Cola cola); // muestra los elementos de la cola
unsigned int c_longitud(Cola cola);
#endif // COLAS_H
