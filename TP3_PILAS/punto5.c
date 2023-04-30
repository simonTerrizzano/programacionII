#include "punto5.h"
Pila p_invertida(Pila p_src)
{
    TipoElemento elemento_aux;
    Pila pila_invertida = p_crear();
    Pila pila_auxiliar = p_crear();
    while(p_es_vacia(p_src) == false)
    {
	elemento_aux = p_desapilar(p_src);
	p_apilar(pila_invertida, elemento_aux);
	p_apilar(pila_auxiliar, elemento_aux);
    }

    p_devolver(p_src, pila_auxiliar);
    free(pila_auxiliar);
    return pila_invertida;




}
