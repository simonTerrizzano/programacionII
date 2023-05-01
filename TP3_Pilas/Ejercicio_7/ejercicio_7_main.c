#include "ejercicio_7.c"


int main(void)
{
    int cantingresoP1;
    int cantingresoP2;
    int numero_a_apilar;
    int check=0;

    Pila P1=p_crear();
    Pila P2=p_crear();
    Pila PR;

    TipoElemento elemento = te_crear(0);

    printf("Ingrese la cantidad de elementos de la 1ra Pila entre 0 y %i",TAMANIO_MAXIMO);
    cantingresoP1 = ingreso_normalizado_enteros(0,10);

    printf("Ingrese la cantidad de elementos de la 2da Pila entre 0 y %i",TAMANIO_MAXIMO);
    cantingresoP2 = ingreso_normalizado_enteros(0,10);

    printf("Carga de la 1ra Pila");

    for (int i = 0; i < cantingresoP1; i++)
    {
        numero_a_apilar=ingreso_normalizado_enteros(-1000,1000);
        elemento->clave=numero_a_apilar;
        p_apilar(P1,elemento);
    }
    
    printf("Carga de la 2da Pila");

    for (int i = 0; i < cantingresoP2; i++)
    {
        numero_a_apilar=ingreso_normalizado_enteros(-1000,1000);
        elemento->clave=numero_a_apilar;
        p_apilar(P2,elemento);
    }

    PR = elemEnComun(P1,P2);

    p_mostrar(PR);
    
    return 0;
}
