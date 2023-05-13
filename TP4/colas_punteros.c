#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "colas.h"
#define TAMANIO_MAXIMO 100
struct nodo
{
    TipoElemento datos;
    struct nodo *siguiente;
};

struct ColaRep
{
    struct nodo *frente;
    struct nodo *final;

};

typedef struct nodo *Nodo;
typedef struct ColaRep *Cola;

Cola c_crear()
{
    Cola cola_nueva = malloc(sizeof(struct ColaRep)); // asigno memoria para nueva cola 
    //cola_nueva->frente = (Nodo) malloc(sizeof(struct nodo) * TAMANIO_MAXIMO); // asigno memoria para elementos
    cola_nueva->frente = cola_nueva->final = NULL;
    return cola_nueva;

}

unsigned int c_longitud(Cola cola)
{

    unsigned int contador = 0;
    if(c_es_vacia(cola) == true) return 0;
    Nodo auxiliar = cola->frente;
    while(auxiliar->siguiente != NULL)
    {
	contador++;
	auxiliar = auxiliar->siguiente;
	
    }
    
    return contador;
}


bool c_es_vacia(Cola cola){return (cola->frente == NULL);}
bool c_es_llena(Cola cola){return (c_longitud(cola) == TAMANIO_MAXIMO);}
void c_encolar(Cola cola, TipoElemento elemento)
{
    
    if(c_es_llena(cola) == false)
    {
	Nodo nuevo_nodo = malloc(sizeof(struct nodo));
	nuevo_nodo->datos = elemento;
	nuevo_nodo->siguiente = NULL;

	if(c_es_vacia(cola) == true)
	{
	    cola->frente = nuevo_nodo;
	    cola->final = nuevo_nodo;
	}
	else
	{
	    cola->final->siguiente = nuevo_nodo;
	    cola->final = cola->final->siguiente;
	
	}
    }
    else
    {
	printf("\nQueue Overflow");
    }
}

TipoElemento c_desencolar(Cola cola)
{
    TipoElemento elemento_a_devolver;
    if(c_es_vacia(cola) == false)
    {
	elemento_a_devolver = cola->frente->datos;
	cola->frente = cola->frente->siguiente;
    }

    return elemento_a_devolver;

}

void c_mostrar(Cola cola)
{

    Nodo aux;
    aux = cola->frente;
    printf("\nClaves: ");
    while(aux->siguiente != NULL)
    {
	printf("%d ", aux->datos->clave);
	aux = aux->siguiente;
    }
    

}
