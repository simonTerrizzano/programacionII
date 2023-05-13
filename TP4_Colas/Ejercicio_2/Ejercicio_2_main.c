#include "Ejercicio_2.c"

int main(void)
{
    bool * tempb;
    Cola cola = c_crear();
    Randomizar(cola);
    c_mostrar(cola);
    printf("\n");
    printf("La longitud de la cola es de %d",c_longitud(cola));
    printf("\n");
    printf("Ingrese un número a buscar: ");
    TipoElemento X = te_crear(ingreso_normalizado_enteros(-1000,1000));
    printf("\n");
    if (estaEnCola(cola, X))
    {
        printf("Esta en cola");
    }
    else{
        printf("No esta en cola");
    }
    printf("\n");
    c_mostrar(cola);
    printf("\n");
    printf("Ingrese una posición donde insertar el número que buscó anteriormente: ");
    int pos = ingreso_normalizado_enteros(1,TAMANIO_MAXIMO);
    int resultado = colarse(cola,X,pos);
    
    c_mostrar(cola);
    
    system("PAUSE");
    return 0;
}
