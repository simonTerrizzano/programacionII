#include "Ejercicio_3.h"

bool compararIgualdadCola(Cola C1,Cola C2){
    Cola temp = c_crear();
    TipoElemento X,Y;
    bool resultado = true;
    if (c_longitud(C1) != c_longitud(C2)){return false;}
    while (!c_es_vacia(C1))
    {
        X = c_desencolar(C1);
        Y = c_desencolar(C2);
        if (X->clave != Y->clave)
        {
            resultado = false;
        }
        c_encolar(temp,X);
        c_encolar(temp,Y);
    }
    while (!c_es_vacia(temp))
    {
        X = c_desencolar(temp);
        Y = c_desencolar(temp);
        c_encolar(C1,X);
        c_encolar(C2,Y);
    }
    return resultado;
}