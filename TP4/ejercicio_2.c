#include "ejercicio_2.h"
#include "colas.h"
void c_elemento_existe(Cola cola, int clave)
{
    bool encontrado = false;
    TipoElemento elemento_auxiliar;
    Cola cola_auxiliar = c_crear();
    while(c_es_vacia(cola) == false)
    {
	elemento_auxiliar = c_desencolar(cola);
	c_encolar(cola_auxiliar, elemento_auxiliar);
	if(elemento_auxiliar->clave == clave)
	{
	    encontrado = true;
	}
    }

    while(c_es_vacia(cola_auxiliar) == false)
    {
	elemento_auxiliar = c_desencolar(cola_auxiliar);
	c_encolar(cola, elemento_auxiliar);
    }


    if(encontrado)
	printf("\nEl elemento de clave %d se encuentra en la lista ;)\n", clave);
    else
    {
	printf("\nNo se encuentra el elemento de clave %d :(\n", clave);
    }
}
