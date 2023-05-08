#include "ejercicio_6.c"

int main(void)
{
    Pila pila = p_crear();
    Pila pila_elim = p_crear();
    TipoElemento x;
    int eleccion;
    int clave;
    bool salir = false;

    printf("Eliga el modo de carga de la pila: \n 1.Aleatoria \n 2.Por teclado \n");

    eleccion = ingreso_normalizado_enteros(1, 2);

    if (eleccion == 1)
    {
        for (int i = 1; i < 9; i++)
        {
            x = te_crear(i);
            p_apilar(pila, x);
        }
    }
    else
    {
        printf("Ingrese cantidad de elementos para cargar en la pila.\n");
        int cantidad = ingreso_normalizado_enteros(0, 10);

        for (int i = 0; i < cantidad; i++)
        {
            printf("Ingrese clave del %iº elemento a apilar: ", i+1);
            clave = ingreso_normalizado_enteros(-1000, 1000);
            x = te_crear(clave);
            p_apilar(pila, x);
        }
    }

    p_mostrar(pila);
    printf("\n\n");

    do
    {
        printf( "\n   1. Eliminar elementos en todas sus ocurrenciaas de manera recursiva. ");
        printf( "\n   2. Eliminar elementos en todas sus ocurrenciaas de manera iterativa. ");
        printf( "\n   3. Salir " );
        printf( "\n\n   Introduzca opcion (1-3): ");

        eleccion=ingreso_normalizado_enteros(1,3);

        /* Inicio del anidamiento */

        switch ( eleccion )
        {
            case 1: if (p_es_vacia(pila))
                    {
                        printf("--La pila está vacia, no hay elementos que eliminar.--\n\n");
                    }else{
                        printf("Ingrese clave a eliminar todas las ocurrencias: ");
                        clave=ingreso_normalizado_enteros(-1000,1000);
                        pila_elim=p_eliminar_ocurrencias_recursivo(pila,clave);
                        printf("Pila Original:\n");
                        p_mostrar(pila);
                        printf("\nPila con eliminaciones:\n");
                        p_mostrar(pila_elim);
                        printf("\n\n");
                    }
            
                    break;

            case 2: if (p_es_vacia(pila))
                    {
                        printf("--La pila está vacia, no hay elementos que eliminar.--\n\n");
                    }else{
                        printf("Ingrese clave a eliminar todas las ocurrencias: ");
                        clave=ingreso_normalizado_enteros(-1000,1000);
                        pila_elim=p_eliminar_ocurrencias_iter(pila,clave);
                        printf("Pila Original:\n");
                        p_mostrar(pila);
                        printf("\nPila con eliminaciones:\n");
                        p_mostrar(pila_elim);
                        printf("\n\n");
                    }
                    break;

            case 3: salir=true;
                    
         }


         /* Fin del anidamiento */

    } while ( salir==false );


        printf("\n\nDeterminamos que la complejidad algoritmica de este ejercicio tanto en su modalidad retursiva como iterativa es de O(n) siendo n el largo de la pila.")

    return 0;
}
