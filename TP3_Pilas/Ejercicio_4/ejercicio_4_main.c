#include "ejercicio_4.c"

int main(void)
{
    int n_a_convertir;
    int b_a_convertir;
    bool salir=false;
    int eleccion;

    do
    {
        printf( "\n   1. Convertir un número x a una base entre 2 y 16. ");
        printf( "\n   2. Salir " );
        printf( "\n\n   Introduzca opcion (1-2): ");

        eleccion=ingreso_normalizado_enteros(1,2);
        switch (eleccion)
        {
        case 1: printf("Ingrese número a convertir: ");
                n_a_convertir=ingreso_normalizado_enteros(-1000,1000);
                printf("Ingrese base a la que quiere convertir el número: ");
                b_a_convertir=ingreso_normalizado_enteros(2,16);

                p_numero_a_base(n_a_convertir,b_a_convertir);
                printf("\n\n")
            break;
        case 2: salir=true;
        
        }
    } while (salir==false);
    



    return 0;
}
