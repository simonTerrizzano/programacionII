#include "pilas.h"
#include "tipo_elemento.c"



struct PilaRep
{
    TipoElemento *valores;
    unsigned int tope;
};

Pila p_crear(){
    Pila nueva_pila = (Pila) malloc(sizeof(struct PilaRep));
    nueva_pila->valores = calloc((TAMANIO_MAXIMO+1), sizeof(TipoElemento));
    nueva_pila->tope = 0;
    return nueva_pila;
}


void p_apilar(Pila pila, TipoElemento elemento){
    if (p_es_llena(pila))
    {
        return;
    }
    pila->tope++;
    pila->valores[pila->tope] = elemento;
}

TipoElemento p_desapilar(Pila pila){
    if (p_es_vacia(pila))
    {
        return NULL;
    }

    TipoElemento elemento = pila->valores[pila->tope];
    pila->tope--;
    return elemento;
}

TipoElemento p_tope(Pila pila){
    if (p_es_vacia(pila))
    {
        return NULL;
    }
    return pila->valores[pila->tope];
}

bool p_es_vacia(Pila pila){
    return pila->tope == 0;
}

bool p_es_llena(Pila pila){
    return (pila->tope == TAMANIO_MAXIMO);
}

void p_mostrar(Pila pila){
    if (p_es_vacia(pila))
    {
        printf("\nLa pila está VACIA\n");
        return;
    }
    
    Pila pilaAUX;
    pilaAUX = p_crear();
    TipoElemento elemento_a_mostrar;

    printf("Contanido de la pila: ");

    while (p_es_vacia(pila)!=true)
    {
        elemento_a_mostrar=p_desapilar(pila);
        printf("%d ",elemento_a_mostrar->clave);
        p_apilar(pilaAUX, elemento_a_mostrar);
    }

    while (p_es_vacia(pilaAUX)!=true)
    {
        elemento_a_mostrar=p_desapilar(pilaAUX);
        p_apilar(pila,elemento_a_mostrar);
    }
    
}
