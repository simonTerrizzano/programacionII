#include "pilas.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100 
struct PilaRep
{
    int top; // mantiene el indice del array al que está apuntando actualmente
    TipoElementos *elementos; // apunta a un tipo elementos del array
};


Pila p_crear()
{
    Pila nueva_pila = (Pila*) malloc(sizeof(Pila));
    nueva_pila->elementos = (TipoElementos*) calloc(MAX, sizeof(TipoElementos));
    nueva_pila->top = 0;
    return nueva_pila;
}

bool


void p_apilar(Pila pila, TipoElemento elemento)
{
    // si todavia hay espacio en la pila. agrega elemento
    if(top < MAX-1)
    {
	pila->elementos[pila->top] = elemento;
	pila->top++;
    }
    else
    {
	perror("Stackoverflow"); // si no hay espacio entoces stackoverflow
    }
}

