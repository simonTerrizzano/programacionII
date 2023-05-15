#include "Ejercicio_5.c"

int main(void)
{
    Cola resultado;
    Cola cola = c_crear();
    printf("Se creara la cola \n");
    crearCola(cola);
    printf("La cola es la siguiente: \n");
    c_mostrar(cola);
    Divisores(cola);
    system("PAUSE");
    return 0;
}