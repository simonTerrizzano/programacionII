#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipo_elemento.h"

// te_crear: recibe un entero el cual sera la clave del elemento creado.
// return: devuelve un puntero al elemento
TipoElemento te_crear(int clave)
{
    // se crea dinamicamente un tipo elemento
    TipoElemento te = (TipoElemento) malloc(sizeof(TipoElemento));
    // se le asigna una clave
    te->clave = clave;
    te->valor = NULL;
    return te;

}

// te_crear: recibe un entero el cual sera la clave del elemento creado y recibe la dirección del dato el cual debera apuntar el te creado.
// return: devuelve un puntero al elemento
TipoElemento te_crearConValor(int clave, void *valor)
{
    TipoElemento te = (TipoElemento) malloc(sizeof(TipoElemento));
    te->clave = clave;
    te->valor = valor;
    return te;
}
