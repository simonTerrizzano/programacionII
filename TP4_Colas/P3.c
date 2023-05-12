#include "colasApuntadores.c"
#include <time.h>
#include "DataEntry.c"

bool compararIgualdadCola(Cola C1,Cola C2);

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
        Y = c_desencolar(temp);
        X = c_desencolar(temp);
        c_encolar(C2,Y);
        c_encolar(C1,X);
    }
    return resultado;
}

void Randomizar(Cola cola);
void Randomizar(Cola cola){
    TipoElemento X;
    srand(time(0));
    for (int i = 0; i < 10; i++)
    {
        X = te_crear(rand()%100);
        c_encolar(cola,X);
    }
}

int main(){

}