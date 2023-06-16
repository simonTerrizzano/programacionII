#ifndef CONJUNTOS_H
#define CONJUNTOS_H

#include <stdbool.h>
#include "tipo_elemento.h"

struct ConjuntoRep;
typedef struct ConjuntoRep *Conjunto;

/**
 * Crea un conjunto vacío.
 *
 * @return Conjunto - una nueva instancia de conjunto.
 */
Conjunto cto_crear();

/**
 * Indica si el conjunto está vacío.
 *
 * @param conjunto una instancia de tipo conjunto.
 * @return bool - true si el conjunto está vacío, false en caso contrario.
 */
bool cto_es_vacio(Conjunto conjunto);

/**
 * Indica si el conjunto está lleno.
 *
 * @param conjunto una instancia de tipo conjunto.
 * @return bool - true si el conjunto está lleno, false en caso contrario.
 */
bool cto_es_lleno(Conjunto conjunto);

/**
 * Devuelve la cantidad de elementos en el conjunto.
 *
 * @param conjunto una instancia de tipo conjunto.
 * @return la cantidad de elementos en el conjunto.
 */
int cto_cantidad_elementos(Conjunto conjunto);

/**
 * Agrega un elemento al conjunto.
 *
 * @param conjunto una instancia de tipo conjunto.
 * @param elemento el elemento a agregar al conjunto.
 */
void cto_agregar(Conjunto conjunto, TipoElemento elemento);

/**
 * Borra un elemento del conjunto.
 *
 * @param conjunto una instancia de tipo conjunto.
 * @param clave la clave del elemento a borrar.
 */
void cto_borrar(Conjunto conjunto, int clave);

/**
 * Indica si un elemento está en el conjunto.
 *
 * @param conjunto una instancia de tipo conjunto.
 * @param clave la clave del elemento a buscar.
 * @return bool - true si el elemento está en el conjunto, false en caso contrario.
 */
bool cto_pertenece(Conjunto conjunto, int clave);

/**
 * Devuelve la unión de dos conjuntos.
 *
 * @param conjunto_a el primer conjunto.
 * @param conjunto_b el segundo conjunto.
 * @return una nueva instancia de tipo conjunto que es la unión de los dos conjuntos pasados por parámetro.
 */
Conjunto cto_union(Conjunto conjunto_a, Conjunto conjunto_b);

/**
 * Devuelve la intersección de dos conjuntos.
 *
 * @param conjunto_a el primer conjunto.
 * @param conjunto_b el segundo conjunto.
 * @return una nueva instancia de tipo conjunto que es la intersección de los dos conjuntos pasados por parámetro.
 */
Conjunto cto_interseccion(Conjunto conjunto_a, Conjunto conjunto_b);

/**
 * Devuelve la diferencia entre dos conjuntos.
 *
 * @param conjunto_a el primer conjunto.
 * @param conjunto_b el segundo conjunto.
 * @return una nueva instancia de tipo conjunto que es la diferencia entre los dos conjuntos pasados por parámetro.
 */
Conjunto cto_diferencia(Conjunto conjunto_a, Conjunto conjunto_b);

/**
 * Devuelve el tipo elemento de una posicion logica.
 *
 * @param conjunto el primer conjunto.
 * @param posicion_ordinal la posicion ordinal para recuperar un item del conjunto.
 * @return un tipo elemento de esa posicion o NULL si la posicion no es valida.
 */
TipoElemento cto_recuperar(Conjunto conjunto, int posicion_ordinal);

/**
 * Muestra el conjunto. Solo las claves.
 *
 * @param conjunto el primer conjunto.
 */
void cto_mostrar(Conjunto conjunto);

#endif // CONJUNTOS_H
