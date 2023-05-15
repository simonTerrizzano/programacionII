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
    printF("La complejidad algoritmica de la funcion Divisores sin contar las funciones de los TAD de colas es de O(n^a)");  //Complejidad algoritmica
    system("PAUSE");
    return 0;
}
