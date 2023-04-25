#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilas.h"
#define MAX 100

typedef struct 
{
    TipoElemento elemento;
    struct nodo *siguiente;
} nodo;
 
struct PilaRep
{
    nodo *tope;
    size_t cantidad;
};

Pila p_crear()
{
    Pila nueva_pila = (Pila) malloc(sizeof(struct PilaRep));
    nueva_pila->tope = NULL;
    nueva_pila->cantidad = 0;
    return nueva_pila;
}

//bool p_es_llena(Pila pila){return (pila->cantidad == MAX);}
bool p_es_vacia(Pila pila){return (pila->tope == NULL);}

void p_apilar(Pila pila, TipoElemento elemento)
{
    nodo *new_nodo = (nodo*) malloc(sizeof(nodo));
    new_nodo->siguiente = pila->tope;
    pila->tope = new_nodo;
    pila->tope->elemento = elemento;
    pila->cantidad++;   
}


TipoElemento p_desapilar(Pila pila)
{
    if(p_es_vacia(pila) == false)
    {
	nodo *del_node;
	del_node = pila->tope;
	pila->tope = pila->tope->siguiente;
	free(del_node);
	pila->cantidad--;
	return pila->tope->elemento;
    }
    else
    {
	printf("\nLa pila esta vacia!");
	return NULL;
    }
}

TipoElemento p_tope(Pila pila)
{
    if(p_es_vacia(pila) == false)
    {
	return pila->tope->elemento;
	
    }
    else
    {
	printf("\nLa pila esta vacia!");
	return NULL;   
    }
}

void p_mostrar(Pila pila)
{
    TipoElemento te;
    nodo *aux_nodo;
    aux_nodo = pila->tope;
    while(pila->tope->siguiente != NULL)
    {
	te = pila->tope->elemento;
	printf("\nClave: %d\n", te->clave);
	pila->tope = pila->tope->siguiente;
    }

    pila->tope = aux_nodo;

}
