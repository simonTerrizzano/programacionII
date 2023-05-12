#include "ejercicio_2.h"
#include "colas.h"
#include "DataEntry.h"
#include "ejercicio_2.c"
int main()
{
    bool salida = false;
    int clave;
    int opcion;
    bool clave_aleatoria =  ingreso_clave_aleatoria();
    Cola cola_1 = c_crear();
    TipoElemento elemento;
    comienza_ingreso();
    if(clave_aleatoria == true)
    {
	while(c_es_llena(cola_1) == false && !salida)
	{
	    printf("\nAñadir nuevo elemento\n1-si\n2-salir");
	    opcion = ingreso_normalizado_enteros(1, 2, &salida);
	    if(opcion == 1)
	    {
		clave = random() % 500;
		elemento = te_crear(clave);
		c_encolar(cola_1, elemento);
		printf("\nNuevo elemento añadido. Clave: %d\n", clave);
	    }
	    else
	    {
		salida = true;
	    }
	}
    }
    else
    {
	while(c_es_llena(cola_1) == false && !salida)
	{
	    printf("\nAñadir nuevo elemento\n1-si\n2-salir");
	    opcion = ingreso_normalizado_enteros(1, 2, &salida);
	    if(opcion == 1)
	    {
		clave = ingreso_normalizado_enteros(0, 500, &salida);
		elemento = te_crear(clave);
		c_encolar(cola_1, elemento);
		printf("\nNuevo elemento añadido. Clave: %d\n", clave);
	    }
	    else
	    {
		salida = true;
	    }
	}
    }
    printf("\nIngrese la clave del elemento a buscar para corroborar si existe\n");

    c_mostrar(cola_1);

    c_elemento_existe(cola_1, ingreso_normalizado_enteros(0, 500, &salida));

    c_mostrar(cola_1);


}
