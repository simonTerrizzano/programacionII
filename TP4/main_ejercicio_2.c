#include "ejercicio_2.h"
#include "colas.h"
#include "DataEntry_alt.h"
#include "ejercicio_2.c"
int main()
{
    bool salida = false;
    int clave;
    int opcion;
    bool clave_aleatoria =  ingreso_clave_aleatoria();
    Cola cola_1 = c_crear();
    Cola cola_invertida;
    Cola cola_copiada;
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

    salida = false;
    c_mostrar(cola_1);

    while(!salida)
    {
	    printf("\n--Seleccione opcion--\n1-Buscar elemento por clave\n2-Insertar Elemento(cualquiera)\n3-invertir cola\n4-copiar cola\n5-Eliminar elemento\n6-Contar elementos\n7-salir");
	opcion = ingreso_normalizado_enteros(1, 7, &salida);
	switch(opcion)
	{

	case 1: printf("\nIngrese clave del elemento a buscar\n");
	    clave = ingreso_normalizado_enteros(0, 500, &salida);
	    c_elemento_existe(cola_1, ingreso_normalizado_enteros(0, 500, &salida));
	    break;

	case 2: printf("\nIngrese la posicion en la que quiere insertar el el elemento");
	    clave = ingreso_normalizado_enteros(1, 100, &salida);
	    elemento = te_crear((random() % 500));
	    printf("\nSe insertara un nuevo elemento de clave %d.Presione una tecla para continuar\n", elemento->clave);
	    getchar();
	    c_insertar_elemento(cola_1, elemento, clave);
	    break;

	case 3: printf("\n--Cola invertida--\n");
	    cola_invertida = c_cola_invertida(cola_1);
	    c_mostrar(cola_invertida);
	    break;
	    
	case 4: printf("\n--Copiar cola--\n");
	    cola_copiada = c_copiar_cola(cola_1);
	    printf("\nCola copiada: \n");
	    c_mostrar(cola_copiada);
	    break;
	    
	case 5: printf("\n--Eliga elemento a eliminar(por clave)--\n");
	    c_eliminar_elemento(cola_1, clave);
	 break;

	case 6: printf("\n--Contar elementos--\n");
	    printf("\nLa cantidad de elementos son: %d", c_contar_elementos(cola_1));
	    break;
	case 7: printf("\nNOS VEMO");
	default: salida = true;
	    break;
	
	}

	c_mostrar(cola_1);
    }

}
