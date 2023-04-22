#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilas.h"
#include "tipo_elemento.h"

void p_devolver(Pila p_dest, Pila p_src)
{
    TipoElemento te_aux;
    while(p_es_vacia(p_src) == false)
    {
	te_aux = p_desapilar(p_src);
	p_apilar(p_dest, te_aux);
    }

}
