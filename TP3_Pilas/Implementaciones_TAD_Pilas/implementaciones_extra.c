#include "pilas.h"

void tranferir(Pila pila, Pila PilaAux){
    TipoElemento elemento;
    while (p_es_vacia(pila))
    {
        elemento=p_desapilar(pila);
        p_apilar(PilaAux,elemento);
    }
    
}