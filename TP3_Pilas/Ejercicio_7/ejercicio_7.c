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
    if (p_es_vacia(P1)||p_es_vacia(P2))
    {
        return PR;
    }
    TipoElemento ElemP1;
    TipoElemento ElemP2;
    Pila Pila_Aux_P1=p_crear();
    Pila Pila_Aux_P2=p_crear();
    int vector[TAMANIO_MAXIMO];
    int k=0;

    while (p_es_vacia(P1)!=true){
            ElemP1=p_desapilar(P1);
            p_apilar(Pila_Aux_P1,ElemP1);
        while (p_es_vacia(P2)!=true){
            ElemP2=p_desapilar(P2);
            p_apilar(Pila_Aux_P2,ElemP2);    
            if (ElemP1->clave==ElemP2->clave&&numeroyaencontrado(ElemP1->clave,vector,k)!=true){
                p_apilar(PR,ElemP1);
                vector[k]=ElemP1->clave;
                k++;
                while (p_es_vacia(P2)!=true)
                {
                    ElemP2=p_desapilar(P2);
                    p_apilar(Pila_Aux_P2,ElemP2);  
                }
                
            }
        }
        while (p_es_vacia(Pila_Aux_P2)!=true){
            ElemP2=p_desapilar(Pila_Aux_P2);
            p_apilar(P2,ElemP2);
        }
        
    }

    while (p_es_vacia(Pila_Aux_P1)!=true){
        ElemP1=p_desapilar(Pila_Aux_P1);
        p_apilar(P1,ElemP1);
    }

    return PR;
}

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