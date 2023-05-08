#include "funcionalidades_extra_pila.h"

void p_devolver(Pila p_dest, Pila p_src)
{
    TipoElemento te_aux;
    while(p_es_vacia(p_src) != true)
    {
	te_aux = p_desapilar(p_src);
	p_apilar(p_dest, te_aux);
    }

}

void p_insertar(Pila pila, TipoElemento nuevo_elemento, unsigned int pos){
    TipoElemento x;
    Pila P_aux=p_crear();
    int cont=1;
    while (cont<pos)
    {
        x=p_desapilar(pila);
        p_apilar(P_aux,x);
        cont++;
    }
    p_apilar(pila,nuevo_elemento);

    p_devolver(pila,P_aux);
    
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
	    p_desapilar(pila); // lo desapila y libera memoria
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

void p_intercambiar(Pila pila, unsigned int posicion_1, unsigned int posicion_2)
{
    TipoElemento elemento_de_pos_max, elemento_de_pos_min;
    TipoElemento elemento_auxiliar;
    Pila pila_auxiliar = p_crear();
    if(posicion_1 == posicion_2){
	return;
    }
    unsigned int pos_max, pos_min; // nos valemos de que o posicion_1 > posicion_2 , o posicion_2 > posicion_1
    if(posicion_1 > posicion_2)
    {
	pos_max = posicion_1;
	pos_min = posicion_2;
    }else{
    pos_max = posicion_2;
    pos_min = posicion_1;
    }
    int cont=1;
    while(p_es_vacia(pila) == false)
    {
	elemento_auxiliar = p_desapilar(pila);
	p_apilar(pila_auxiliar, elemento_auxiliar);

	if(cont == pos_max){elemento_de_pos_max = elemento_auxiliar;}

	if(cont == pos_min){elemento_de_pos_min = elemento_auxiliar;}
    cont++;
    }
    cont=1;
    p_devolver(pila,pila_auxiliar);
    while(p_es_vacia(pila) == false)
    {
	elemento_auxiliar = p_desapilar(pila);
	p_apilar(pila_auxiliar, elemento_auxiliar);
	if(cont == pos_min)
	{
	    p_desapilar(pila_auxiliar);
	    p_apilar(pila_auxiliar, elemento_de_pos_max);
	}

	if(cont == pos_max)
	{
	    p_desapilar(pila_auxiliar);
	    p_apilar(pila_auxiliar, elemento_de_pos_min);
	}
    cont++;
    }
    p_devolver(pila,pila_auxiliar);
}


Pila p_duplicar(Pila p_src)
{
    TipoElemento elemento_auxiliar;
    Pila p_duplicada = p_crear();
    Pila p_auxiliar = p_crear();
    while(p_es_vacia(p_src) == false)
    {
	elemento_auxiliar = p_desapilar(p_src);
	p_apilar(p_duplicada,elemento_auxiliar);
	p_apilar(p_auxiliar, elemento_auxiliar);
	
    }

    p_devolver(p_src, p_duplicada);
    p_devolver(p_duplicada,p_auxiliar);
    return p_duplicada;

}

unsigned int p_contar_elementos(Pila p_src)
{
    unsigned int contador_elementos = 0;
    TipoElemento aux;
    Pila p_aux = p_crear();
    while(p_es_vacia(p_src) == false)
    {
	aux = p_desapilar(p_src);
	contador_elementos++;
	p_apilar(p_aux, aux);
    }

    p_devolver(p_src, p_aux);
    return contador_elementos;
}

bool p_buscar_clave(Pila pila, int clave_a_encontrar){
    Pila p_aux=p_crear();
    bool encontrado=false;
    TipoElemento elemento;

    while(p_es_vacia(pila)!=true)
    {
        elemento=p_desapilar(pila);
        if (elemento->clave==clave_a_encontrar)
        {
            encontrado=true;
        }

        p_apilar(p_aux,elemento);
    }

    p_devolver(pila,p_aux);


    return encontrado;
}
