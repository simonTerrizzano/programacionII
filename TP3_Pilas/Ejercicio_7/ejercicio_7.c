#include "ejercicio_7.h"

Pila elemEnComun(Pila P1,Pila P2){
    Pila PR = p_crear();
    if (p_es_vacia(P1)||p_es_vacia(P2))
    {
        return PR;
    }
    TipoElemento ElemP1;
    TipoElemento ElemP2;
    Pila Pila_Aux_P1;
    Pila Pila_Aux_P2;
    

    for (int i = 0; i < p_longitud(P1); i++)
    {
            ElemP1=p_desapilar(P1);
            p_apilar(Pila_Aux_P1,ElemP1);
        for (int j = 0; j < p_longitud(P2); j++)
        {
            ElemP2=p_desapilar(P2);
            p_apilar(Pila_Aux_P2,ElemP2);    
            if (ElemP1->clave==ElemP2->clave)
            {
                p_apilar(PR,ElemP1);
            }
        }
        tranferir(Pila_Aux_P2,P2);
    }
}