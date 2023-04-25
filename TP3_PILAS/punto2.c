#include "punto2.h"
void buscar_clave(Pila pila, int clave);
int main()
{
    char salto;
    unsigned int pos;
    int clave;
    TipoElemento elemento;
    int valores[MAX];
    int *ptr_values = &valores[0];
    bool exit = false;
    Pila pila_1;
    pila_1 = p_crear();
    // carga de elementos
    while(p_es_llena(pila_1) == false && exit == false)
    {
	printf("\n--Ingrese el valor que quiere guardar en la pila o escriba (exit) para salir--\n");
	*(ptr_values)=ingreso_normalizado_enteros(-1000,1000,&exit);
	if(!exit)
	{
	    clave = (random() % 500) + 1;
	    //printf("\nClave: %d", clave);
	    elemento = te_crear_con_valor(clave, ptr_values);
	    p_apilar(pila_1, elemento);
	    ptr_values++;
	}
	
    }

    p_mostrar(pila_1);
    /*printf("\nIngrese la clave que quiere buscar");
    clave = ingreso_normalizado_enteros(-1000, 1000, &exit);
    buscar_clave(pila_1, clave);
    p_mostrar(pila_1);
    */
    
    /*printf("\nIngrese un numero para agregar en la pila:");
    *(ptr_values) = ingreso_normalizado_enteros(-1000, 1000, &exit);
    clave++;
    printf("clave elemento nuevo: %d", clave);
    elemento = te_crear_con_valor(clave, ptr_values);
    ptr_values++;
    printf("\n---[Ingrese posicion ordinal]--- ");
    pos = ingreso_normalizado_enteros(1, 100, &exit);
    p_insertar(pila_1, elemento, pos);
    p_mostrar(pila_1);
    */
    /*printf("\n%s", "INGRESE CLAVE DE ELEMENTO A ELIMINAR\n");
    clave = ingreso_normalizado_enteros(1, 500, &exit);
    p_eliminar_elemento(pila_1, clave);*/
    printf("\n%s", "INGRESE POSICION DE UNO DE LOS ELEMENTOS A INTERCAMBIAR\n");
    unsigned int pos_1 = ingreso_normalizado_enteros(1, pila_1->cantidad, &exit);
    printf("\n%s", "INGRESE POSICION DE UNO DE LOS ELEMENTOS A INTERCAMBIAR\n");
    unsigned int pos_2 = ingreso_normalizado_enteros(1, pila_1->cantidad, &exit);
    intercambiar(pila_1, pos_1, pos_2);
    p_mostrar(pila_1);
    free(pila_1);

}


void buscar_clave(Pila pila, int clave)
{
    // se crea la pila
    Pila pila_aux = p_crear();
    TipoElemento aux;
    // comenzamos desapilando 
    aux = p_desapilar(pila);
    while(aux->clave != clave)
    {
	p_apilar(pila_aux, aux);
	aux = p_desapilar(pila);
    }

    p_apilar(pila, aux);
    p_devolver(pila, pila_aux);
    if(aux->clave == clave)
    {
	printf("\nLa clave %d existe en la pila :^)", aux->clave);
    }
    else
    {
	printf("\nLa clave %d no se encuentra en la pila :(", aux->clave);
    }
}

