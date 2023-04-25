#include "pilas.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

struct PilaRep
{
    size_t cantidad;
    int top; // mantiene el indice del array al que está apuntando actualmente
    TipoElemento *elementos; // apunta a un tipo elementos del array
};


Pila p_crear()
{
    Pila nueva_pila = (Pila) malloc(sizeof(struct PilaRep));
    nueva_pila->elementos = (TipoElemento*) calloc(MAX, sizeof(TipoElemento));
    nueva_pila->top = 0;
    nueva_pila->cantidad = 0;
    return nueva_pila;
}

bool p_es_vacia(Pila pila){return (pila->top == 0);}
bool p_es_llena(Pila pila){return (pila->top == MAX);}

void p_apilar(Pila pila, TipoElemento elemento)
{
    // si todavia hay espacio en la pila. agrega elemento
    if(p_es_llena(pila) == false)
    {
	pila->elementos[pila->top] = elemento;
	pila->top++;
	pila->cantidad++;
    }
    else
    {
	perror("Stackoverflow"); // si no hay espacio entoces stackoverflow
    }
}

TipoElemento p_desapilar(Pila pila)
{
    if(p_es_vacia(pila) == false)
    {
	pila->cantidad--;
	pila->top--;
	return pila->elementos[pila->top];
	
    }
    else
    {
	perror("Stackunderflow");
	
    }

}

TipoElemento p_tope(Pila pila)
{
    if(p_es_vacia(pila) == false)
    {
	return pila->elementos[(pila->top)-1];
    }
    else
    {
	perror("La pila esta vacia!");
    }
}

void p_mostrar(Pila pila)
{
    TipoElemento te;
    int aux_index = pila->top;
    while(p_es_vacia(pila) == false)
    {
	te = p_tope(pila);
	printf("\nClave: %d\n", te->clave);
	pila->top--;
    }
    pila->top = aux_index;
}

