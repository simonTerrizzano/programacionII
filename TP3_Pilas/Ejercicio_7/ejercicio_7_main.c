#include "ejercicio_7.c"


int main(void)
{
    int eleccion;
    bool salir=false;
    int cantingresoP1=0;
    int cantingresoP2=0;
    int i;

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

    for (i = 0; i < cantingresoP1; i++)
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
    for (i = 0; i < cantingresoP2; i++)
    {
        printf("%iº número",i+1);
        elemento=te_crear(ingreso_normalizado_enteros(-1000,1000));
        p_apilar(P2,elemento);
    }

    p_mostrar(P1);
    p_mostrar(P2);
    printf("\n\n");
     do
    {
        printf( "\n   1. Comparar pilas ingresadas ");
        printf( "\n   2. Salir " );
        printf( "\n\n   Introduzca opcion (1-2): ");

        eleccion=ingreso_normalizado_enteros(1,2);

        /* Inicio del anidamiento */

        switch ( eleccion )
        {
            case 1: PR = elemEnComun(P1,P2);

                    if(p_es_vacia(PR)){
                        printf("\nLas pilas no tienen elementos en común");
                        printf("\n\n");
                    }else{
                        printf("Los elementos que las pilas tienen en común son: ");
                        p_mostrar(PR);
                        printf("\n\n");
                    }
            
                    break;

            case 2: salir=true;
                    
         }

    } while ( salir==false );

    
    return 0;
}
