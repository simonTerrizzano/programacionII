#include "punto3.h"
#define MAX 100
int main()
{
    //int opcion;
    //char salto;
    //unsigned int pos;
    int clave;
    TipoElemento elemento;
    int valores[MAX];
    int *ptr_values = &valores[0];
    bool exit = false;
    Pila pila_1;
    Pila p_duplicada;
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
    p_duplicada = p_duplicar(pila_1);
    TipoElemento te_new = te_crear(205);
    p_insertar(p_duplicada, te_new, p_duplicada->cantidad);
    printf("Son iguales? %s", ((p_contenidos_iguales(pila_1, p_duplicada)) ? "si":"no"));
    p_mostrar(pila_1);
    free(pila_1);
    
}
