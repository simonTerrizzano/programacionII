#include "UtilidadesColas.c"
#include <time.h>

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

int main(){
    bool resultado;
    TipoElemento X;
    Cola cola1 = c_crear();
    Cola cola2 = c_crear();
    printf("Se creara la cola 1 \n");
    crearCola(cola1);
    printf("Se creara la cola 2 \n");
    crearCola(cola2);
    resultado = compararIgualdadCola(cola1, cola2);
    if (resultado)
    {
        printf("Las colas son iguales \n");
    }
    else{
        printf("Las colas no son iguales \n");
    }
    system("PAUSE");
}