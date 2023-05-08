#include "ejercicio_5.h"

Pila p_invertir(Pila pila){
    Pila p_inv=p_crear();
    Pila p_aux=p_crear();
    Pila p_aux_2=p_crear();

    p_aux=p_duplicar(pila);//duclicamos pila original para no perderla

    p_devolver(p_inv,pila);//tranferimos pila para que se apile de forma inversa


    p_devolver(p_aux_2,p_aux);
    p_devolver(pila,p_aux_2);//recuperamos pila original


    return p_inv;
}