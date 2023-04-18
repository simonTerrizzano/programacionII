#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DataEntry.c"
#include "tipo_elemento.c"


/*
2.Dada una lista cargada con valores al azar (en la clave) realizar los siguientes ejercicios:
a. Que calcule el menor de los datos e indique la posición ordinal.
b. Que calcule el dato máximo y cuente la cantidad de veces que se repite.
c. Que obtenga el promedio de los datos de una lista. El proceso debe ser recursivo.
d. Que retorne otra lista con los números múltiplos de otro número que recibe como
parámetro.
*/
/*
ACLARACIONES:
I) El dato a guardar(número) se reduce a enteros.
II) El rango de valos que puede tomar un entero sera de [-1000, 1000].
 */

// calcular_minimo: Busca entre todos los elementos de la lista el minimo y lo muestra.
void calcular_minimo(Iterador iter);
// cuantes_veces_se_repite: Calcula cuantas veces se repite un valor en una lista.
unsigned int cuantas_veces_se_repite(Iterador iter, int valor);
// mostrar_elementos_lista_recursivamente: #
void mostrar_elementos_lista_recursivamente(Iterador iter);
// promedio_suma_elementos: Retorna lo almacenado en (->almacenamiento_suma) dividido la cantidad de elementos. 
double promedio_suma_elementos(Iterador iter, int *almacenamiento_suma, int cantidad);
// lista_de_multiplos: retorna direccion de la lista de numeros creada que contiene la lista multiplos de un numero(number) de <lista_original>
Lista lista_de_multiplos(Lista lista_original, int number);

int main()
{

    
    int epsilon; // sera donde se guarde el numero que el usuario eliga para buscar los
    //multiplos en la lista 
    int almacenamiento_suma = 0; // se almacena la suma de todos los valores de los nodos
    bool salida = false; // se encarga de detectar que se quiere salir de la carga de
    //numeros
    int datos[TAMANIO_MAXIMO]; // array donde se almacenaran los distintos valores de los
    //nodos
    int *ptr_data; // puntero al array
    ptr_data = &datos[0];
    bool maximo_cargado = false;
    int maximo_valor; // guarda el maximo valor ingresado
    // se comienza creando la lista y el iterador para recorrerla.
    Lista lista_1, lista_multiplos; // lista_1 sera la <<lista original>> y lista_multiplos
    //sera aquella lista que contenga los multiplos de cierto epsilon que se encuentren en
    //la lista original

    lista_1 = l_crear();
    TipoElemento te;
    Iterador iter;
    // se entiende que: Se le pide al usuario una valor, y la clave del nodo que guarda el
    //valor será determinado por un número aleatorio.

    // mientras la lista no este llena o se llame al comando <exit>
    // se agregaran nodos
    printf("\n--Ingreso de numeros--\n\nCosideraciones:\nI) el numero debe serentero\nII)los valores deben ser de [-1000,1000]\nIII)ingrese el comando exit para detener el ingreso de valores.\n");

    while(!(l_es_llena(lista_1)) && salida != true)
    {
	*(ptr_data) = ingreso_normalizado_enteros(-1000, 1000, &salida);
	//printf("\nValor dato: %d\n", dato); 
	if(salida == true)
	{
	    printf("\nEl ingreso de datos se da por finalizado\n");
	}
	else
	{
	    te = te_crear_con_valor(((random()+1)%500), ptr_data);
	    l_agregar(lista_1, te);
	    // si todavia no se ha cargado un primer maximo, entonces carga el primero que
	    //encuentre
	    if(maximo_cargado == false)
	    {
		maximo_valor = *(ptr_data);
		maximo_cargado = true;
	    }
	    else
	    {
		// en cualquier otro caso, calcula si el nuevo dato es un nuevo maximo
		if(*(ptr_data) > maximo_valor)
		{
		    maximo_valor = *(ptr_data);
		}
	    }
	    ptr_data++;
	}
    }

    salida = false;
    // se genera el iterador a la lista.
    iter = iterador(lista_1);
    calcular_minimo(iter); // se calcula el minimo y se muestra
    free(iter);


    
    iter = iterador(lista_1);
    // mostramos cuantas veces se repite un maximo
    printf("\nEl valor máximo es: %d y se repite %d veces\n", maximo_valor,
	   cuantas_veces_se_repite(iter, maximo_valor));
    free(iter);
    iter = iterador(lista_1); // se vuelve a reiniciar el iterador



// se muestra cuantas veces se encuentra el maximo en la lista
    printf("\nLongitud de lista: %d", l_longitud(lista_1));
    printf("\nEl promedio es de %f \n\n", promedio_suma_elementos(iter,&almacenamiento_suma,l_longitud(lista_1)));


    // se pide al usuario un numero para buscar los multiplos en la lista
    printf("\nA partir de la lista anterior y un numero cualquiera se calcularan que elementos son multiplos de ese numero\n\nPorfavor, ingrese un numero: ");
    epsilon = ingreso_normalizado_enteros(-1000, 1000, &salida);
    lista_multiplos = lista_de_multiplos(lista_1,epsilon);
    iter = iterador(lista_multiplos);
    // muestra dichos multiplos
    while(hay_siguiente(iter))
    {
	te = siguiente(iter);
	printf("%d ", *(int*)te->valor);

    }

    // se libera el espacio de memoria
    free(lista_1);
    free(iter);
    free(lista_multiplos);
    return 0;
}

