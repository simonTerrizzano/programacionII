#ifndef LISTAS_H
#define LISTAS_H
#include <stdbool.h>
#include "tipo_elemento.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

struct ListaRep;
typedef struct ListaRep *Lista;

struct IteradorRep;
typedef struct IteradorRep *Iterador;

/* l_crear: crea una lista de cantidad n y los inicia en 0. retorna la dirección de memoria de la cabera de la lista creada.
   return: direccion de lista creada.*/
Lista l_crear();

/*
  l_es_vacia: Recibe una lista y comprueba si esta vacia
  return: true-vacia; false-no vacia
 */
bool l_es_vacia(Lista lista);

/*
  l_es_llena: Recibe una lista y comprueba si esta se encuentra llena
  return: true-llena; false-no llena
 */
bool l_es_llena(Lista lista);

// l_longitud: Recibe una lista y devuelve la cantidad de elementos que tiene.
// return: cantidad(int)
int l_longitud(Lista lista);

// l_agregar: agrega al final de lista <lista> un <elemento>. aumenta la cantidad de elementos en lista
void l_agregar(Lista lista, TipoElemento elemento);

// l_borrar: borra un elemento de clave <clave> en la lista 
void l_borrar(Lista lista, int clave);

// l_buscar: busca un elemento de clave <clave> en la lista, si lo encuentra retorna su direccion, si no lo encuentra retorna un NULL
TipoElemento l_buscar(Lista lista, int clave);

// l_insertar: se inserta un elemento <elemento> en la posicion <pos> en la lista <lista>.
void l_insertar(Lista lista, TipoElemento elemento, int pos);

// l_eliminar: elimina elemento segun posicion
void l_eliminar(Lista lista, int pos);

// l_recuperar: devuelve elemento de lista segun posicion
TipoElemento l_recuperar(Lista lista, int pos);

// l_mostrarLista: muestra el contenido de lista
void l_mostrar(Lista lista);

// Funciones de iterador de la lista
Iterador iterador(Lista lista);

bool hay_siguiente(Iterador iterador);

// retorna el elemento siguiente de la lista
TipoElemento siguiente(Iterador iterador);


#endif // LISTAS_H
