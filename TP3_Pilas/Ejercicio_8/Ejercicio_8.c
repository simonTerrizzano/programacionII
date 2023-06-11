#include "ejercicio_8.h"

Pila elementosRepetidos(Pila pila){
    Pila PR=p_crear();
    if(p_es_vacia(pila)){
        return PR;
    }

    Pila pAux=p_crear();
    Pila pBusqueda=p_crear();
    TipoElemento elemento;
    TipoElemento elemento_a_contar;
    int arreglo[TAMANIO_MAXIMO];
    memset(arreglo, 0, TAMANIO_MAXIMO*sizeof(int));
    int k=0;
    int contador;
    int *pcont=calloc((TAMANIO_MAXIMO+1), sizeof(int));
    int j=0;

    while (p_es_vacia(pila)!=true)
    {
        elemento=p_desapilar(pila);
        p_apilar(pAux,elemento);
        p_apilar(pBusqueda,elemento);
    }
    while (p_es_vacia(pAux)!=true)
    {
        elemento=p_desapilar(pAux);
        p_apilar(pila,elemento);
    }
    
    


    while (p_es_vacia(pBusqueda)!=true)
    {
        contador=0;
        elemento=p_desapilar(pBusqueda);
        elemento_a_contar=te_crear(elemento->clave);
        
        while (p_es_vacia(pila)!=true && numeroyaencontrado(elemento_a_contar->clave,arreglo,k)!=true)
        {
            elemento=p_desapilar(pila);
            p_apilar(pAux,elemento);
            if (elemento->clave==elemento_a_contar->clave)
            {
                contador++;
            }
            
        }
        if (numeroyaencontrado(elemento_a_contar->clave,arreglo,k)!=true)
        {
            arreglo[k]=elemento_a_contar->clave; 
            k++; 
            pcont[j]=contador;
            elemento_a_contar->valor=&pcont[j];
            j++;
            p_apilar(PR,elemento_a_contar);
        }

        while (p_es_vacia(pAux)!=true)
        {
            elemento=p_desapilar(pAux);
            p_apilar(pila,elemento);
        }

    }
    
    
    return PR;
}

/*
Algoritmo de busqueda secuencial para encontrar un numero determinado en un arreglo
*/
bool numeroyaencontrado(int numero,int *arreglo,int n){
    for (int i = 0; i < n; i++)
    {
        if (numero==arreglo[i])
        {
            return true;
        }
    }
    return false;
}