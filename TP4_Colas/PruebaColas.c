#include "colasApuntadores.c"
#include <time.h>

void Randomizar(Cola cola){
    TipoElemento X;
    srand(time(0));
    for (int i = 0; i < 10; i++)
    {
        X = te_crear(rand()%100);
        c_encolar(cola,X);
    }
}

int main(int argc, char const *argv[])
{
    Cola cola = c_crear();
    Randomizar(cola);
    c_mostrar(cola);
    printf("\n");
    printf("La longitud de la cola es de %d",c_longitud(cola));
    printf("\n");
    system("PAUSE");
    return 0;
}
