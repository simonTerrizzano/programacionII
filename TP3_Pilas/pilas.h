#ifndef PILAS_H
#define PILAS_H

#include <stdbool.h>
#include "tipo_elemento.h"

struct PilaRep;
typedef struct PilaRep *Pila;

/**
 * Crea una nueva pila vacía.
 *
 * @return Pila - una nueva instancia de pila vacía.
 */
Pila p_crear();

/**
 * Agrega un elemento a la cima de la pila recibida como parámetro.
 *
 * @param pila - una instancia de tipo Pila.
 * @param elemento - el elemento a agregar a la pila.
 */
void p_apilar(Pila pila, TipoElemento elemento);

/**
 * Remueve y devuelve el elemento en la cima de la pila recibida como parámetro.
 *
 * @param pila - una instancia de tipo Pila.
 * @return TipoElemento - el elemento que se encontraba en la cima de la pila.
 */
TipoElemento p_desapilar(Pila pila);

/**
 * Devuelve el elemento en la cima de la pila recibida como parámetro sin removerlo.
 *
 * @param pila - una instancia de tipo Pila.
 * @return TipoElemento - el elemento en la cima de la pila.
 */
TipoElemento p_tope(Pila pila);

/**
 * Comprueba si la pila recibida como parámetro está vacía.
 *
 * @param pila - una instancia de tipo Pila.
 * @return bool - true si la pila está vacía, false en caso contrario.
 */
bool p_es_vacia(Pila pila);

/**
 * Comprueba si la pila recibida como parámetro está llena.
 *
 * @param pila - una instancia de tipo Pila.
 * @return bool - true si la pila está llena, false en caso contrario.
 */
bool p_es_llena(Pila pila);

/**
 * Muestra por pantalla los elementos de la pila recibida como parámetro.
 *
 * @param pila - una instancia de tipo Pila.
 */
void p_mostrar(Pila pila);

#endif // PILAS_H
