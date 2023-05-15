#include "ejercicio_3.c"

int main(void)
{
    
    Cola C1=c_crear();
    Cola C2=c_crear();

    TipoElemento x;

    int cantidad;
    int i;
    int eleccion;
    int clave;
    bool res;

    printf("Eliga el modo de carga de las cola: \n 1.Aleatoria \n 2.Por teclado \n");

    eleccion = ingreso_normalizado_enteros(1, 2);

    if (eleccion == 1)
    {
        srand(time(0));
        for (int i = 1; i <= TAMANIO_MAXIMO_COLAS/2; i++)
        {
            x = te_crear(rand()%100);
            c_encolar(C1,x);
            x = te_crear(rand()%100);
            c_encolar(C2,x);
        }
    }
    else
    {
        printf("Ingrese cantidad de elementos para cargar en la 1ra cola.\n");
        cantidad = ingreso_normalizado_enteros(0,   TAMANIO_MAXIMO_COLAS/2);

        for (i = 0; i < cantidad; i++)
        {
            printf("Ingrese clave del %iº elemento a apilar: ", i+1);
            clave = ingreso_normalizado_enteros(-1000, 1000);
            x = te_crear(clave);
            c_encolar(C1, x);
        }
        printf("Ingrese cantidad de elementos para cargar en la 2da cola.\n");
        cantidad = ingreso_normalizado_enteros(0,   TAMANIO_MAXIMO_COLAS/2);

        for (i = 0; i < cantidad; i++)
        {
            printf("Ingrese clave del %iº elemento a apilar: ", i+1);
            clave = ingreso_normalizado_enteros(-1000, 1000);
            x = te_crear(clave);
            c_encolar(C2, x);
        }
    }

    printf("1ra Cola\n");
    c_mostrar(C1);
    printf("2da Cola\n");
    c_mostrar(C2);

    res = compararIgualdadCola(C1,C2);

    if (res)
    {
        printf("Las colas son iguales.\n");
    }else{
        printf("Las colas no son iguales.\n");
    }

    printf("1ra Cola\n");
    c_mostrar(C1);
    printf("2da Cola\n");
    c_mostrar(C2);
    


    return 0;
}
