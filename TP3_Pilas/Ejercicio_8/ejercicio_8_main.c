#include "Ejercicio_8.c"

int main(void)
{
    int cantingresoP1=0;
    int i;

    Pila P1=p_crear();

    Pila PR=p_crear();

    TipoElemento elemento;

    printf("Ingrese la cantidad de elementos de la Pila entre 0 y %i",TAMANIO_MAXIMO);
    cantingresoP1 = ingreso_normalizado_enteros(0,10);


    if (cantingresoP1>0)
    {
    printf("Carga de la 1ra Pila\n");
    }

    for (i = 0; i < cantingresoP1; i++)
    {
        printf("%iº número",i+1);
        elemento=te_crear(ingreso_normalizado_enteros(-1000,1000));
        p_apilar(P1,elemento);
    }


    PR = elementosRepetidos(P1);

    if (p_es_vacia(PR)!=true)
    {
        
    
        Pila pilaAUX;
        pilaAUX = p_crear();
        TipoElemento elemento_a_mostrar;

        printf("Contanido de la pila: \n");
        printf("PR = ( ");
        while (p_es_vacia(PR)!=true)
        {
            elemento_a_mostrar=p_desapilar(PR);
            printf("[%d:%d] ",elemento_a_mostrar->clave,*((int*)elemento_a_mostrar->valor));
            p_apilar(pilaAUX, elemento_a_mostrar);
        }
        printf(")");

        while (p_es_vacia(pilaAUX)!=true)
        {
            elemento_a_mostrar=p_desapilar(pilaAUX);
            p_apilar(PR,elemento_a_mostrar);
        }
    }else
    {
        printf("\nLa pila está vacia, no hay elementos repetidos que mostrar");
    }
    
    

    return 0;
}
