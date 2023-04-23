#include "pilas.h"

void tranferir(Pila pila, Pila pilaAux){
    TipoElemento elemento;
    while (p_es_vacia(pila)!=true)
    {
        elemento=p_desapilar(pila);
        p_apilar(pilaAux, elemento);     
    }
}