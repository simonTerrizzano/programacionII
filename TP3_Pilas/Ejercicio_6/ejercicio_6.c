#include "ejercicio_6.h"
Pila p_eliminar_ocurrencias_recursivo(Pila p_src, int clave_buscada)
{
    Pila pila_modf = p_crear();
    Pila pila_aux = p_duplicar(p_src);
    p_proc_el_recur(p_src, pila_modf, clave_buscada);
    p_devolver(p_src,pila_aux);
    return pila_modf;
}


void p_proc_el_recur(Pila p_src, Pila p_modf, int clave_buscada)
{
    if(p_es_vacia(p_src))
    {
	return;
    }

    TipoElemento elem_aux;
    elem_aux = p_desapilar(p_src);
    if(elem_aux->clave != clave_buscada)
    {
	p_apilar(p_modf, elem_aux);
    }
    
    p_proc_el_recur(p_src, p_modf, clave_buscada);

}



Pila p_eliminar_ocurrencias_iter(Pila p_src, int clave)
{
    Pila p_aux = p_duplicar(p_src);
    Pila p_modf = p_crear();
    TipoElemento elemento;
    while(p_es_vacia(p_src) == false)
    {
	elemento = p_desapilar(p_src);
	if(elemento->clave != clave)
	{
	    p_apilar(p_modf, elemento);
	}	
    }

    p_devolver(p_src,p_aux);
    p_aux = p_crear();
    // p_devolver(p_aux, p_modf);
    return p_modf;
}