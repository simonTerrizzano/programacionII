#include "Ejercicio_4.c"

int main(void)
{
    Cola cola = c_crear();
    Cola CR = c_crear();
    TipoElemento x;
    int eleccion;
    int cantidad;
    int clave;
    bool salir = false;

    printf("Eliga el modo de carga de la cola: \n 1.Aleatoria \n 2.Por teclado \n");

    eleccion = ingreso_normalizado_enteros(1, 2);

    if (eleccion == 1)
    {
        srand(time(0));
        for (int i = 1; i < 9; i++)
        {
            x = te_crear(rand()%100);
            c_encolar(cola,x);
        }
    }
    else
    {
        printf("Ingrese cantidad de elementos para cargar en la cola.\n");
        cantidad = ingreso_normalizado_enteros(0,   TAMANIO_MAXIMO);

        for (int i = 0; i < cantidad; i++)
        {
            printf("Ingrese clave del %iº elemento a apilar: ", i+1);
            clave = ingreso_normalizado_enteros(-1000, 1000);
            x = te_crear(clave);
            c_encolar(cola, x);
        }
    }

    printf("La cola ingresada es: ");
    c_mostrar(cola);
    printf("\n\n");

    do
    {
        printf( "\n   1. Pasar a otra cola los elementos no repetidos. ");
        printf( "\n   2. Salir " );
        printf( "\n\n   Introduzca opcion (1-2): ");

        eleccion=ingreso_normalizado_enteros(1,2);

        /* Inicio del anidamiento */

        switch ( eleccion )
        {
            case 1: if (c_es_vacia(cola))
                    {
                        printf("--La cola está vacia, no hay elementos que pasar.--\n\n");
                    }else{
                        printf("Cola Original:\n");
                        c_mostrar(cola);
                        printf("\nCola con elementos no repetidos:\n");
                        CR=c_noRepetidos(cola);
                        c_mostrar(CR);
                        printf("\n\n");
                    }
            
                    break;

            case 2: salir=true;
                    
         }


         /* Fin del anidamiento */

    } while ( salir==false );


        printf("\n\n");

    return 0;
}
