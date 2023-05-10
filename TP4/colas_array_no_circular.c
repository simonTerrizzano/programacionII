#include "colas.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAMANIO_MAXIMO 100
#define NULO -1

struct ColaRep
{
    TipoElemento *valores; // se apunta al arreglo que contendra los elementos
    int frente;
    int final;
};

typedef struct ColaRep *Cola;

Cola c_crear()
{
    Cola cola_nueva = malloc(sizeof(struct ColaRep));
    cola_nueva->valores = (TipoElemento) malloc(sizeof(TipoElemento) * TAMANIO_MAXIMO) // se crea el array de elementos 
    cola_nueva->frente = NULO;
    cola_nueva->final = NULO;
    return cola_nueva;
}

bool c_es_vacia(Cola cola){return (cola->final == NULO && cola->frente == NULO);}
bool c_es_llena(Cola cola){return (cola->final == TAMANIO_MAXIMO-1);}
void c_encolar(Cola cola, TipoElemento elemento)
{
    // si no está llena
    if(c_es_llena(cola) == false)
    {
	// si esta vacia entonces pone ambos en posicion 0
	if(c_es_vacia(cola) == true)
	{
	    cola->frente++;
	    cola->final++;
	    cola->valores[cola->final] = elemento;
	}
	else
	{
	    cola->final++;
	    cola->valores[cola->final] = elemento;
	}
    }
    else
    {
	printf("\nError. Queue overflow :(\n");
    }
}

TipoElemento c_desencolar(Cola cola)
{
    TipoElemento elemento_a_devolver;
    if(c_es_vacia(cola) == false)
    {
	if(cola->final == cola->frente)
	{
	    elemento_a_devolver = cola->valores[cola->frente];
	    cola->final = NULO;
	    cola->frente = NULO;
	}
	else
	{
	    elemento_a_devolver = cola->valores[cola->frente];
	    free(cola->valores[cola->frente]);
	    cola->frente++;
	}
    }
    else
    {
	printf("\nError. Queue underflow :(\n");
    }
}

TipoElemento c_recuperar(Cola cola)
{
    TipoElemento elemento_a_devolver;
    elemento_a_devolver = cola->valores[cola->frente];
    return elemento_a_devolver;

}

void c_mostrar(Cola cola)
{
    TipoElemento elemento_auxiliar;
    int pos_frente = cola->frente;
    printf("\nClaves: ");
    while(pos_frente <= cola->final && (c_es_vacia(cola) == false))
    {
	elemento_auxiliar = cola->valores[pos_frente];
	printf("%d ", elemento_auxiliar->clave);
	pos_frente++;
    }    
}

unsigned int c_longitud(Cola cola)
{
    unsigned int contador = 0;
    int pos_frente = cola->frente;
    while(pos_frente <= cola->final && (c_es_vacia(cola) == false))
    {
	pos_frente++;
	contador++;
    }
    
    return contador;
}
