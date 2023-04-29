#include "punto3.h"

bool p_contenidos_iguales(Pila pila_1, Pila pila_2)
{
    int suma_claves_pila_1 = 0, suma_claves_pila_2 = 0;
    TipoElemento elemento_auxiliar;
    Pila pila_auxiliar = p_crear();
    while(p_es_vacia(pila_1) == false)
    {
	elemento_auxiliar = p_desapilar(pila_1);
	suma_claves_pila_1 += elemento_auxiliar->clave;
	p_apilar(pila_auxiliar, elemento_auxiliar);
    }

    p_devolver(pila_1, pila_auxiliar);

    while(p_es_vacia(pila_2) == false)
    {
	elemento_auxiliar = p_desapilar(pila_2);
	suma_claves_pila_2 += elemento_auxiliar->clave;
	p_apilar(pila_auxiliar, elemento_auxiliar);
    }
    p_devolver(pila_2, pila_auxiliar);

    return (suma_claves_pila_1 == suma_claves_pila_2);
   
}
