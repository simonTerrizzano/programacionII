#include "Ejercicio_4.h"

Cola c_noRepetidos(Cola cola){
    Cola CR=c_crear();
    if(c_es_vacia(cola)){
        return CR;
    }

    Cola cAux=c_crear();
    Cola cBusqueda=c_crear();
    TipoElemento elemento;
    TipoElemento elemento_a_contar;
    int arreglo[TAMANIO_MAXIMO_COLAS];
    memset(arreglo, 0, TAMANIO_MAXIMO_COLAS*sizeof(int));
    int k=0;
    int contador;
    int j=0;

    while (c_es_vacia(cola)!=true)
    {
        elemento=c_desencolar(cola);
        c_encolar(cAux,elemento);
        c_encolar(cBusqueda,elemento);
    }


    while (c_es_vacia(cBusqueda)!=true)
    {
        contador=0;
        elemento=c_desencolar(cBusqueda);
        elemento_a_contar=te_crear(elemento->clave);
        
        while (c_es_vacia(cAux)!=true && numeroyaencontrado(elemento_a_contar->clave,arreglo,k)!=true)//por cada elemento de la 
        de la cola recorre la cola entera a excepción de los elementos la buscados//
        {
            elemento=c_desencolar(cAux);
            c_encolar(cola,elemento);
            if (elemento->clave==elemento_a_contar->clave)
            {
                contador++;//cuenta las veces que se repite el elemento en la cola
            }
            
        }
        if (contador==1)//si el elemento se contó solo una vez se encola
        {
            c_encolar(CR,elemento_a_contar); 
        }else{//si se contó más de una vez se agrega al arreglo para que no lo vuelva a contar
            arreglo[k]=elemento_a_contar->clave; 
            k++;
        }

        while (c_es_vacia(cola)!=true)
        {
            elemento=c_desencolar(cola);
            c_encolar(cAux,elemento);//devulvemos la cola para volver a buscar
        }

    }
    while (c_es_vacia(cAux)!=true)
    {
        elemento=c_desencolar(cAux);
        c_encolar(cola,elemento);//recuperamos la cola
    }
    
    
    
    return CR;//retornamos la cola sin repeticiones
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
