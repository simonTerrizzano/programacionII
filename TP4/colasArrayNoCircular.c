#include "colas.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

struct ColaRep
{
    TipoElemento *valores; // arreglo de "Tipoelemento"
    int frente;
    int final;
};
typedef struct ColaRep *Cola;

Cola c_crear()
{
    Cola nueva_cola = (Cola) malloc(sizeof(struct ColaRep));
    nueva_cola->valores = (TipoElemento*) malloc(TAMANIO_MAXIMO * sizeof(TipoElemento));
    nueva_cola->frente = 0;
    nueva_cola->final = 0;
    return nueva_cola;
}

bool c_es_vacia(Cola cola){
    return (cola->frente == cola->final);
}

bool c_es_llena (Cola cola){
    return (cola->final == TAMANIO_MAXIMO);
}

void c_encolar(Cola C, TipoElemento elemento){
    if (c_es_llena(C)) {
        printf("La cola está llena\n");
        return;
    }
    C->valores[C->final] = elemento;
    C->final = C->final + 1;
    return;
}



TipoElemento c_desencolar(Cola cola) {
    TipoElemento X = te_crear(0);
    if (c_es_vacia(cola)) {
        return X;
    }
    int contador = 0;
    X = cola->valores[contador];
    while (contador != cola->final - 1) {
        cola->valores[contador] = cola->valores[contador+1];
        contador++;
    }
    cola->final--;
    return X;
} 

void c_mostrar (Cola C){
    if (c_es_vacia(C))
    {
        printf("La cola está vacia.");
        return;
    }
    
    Cola T = c_crear();
    //int final = C->final;
    TipoElemento X;
    printf("Imprimiendo las Claves de la Cola \n");
    while (!c_es_vacia(C))
    {
        X = c_desencolar(C);
        printf("Clave: %d\n",X->clave);
        c_encolar(T, te_crear(X->clave));
    }
    while (!c_es_vacia(T))
    {
        X = c_desencolar(T);
        c_encolar(C, te_crear(X->clave));
    }
    return;
}

TipoElemento c_recuperar (Cola C){
    TipoElemento X = te_crear(0);
    if (c_es_vacia(C)){return X;}
    X = C->valores[C->frente];
    return X;
}

int c_longitud (Cola cola){
    unsigned int contador = 0;
    int pos_frente = cola->frente;
    while(pos_frente <= cola->final && (c_es_vacia(cola) == false))
    {
	pos_frente++;
	contador++;
    }
    
    return contador;
}
