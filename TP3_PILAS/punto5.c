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

//COMPLEJIDAD ALGORITMICA: COMPLEJIDAD ALGORITMICA ES DE O(N). Ya que la cantidad de lineas a ejecutar es proporcional a N cantidad de elementos de la pila. El crecimiento es lineal, y el peor caso sera que se ejecute N veces. Luego tenemos p_devolver(), que tambien la cantidad de lineas a ejecutar es proporcional a la cantidad de elementos. Por lo tanto el crecimiento es al rededor de 2n en el peor caso.
