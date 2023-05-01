#include "ejercicio_7.c"


int main(void)
{
    int cantingresoP1;
    int cantingresoP2;
    int numero_a_apilar;
    int i=0;

    Pila P1=p_crear();
    Pila P2=p_crear();
    Pila PR=p_crear();

    TipoElemento elemento;

    printf("Ingrese la cantidad de elementos de la 1ra Pila entre 0 y %i",TAMANIO_MAXIMO);
    cantingresoP1 = ingreso_normalizado_enteros(0,10);

    printf("Ingrese la cantidad de elementos de la 2da Pila entre 0 y %i",TAMANIO_MAXIMO);
    cantingresoP2 = ingreso_normalizado_enteros(0,10);

    if (cantingresoP2>0)
    {
    printf("Carga de la 1ra Pila\n");
    }

    for (int i = 0; i < cantingresoP1; i++)
    {
        printf("%iº número",i+1);
        elemento=te_crear(ingreso_normalizado_enteros(-1000,1000));
        p_apilar(P1,elemento);
    }
    if (cantingresoP2>0)
    {
    printf("Carga de la 2da Pila\n");
    }
    
    
    i=0;
    for (int i = 0; i < cantingresoP2; i++)
    {
        printf("%iº número",i+1);
        elemento=te_crear(ingreso_normalizado_enteros(-1000,1000));
        p_apilar(P2,elemento);
    }


    PR = elemEnComun(P1,P2);

    if(p_es_vacia(PR)){
        printf("\nLas pilas no tienen elementos en común");
    }else{
        p_mostrar(PR);
    }
    
    return 0;
}
