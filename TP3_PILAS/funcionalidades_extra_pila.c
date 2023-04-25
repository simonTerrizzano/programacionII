#include "funcionalidades_extra_pila.h"
void p_devolver(Pila p_dest, Pila p_src)
{
    TipoElemento te_aux;
    while(p_es_vacia(p_src) == false)
    {
	te_aux = p_desapilar(p_src);
	p_apilar(p_dest, te_aux);
    }

}

void p_insertar(Pila pila, TipoElemento elemento_nuevo , unsigned int pos)
{

    TipoElemento elemento;
    Pila pila_auxiliar;
    pila_auxiliar = p_crear();
    while(p_es_vacia(pila) == false && pila->cantidad>=pos)
    {
	elemento = p_desapilar(pila);
	p_apilar(pila_auxiliar, elemento);
    }
    p_apilar(pila, elemento_nuevo);
    p_devolver(pila, pila_auxiliar);
}

void p_eliminar_elemento(Pila pila, int clave)
{

    bool encontrado = false;
    Pila pila_aux = p_crear(); // pila auxiliar para no perder elementos de la pila original
    TipoElemento elemento_aux;
    while(p_es_vacia(pila) == false && encontrado == false)
    {
	elemento_aux = p_tope(pila); // mira el tope de la pila
	if(elemento_aux->clave == clave) // si la clave del elemento coincide
	{
	    free(p_desapilar(pila)); // lo desapila y libera memoria
	    encontrado = true;
	}
	else
	{
	    elemento_aux = p_desapilar(pila); // desapila para buscar al siguiente
	    p_apilar(pila_aux, elemento_aux); // lo apila en auxiliar para no perderlo
	}
    }

    p_devolver(pila, pila_aux); // le devuelve todo a la pila original 

}

void intercambiar(Pila pila, unsigned int posicion_1, unsigned int posicion_2)
{
    TipoElemento elemento_de_pos_max, elemento_de_pos_min;
    TipoElemento elemento_auxiliar;
    Pila pila_auxiliar = p_crear();
    if(posicion_1 == posicion_2 || ((posicion_1 > pila->cantidad) || (posicion_2 > pila->cantidad)))
	return;
    unsigned int pos_max, pos_min; // nos valemos de que o posicion_1 > posicion_2 , o posicion_2 > posicion_1
    if(posicion_1 > posicion_2)
    {
	pos_max = posicion_1;
	pos_min = posicion_2;
    }
    pos_max = posicion_2;
    pos_min = posicion_1;
    
    while(p_es_vacia(pila) == false)
    {
	if(pila->cantidad == pos_max){elemento_de_pos_max = p_tope(pila);}

	if(pila->cantidad == pos_min){elemento_de_pos_min = p_tope(pila);}

	elemento_auxiliar = p_desapilar(pila);
	p_apilar(pila_auxiliar, elemento_auxiliar);
    }

    while(p_es_vacia(pila_auxiliar) == false)
    {
	elemento_auxiliar = p_desapilar(pila_auxiliar);
	p_apilar(pila, elemento_auxiliar);
	if(pila->cantidad == pos_min)
	{
	    p_desapilar(pila);
	    p_apilar(pila, elemento_de_pos_max);
	}

	if(pila->cantidad == pos_max)
	{
	    p_desapilar(pila);
	    p_apilar(pila, elemento_de_pos_min);
	}
    }
}