void calcular_minimo(Iterador iter)
{
    //reiniciar_iterador(iter);
    int minimo;
    TipoElemento te;
    int pos = 1;
    te = siguiente(iter);
    minimo = *((int*)(te->valor));
    while(hay_siguiente(iter))
    {
	te = siguiente(iter);
	pos++;
	if((*((int*)te->valor)) < minimo)
	{
	    minimo = *((int*)(te->valor));

	}
    }

    printf("\nEl valor minimo es: %d, en posicion: %d\n", minimo, pos);  
}

unsigned int cuantas_veces_se_repite(Iterador iter, int valor)
{
    unsigned int counter = 0;
    TipoElemento te;
    while(hay_siguiente(iter))
    {
	te = siguiente(iter);
	if(*(int*)te->valor == valor)
	{
	    counter++;
	}
    }

    return counter;
}

Lista lista_de_multiplos(Lista lista, int number)
{
    TipoElemento te;
    Iterador iter;
    Lista lista_multiplos;
    lista_multiplos = l_crear();
    iter = iterador(lista);

    while(hay_siguiente(iter))
    {
	te = siguiente(iter);
	if(((*(int*)te->valor) % number) == 0)
	{
	    l_agregar(lista_multiplos, te);
	}
    }

    return lista_multiplos;
}


//FUNCION DE PRUEBA
void mostrar_elementos_lista_recursivamente(Iterador iter)
{
    TipoElemento te = siguiente(iter);
    if(hay_siguiente(iter)==false)
    {
	printf("\nClave:%d\tDato:%d", te->clave, *(int*)te->valor);
	return;
    }
    else
    {
	printf("\nClave:%d\tDato:%d", te->clave, *(int*)te->valor);
	mostrar_elementos_lista_recursivamente(iter);
    }
}

double promedio_suma_elementos(Iterador iter, int *almacenamiento_suma, int cantidad)
{
    double prom;
    TipoElemento te;
    if(hay_siguiente(iter) == false)
    {
	prom = *(almacenamiento_suma) / cantidad;
	return prom;
    }
    else
    {
	te = siguiente(iter);
	
	*(almacenamiento_suma)+= *(int*)te->valor;
	//printf("\nalmacenamiento_suma = %d", *almacenamiento_suma);
	promedio_suma_elementos(iter, almacenamiento_suma, cantidad);
    }
}
