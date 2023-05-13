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


    c_mostrar(cola_1);
    printf("\n--Seleccione opcion--\n1-Buscar elemento por clave\n2-Insertar Elemento(cualquiera)\n");
    opcion = ingreso_normalizado_enteros(1, 6, &salida);
    switch(opcion)
    {

    case 1: printf("\nIngrese clave del elemento a buscar\n");
	clave = ingreso_normalizado_enteros(0, 500, &salida);
	c_elemento_existe(cola_1, ingreso_normalizado_enteros(0, 500, &salida));
	break;

    case 2: printf("\nIngrese la posicion en la que quiere insertar el el elemento");
	clave = ingreso_normalizado_enteros(1, 100, &salida);
	elemento = te_crear((random() % 500));
	c_insertar_elemento(cola_1, elemento, clave);
	break;

    default:
	break;
	
    }

    c_mostrar(cola_1);


}
