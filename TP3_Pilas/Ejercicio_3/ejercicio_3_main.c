#include "ejercicio_3.c"

int main(void)
{
    Pila pila_1 = p_crear();
    Pila pila_2 = p_crear();
    TipoElemento x;
    int eleccion;
    int clave;

    printf("Eliga el modo de carga para la 1ra pila: \n 1.Aleatoria \n 2.Por teclado \n");

    eleccion = ingreso_normalizado_enteros(1, 2);

    if (eleccion == 1)
    {
        for (int i = 1; i < 9; i++)
        {
            x = te_crear(i);
            p_apilar(pila_1, x);
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
            p_apilar(pila_1, x);
        }
    }
    printf("Eliga el modo de carga para la 2da pila: \n 1.Aleatoria \n 2.Por teclado \n");

    eleccion = ingreso_normalizado_enteros(1, 2);

    if (eleccion == 1)
    {
        for (int i = 1; i < 9; i++)
        {
            x = te_crear(i);
            p_apilar(pila_2, x);
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
            p_apilar(pila_2, x);
        }
    
    }
    if (p_contenidos_iguales(pila_1,pila_2))
    {
        printf("\nLas pilas son iguales.");
    }else{
        printf("\nLas pilas no son iguales.");
    }
    
    return 0;
}
