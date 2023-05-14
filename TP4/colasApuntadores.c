#include "colas.h"
#include "tipo_elemento.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct Nodo {
TipoElemento datos;
struct Nodo *siguiente;
};

struct ColaRep {
struct Nodo *frente;
struct Nodo *final;
};

Cola c_crear(void){
    Cola nueva_cola = (Cola) malloc(sizeof(struct ColaRep));
    nueva_cola->frente=NULL;
    nueva_cola->final=NULL;
    return nueva_cola;
}

void c_encolar(Cola cola, TipoElemento elemento){
    if (c_es_llena(cola))
    {
        return;
    }
    struct Nodo *nuevo_nodo = malloc(sizeof(struct Nodo));
    nuevo_nodo->datos=elemento;
    nuevo_nodo->siguiente=NULL;

    if (c_es_vacia(cola))
    {
        cola->frente=nuevo_nodo;
    }else{
        cola->final->siguiente=nuevo_nodo;
    }
    cola->final=nuevo_nodo;
}

TipoElemento c_desencolar(Cola cola){
    if (c_es_vacia(cola))
    {
        return NULL;
    }
    struct Nodo *inicio=cola->frente;
    TipoElemento elemento=inicio->datos;
    cola->frente=inicio->siguiente;
    free(inicio);
    return elemento;
}

int c_longitud(Cola cola){
    int i=0;
    struct Nodo *N = cola->frente;
    while (N!=NULL)
    {
        i++;
        N=N->siguiente;
    }
    return i;
}

bool c_es_vacia(Cola cola){
    return longitud(cola)==0;
}

bool c_es_llena(Cola cola){
    return longitud(cola)==TAMANIO_MAXIMO;
}

void c_mostrar(Cola cola){
    if (c_es_vacia(cola))
    {
        printf("La cola está vacia.");
        return;
    }
    Cola Caux = c_crear();
    TipoElemento X = te_crear(0);
    
    printf("Imprimiendo las Claves de la Cola \n");
    // La cola se debe desencolar y guardar en una auxiliar
    while (c_es_vacia(cola) != true) {
        X = c_desencolar(cola);
        printf("Clave: %d \n", X->clave);
        c_encolar(Caux, X);
    }
    // ahora paso la auxiliar a la cola de nuevo para dejarla como estaba
    while (c_es_vacia(Caux) != true) {
        X = c_desencolar(Caux);
        c_encolar(cola, X);
    }
    
}
