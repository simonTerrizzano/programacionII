#include "listas.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANIO_MAXIMO 100

struct nodo
{
    TipoElemento datos;
    struct nodo *siguiente;

};

struct ListaRep
{
    struct nodo *inicio; // nodo cabecera
    int cantidad;

};
struct IteradorRep
{

    struct nodo *posicion_actual;
};

Lista l_crear()
{
    Lista nueva_lista = (Lista) malloc(sizeof(struct ListaRep));
    nueva_lista->inicio = NULL;
    nueva_lista->cantidad = 0;
    return nueva_lista;
 
}

bool l_es_vacia (Lista lista) { return lista->cantidad == 0; }

bool l_es_llena (Lista lista) { return lista->cantidad == TAMANIO_MAXIMO; }

int l_longitud(Lista lista)
{
    return lista->cantidad;

}

TipoElemento l_recuperar(Lista lista, int pos)
{
    struct nodo *temp2 = lista->inicio;
    for(int i = 0; i<pos-1;i++)
    {
	temp2 = temp2->siguiente;

    }

    return temp2->datos;

}

void l_agregar(Lista lista, TipoElemento elemento)
{
    if(l_es_llena(lista)) {return;}

    struct nodo *nuevo_nodo = malloc(sizeof(struct nodo));
    nuevo_nodo->datos = elemento;
    nuevo_nodo->siguiente = NULL;

    // si la lista no tiene ningun nodo todavia
    if(lista->inicio == NULL)
    {
	// el nuevo nodo sera cabecera
	lista->inicio = nuevo_nodo;

    }
    else
    {
	// busca el ultimo nodo.
	struct nodo *temp2 = lista->inicio;
	while(temp2->siguiente != NULL)
	{
	    temp2 = temp2->siguiente;
	}

	temp2->siguiente = nuevo_nodo;
    }

    lista->cantidad++;

}

void l_borrar(Lista lista, int clave)
{
    if(l_es_vacia(lista))
    {
	return;

    }

    struct nodo *actual = lista->inicio;
    while(actual != NULL && actual->datos->clave == clave)
    {
	lista->inicio = actual->siguiente;
	free(actual);
	lista->cantidad--;
	actual = lista->inicio;
    }
    while(actual != NULL && actual->siguiente != NULL)
    {
	if(actual->siguiente->datos->clave==clave)
	{
	    struct nodo *temp = actual->siguiente;
	    actual->siguiente = temp->siguiente;
	    free(temp);
	    lista->cantidad--;
	}
	else
	{
	    actual = actual->siguiente;
	}
    }
}

void l_insertar(Lista lista, TipoElemento elemento, int pos)
{
    if(l_es_llena(lista)) {return;}

    struct nodo *nuevo_nodo = malloc(sizeof(struct nodo));
    nuevo_nodo->datos = elemento;
    nuevo_nodo->siguiente = NULL;

    if(pos == 1)
    {
	nuevo_nodo->siguiente = lista->inicio;
	lista->inicio = nuevo_nodo;
       
    }
    else
    {
	struct nodo *temp2 = lista->inicio;
	for(int i = 0; i < pos-2; i++)
	{
	    temp2 = temp2->siguiente;
	}
	nuevo_nodo->siguiente = temp2->siguiente;
	temp2->siguiente = nuevo_nodo;

    }

    lista->cantidad++;
    
}

void l_eliminar(Lista lista, int pos)
{
    if(l_es_vacia(lista)) {return;}
    struct nodo *actual = lista->inicio;
    if(1 <= pos && pos <= l_longitud(lista))
    {
	if(pos==1)
	{
	    lista->inicio = actual->siguiente;
	    free(actual);
	    
	}
	else
	{
	    for(int i = 0; i < pos-2; i++)
	    {
		actual = actual->siguiente;

	    }
	    struct nodo *temp = actual->siguiente;
	    actual->siguiente = temp->siguiente;
	    free(temp);

	}
	lista->cantidad--;

    }

}

TipoElemento l_buscar(Lista lista, int clave)
{
    struct nodo *actual = lista->inicio;
    while(actual != NULL)
    {
	if(actual->datos->clave == clave)
	{
	    return actual->datos;
	}

	actual = actual->siguiente;
    }

    return NULL;
}


void l_mostrarLista(Lista lista)
{

    struct nodo *temp2 = lista->inicio;
    printf("Contenido de la lista: ");
    while(temp2 != NULL)
    {
	printf("%3d ", temp2->datos->clave);
	temp2 = temp2->siguiente;
    }

    printf("\n");

}
		 
Iterador iterador(Lista lista)
{
    Iterador iter = (Iterador) malloc(sizeof(struct IteradorRep));
    iter->posicion_actual = lista->inicio;
    return iter;

}

bool hay_siguiente(Iterador iterador)
{
    return (iterador->posicion_actual != NULL);
}

TipoElemento siguiente(Iterador iterador)
{
    TipoElemento actual = iterador->posicion_actual->datos;
    iterador->posicion_actual = iterador->posicion_actual->siguiente;
    return actual;
}

