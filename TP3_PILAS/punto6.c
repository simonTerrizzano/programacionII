#include "punto6.h"
Pila p_eliminar_ocurrencias_recursivo(Pila p_src, int clave_buscada)
{
    Pila pila_modf = p_crear();
    Pila pila_aux = p_duplicar(p_src);
    p_proc_el_recur(p_src, pila_modf, clave_buscada);
    p_src = p_duplicar(pila_aux);
    free(pila_aux);
    pila_aux = p_crear();
    p_devolver(pila_aux, pila_modf);
    free(pila_modf);
    return pila_aux;
} // COMPLEJIDAD ALGORITMICA O(N).


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

} // COMPLEJIDAD ALGORITMICA O(N).



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

    p_src = p_duplicar(p_aux);
    free(p_aux);
    p_aux = p_crear();
    p_devolver(p_aux, p_modf);
    return p_aux;


}
// COMPLEJIDAD ALGORITMICA O(N).
