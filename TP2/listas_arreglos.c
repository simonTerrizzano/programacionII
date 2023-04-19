#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAMANIO_MAXIMO 100
#include "listas.h"


struct ListaRep
{
    TipoElemento *valores; // arreglo de "Tipoelemento"
    int cantidad;
    int libre;
    int inicio;
   
};

struct IteradorRep
{

    Lista lista;
    int posicion_actual;

};


Lista l_crear()
{

    Lista nueva_lista = (Lista) malloc(sizeof(struct ListaRep));
    nueva_lista->valores = calloc(TAMANIO_MAXIMO, sizeof(TipoElemento));
    nueva_lista->cantidad = 0;
    return nueva_lista;
    

}


bool l_es_vacia(Lista lista)
{
    return ((lista->cantidad) == 0);
}

bool l_es_llena(Lista lista)
{
    return ((lista->cantidad) == TAMANIO_MAXIMO);
}

int l_longitud(Lista lista)
{
    return lista->cantidad;


}

void l_agregar(Lista lista, TipoElemento elemento)
{
    // si la lista no esta llena 
    if(l_es_llena(lista) != true)
    {
	// agrega el elemento en la ultima posicion
	lista->valores[lista->cantidad] = elemento;
	// aumenta la cantidad de elementos en lista
	lista->cantidad++;
    }
}

void l_borrar(Lista lista, int clave)
{
    // si la lista esta vacia entonces no evaluando.
    if(l_es_vacia(lista))
    {
	return;
    }
    
    int pos = 0;
    // mientras la posicion no sea la ultima de la lista
    while(pos < lista->cantidad)
    {
	// si de los elementos de la lista, un elemento tiene la clave buscada
	//entonces:
	if(lista->valores[pos]->clave == clave)
	{
	    // se realiza un shift a la izquierda <<pisar/eliminar>> el elemento a borrar
	    for(int i = pos; i < lista->cantidad - 1; i++)
	    {

		lista->valores[i] = lista->valores[i+1];
	    }

	    // se reduce en (-1) la cantidad de elementos en lista.
	    lista->cantidad--;
	}
	else
	{
	    // si no encuentra la clave buscada, continua a la siguinte posicion.
	    pos++;
	}	
    }
}


TipoElemento l_buscar(Lista lista, int clave)
{
    int pos = 0;
    while(pos < lista->cantidad)
    {
	if(lista->valores[pos]->clave == clave)
	{
	    return lista->valores[pos];
	}
	pos++;
    }
    return NULL;

}

void l_insertar(Lista lista, TipoElemento elemento, int pos)
{

    // i = ultima posicion.
    // se mueven todos los elementos de la lista una posicion mas, de manera tal que la posicion en la que
    // se quiere insertar el nuevo elemento quede <<libre>>
    for(int i = lista->cantidad; i >= pos && i > 0; i--)
    {
	lista->valores[i] = lista->valores[i-1];
    }
    
    lista->valores[pos-1] = elemento;
    lista->cantidad++;
}

void l_eliminar(Lista lista, int pos)
{
    // si la posicion es valida 
    if(1 <= pos && pos <= l_longitud(lista))
    {
	
	for(int i = pos-1; i < lista->cantidad; i++)
	{
	    lista->valores[i] = lista->valores[i+1];
	}

	lista->cantidad--;
    }
    

}

TipoElemento l_recuperar(Lista lista, int pos)
{
    return lista->valores[pos-1];
    
}

void l_mostrarLista(Lista lista)
{
    printf("Contenido de la lista: ");
    for(int i=0; i < lista->cantidad; i++)
    {
	printf("%d /", lista->valores[i]->clave);
    }

    printf("\n");
}

Iterador iterador(Lista lista)
{

    Iterador iter = (Iterador) malloc(sizeof(struct IteradorRep));
    iter->lista = lista;
    iter->posicion_actual = 0;
    return iter;

}

bool hay_siguiente(Iterador iterador)
{
    return iterador->posicion_actual < iterador->lista->cantidad;
}

TipoElemento siguiente(Iterador iterador)
{
    return iterador->lista->valores[iterador->posicion_actual++];
}

