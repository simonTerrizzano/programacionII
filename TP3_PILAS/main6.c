#include "punto6.c"
#include "ejercicio_2.c"
int main()
{

    TipoElemento el_aux;
    Pila p_modf;
    int seleccion;
    Pila p_auxiliar = p_crear();
    bool salida = false;
    Pila pila_1 = p_crear();
    p_cargar_sin_valores(pila_1);
    printf("\nClaves que contiene la pila: ");
    p_mostrar(pila_1);
    printf("\nEliminacion de manera: \n1- recursiva\n 2- iterativa?\n");
    seleccion = ingreso_normalizado_enteros(1, 2, &salida);
    if(seleccion == 1)
    {
	printf("\nIngrese el numero de clave a eliminar: ");
	 p_modf = p_eliminar_ocurrencias_recursivo(pila_1, ingreso_normalizado_enteros(0, 500, &salida));
    }
    else
    {
	printf("\nIngrese el numero de clave a eliminar: ");
	p_modf = p_eliminar_ocurrencias_iter(pila_1, ingreso_normalizado_enteros(0, 500, &salida));

    }
    
    
    while(p_es_vacia(p_modf) == false)
    {
	el_aux = p_desapilar(p_modf);
	p_apilar(p_auxiliar, el_aux);
    }
    p_mostrar(p_auxiliar);
    printf("\n\n\n");
    p_mostrar(pila_1);
    free(p_modf);
}
