#include "ejercicio_7.h"
/*
Dada dos pilas realizar una función que permita determinar los elementos que tienen
en común. Debe retornar una nueva pila con esos elementos (que están en ambas
pilas) sin perder las pilas originales. Determinar la complejidad algorítmica de la
solución.
Ejemplo: si “P1” contiene (1,4,7,9,8) y “P2” contiene (4,1,6,9,3) el resultado será la
pila “PR” = (1,4,9). 
*/
Pila elemEnComun(Pila P1,Pila P2){
    Pila PR = p_crear();
    if (p_es_vacia(P1)||p_es_vacia(P2))//Sí alguna de la pilas está vacia retornar una una pila vacia
    {
        return PR;
    }
    TipoElemento ElemP1;
    TipoElemento ElemP2;
    Pila Pila_Aux_P1=p_crear();
    Pila Pila_Aux_P2=p_crear();
    int vector[TAMANIO_MAXIMO_PILAS];
    memset(vector, 0, TAMANIO_MAXIMO_PILAS*sizeof(int));
    int k=0;

    while (p_es_vacia(P1)!=true){
            ElemP1=p_desapilar(P1);//Evaluamos los elementos de la primera pila
            p_apilar(Pila_Aux_P1,ElemP1);//Apilamos un una pila auxiliar para no perder la original
        while (p_es_vacia(P2)!=true){
            ElemP2=p_desapilar(P2);//Elaluamos todos los elementos de la 2da pila por cada elemento de la 1ra
            p_apilar(Pila_Aux_P2,ElemP2); //Apilamos un una pila auxiliar para no perder la original  
            if (ElemP1->clave==ElemP2->clave && numeroyaencontrado(ElemP1->clave,vector,k)!=true){
                //Evaluamos si las clave son iguales 
                //y ademas si la clave no fue encontrada previamente
                p_apilar(PR,ElemP1);
                vector[k]=ElemP1->clave;//Guardamos la clave encontrada para no volver a buscarla
                k++;
                while (p_es_vacia(P2)!=true)//Recorremos lo que resta de la pila para no encontrar claves repetidas en la 2da pila
                {
                    ElemP2=p_desapilar(P2);
                    p_apilar(Pila_Aux_P2,ElemP2);  
                }
                
            }
        }
        while (p_es_vacia(Pila_Aux_P2)!=true){
            //Volvemos a apilas la 2da pila para buscar 
            //elementos en común con el siguente elemento de la 1ra pila
            ElemP2=p_desapilar(Pila_Aux_P2);
            p_apilar(P2,ElemP2);
        }
        
    }

    while (p_es_vacia(Pila_Aux_P1)!=true){//Reconstruimos pila original
        ElemP1=p_desapilar(Pila_Aux_P1);
        p_apilar(P1,ElemP1);
    }

    return PR;
}
/*
Algoritmo de busqueda secuencial para encontrar un numero determinado en un arreglo
*/
bool numeroyaencontrado(int numero, int *arreglo,int n){
    for (int i = 0; i < n; i++)
    {
        if (numero==arreglo[i])
        {
            return true;
        }
    }
    return false;
}