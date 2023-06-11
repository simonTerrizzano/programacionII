#ifndef TABLA_HASH_H
#define TABLA_HASH_H

#include "tipo_elemento.h"

struct TablaHashRep;
typedef struct TablaHashRep *TablaHash;

/**
 * Crea una nueva tabla hash con un tamaño inicial y una función hash especificada.
 *
 * @param tamano - un valor entero que indica el tamaño inicial de la tabla hash.
 * @param hash_function - un puntero a una función que se utilizará para calcular el hash de las claves.
 * @return TablaHash - una nueva instancia de TablaHash con el tamaño y función hash especificados.
 */
TablaHash th_crear(int tamano, int (*hash_function)(int));

/**
 * Inserta un TipoElemento en la tabla hash especificada.
 *
 * @param th - la tabla hash donde se insertará el elemento.
 * @param te - un TipoElemento que se insertará en la tabla hash.
 */
void th_insertar(TablaHash th, TipoElemento te);

/**
 * Elimina un TipoElemento de la tabla hash especificada.
 *
 * @param th - la tabla hash de donde se eliminará el elemento.
 * @param clave - un valor entero que se utilizará como clave del elemento que se eliminará.
 */
void th_eliminar(TablaHash th, int clave);

/**
 * Recupera el TipoElemento con la clave especificada de la tabla hash.
 *
 * @param th - la tabla hash donde se buscará el elemento.
 * @param clave - un valor entero que se utilizará como clave del elemento que se buscará.
 * @return TipoElemento - un puntero al TipoElemento con la clave especificada o NULL si no se encuentra.
 */
TipoElemento th_recuperar(TablaHash th, int clave);

/**
 * Muestra todos los elementos de la tabla hash, incluyendo los espacios vacíos.
 *
 * @param th - la tabla hash que se mostrará.
 */
void th_mostrar(TablaHash th);

/**
 * Muestra solo los elementos ocupados de la tabla hash, es decir, aquellos con un TipoElemento asociado.
 *
 * @param th - la tabla hash que se mostrará.
 */
void th_mostrar_solo_ocupados(TablaHash th);

#endif //TABLA_HASH_H
