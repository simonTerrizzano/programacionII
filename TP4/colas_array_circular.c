#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "colas.h"
#define TAMANIO_MAXIMO 100
#define NULO -1
struct ColaRep
{
    TipoElemento *datos;
    int frente;
    int final;
    
};

typedef struct ColaRep *Cola;

Cola c_crear()
{
    Cola cola_nueva = malloc(sizeof(struct ColaRep));
    cola_nueva->datos = (TipoElemento*) malloc(sizeof(TipoElemento) * TAMANIO_MAXIMO);
    cola_nueva->frente = NULO;
    cola_nueva->final = NULO;
    return cola_nueva;
}

bool c_es_vacia(Cola cola){return (cola->frente == NULO && cola->final == NULO);}
bool c_es_llena(Cola cola){return (cola->frente == 0 && cola->final == TAMANIO_MAXIMO-1) || (cola->frente != 0 && (cola->final == cola->frente-1));} 
void c_encolar(Cola cola, TipoElemento elemento)
{
    if(c_es_llena(cola) == false)
    {
	if(c_es_vacia(cola) == true)
	{
	    cola->frente++;
	    cola->final++;
	    cola->datos[cola->final] = elemento;
	}
	else
	{
	    cola->final++;
	    if(cola->final == TAMANIO_MAXIMO)
	    {
		cola->final = 0;
	    }
	    cola->datos[cola->final] = elemento;
	}
    }
    else
    {
	printf("\nQueue Overflow\n");
    }

}

TipoElemento c_desencolar(Cola cola)
{
    TipoElemento elemento_aux;
    if(c_es_vacia(cola) == false)
    {
	if(cola->final == cola->frente)
	{
	    elemento_aux = cola->datos[cola->frente];
	    cola->frente=NULO;
	    cola->final=NULO;
	}
	else
	{
	    elemento_aux = cola->datos[cola->frente];
	    cola->frente++;
	    if(cola->frente == TAMANIO_MAXIMO)
		cola->frente=0;
	}
    }
    else
    {
	elemento_aux = NULL;
	return NULL;
	printf("\nQueue Underflow\n");
    }
    
    return elemento_aux;   
}

TipoElemento c_recuperar(Cola cola)
{
    TipoElemento elemento_a_devolver;
    elemento_a_devolver = cola->datos[cola->frente];
    return elemento_a_devolver;
}

void c_mostrar(Cola cola)
{
    TipoElemento elemento_auxiliar;
    int pos_frente = cola->frente;
    printf("\nClaves: ");
    if(c_es_vacia(cola) == false)
    {
	elemento_auxiliar = cola->datos[pos_frente];
	printf("%d ", elemento_auxiliar->clave);

	while(pos_frente != cola->final)
	{
	    pos_frente++;
	    if(pos_frente == TAMANIO_MAXIMO)
	    {
		pos_frente = 0;
	    }
	    elemento_auxiliar = cola->datos[pos_frente];
	    printf("%d ", elemento_auxiliar->clave);
	}
    }    
}

unsigned int c_longitud(Cola cola)
{
    unsigned int contador = 0;
    //TipoElemento elemento_auxiliar;
    int pos_frente = cola->frente;
    while(pos_frente != cola->final && (c_es_vacia(cola) == false))
    {
	contador++;
	pos_frente++;
	if(pos_frente == TAMANIO_MAXIMO)
	{
	    pos_frente = 0;
	}

    }

    return contador;
    
}
