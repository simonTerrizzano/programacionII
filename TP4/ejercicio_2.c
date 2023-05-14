#include "ejercicio_2.h"
#include "colas.h"

void c_devolver(Cola c_dest, Cola c_src)
{
    TipoElemento elemento_aux;
    while(c_es_vacia(c_src) == false)
    {
	elemento_aux = c_desencolar(c_src);
	c_encolar(c_dest, elemento_aux);
    }

}

bool c_elemento_existe(Cola cola, int clave)
{
    bool encontrado = false;
    TipoElemento elemento_auxiliar;
    Cola cola_auxiliar = c_crear();
    while(c_es_vacia(cola) == false)
    {
	elemento_auxiliar = c_desencolar(cola);
	c_encolar(cola_auxiliar, elemento_auxiliar);
	if(elemento_auxiliar->clave == clave)
	{
	    encontrado = true;
	}
    }

    while(c_es_vacia(cola_auxiliar) == false)
    {
	elemento_auxiliar = c_desencolar(cola_auxiliar);
	c_encolar(cola, elemento_auxiliar);
    }


    if(encontrado)
	printf("\nEl elemento de clave %d se encuentra en la lista ;)\n", clave);
    else
    {
	printf("\nNo se encuentra el elemento de clave %d :(\n", clave);
    }

    return encontrado;

}

void c_insertar_elemento(Cola cola, TipoElemento elemento_nuevo,  int pos)
{
    
    int contador = 0;
    TipoElemento elemento_auxiliar;
    Cola cola_auxiliar = c_crear();
    bool posicion_es_valida = true;
    if(pos < 1)
    {
	posicion_es_valida = false;
    }

    // si la posicion es mayor que la posicion del ultimo elemento entonces sencillamente se lo pone como ultimo
    if(pos > longitud(cola))
	c_encolar(cola, elemento_nuevo);
    // si la posicion que se ingreso es valida
    else if(posicion_es_valida)
    {
	// mientras la pila contenga elementos
	while(c_es_vacia(cola) == false)
	{
	    contador++;
	    if(contador == pos)
	    {
		c_encolar(cola_auxiliar, elemento_nuevo);
	    }
	    else
	    {
		elemento_auxiliar = c_desencolar(cola);
		c_encolar(cola_auxiliar, elemento_auxiliar);
	    }	    

	}

	c_devolver(cola, cola_auxiliar);
       
    }
    else
    {
	printf("\nLa posicion ingresada es invalida");
    }

}


void c_eliminar_elemento(Cola cola, int clave)
{
    Cola c_auxiliar = c_crear();
    TipoElemento elemento_auxiliar;
    bool existe_la_clave = c_elemento_existe(cola, clave);
    if(existe_la_clave)
    {
	while(c_es_vacia(cola) == false)
	{
	    elemento_auxiliar = c_desencolar(cola);
	    if(elemento_auxiliar->clave != clave)
	    {
		c_encolar(c_auxiliar, elemento_auxiliar);
	    }
	    
	}

	c_devolver(cola, c_auxiliar);
    }
    else
    {

	printf("\nError. No existe elemento con dicha clave");
    }

}

Cola c_copiar_cola(Cola C)
{
    Cola temp = c_crear();
    Cola CCopia = c_crear();
    TipoElemento X;
    while (!c_es_vacia(C))
    {
        X = c_desencolar(C);
        c_encolar(temp,X);
    }
    while (!c_es_vacia(temp))
    {
        X = c_desencolar(temp);
        c_encolar(CCopia,X);
        c_encolar(C,X);
    }
    return CCopia;
}

int c_contar_elementos(Cola C){
    return longitud(C);
}

Cola c_cola_invertida(Cola cola)
{
    Cola cola_duplicada = c_copiar_cola(cola);
    Cola cola_aux = c_crear();
    TipoElemento elemento;
    while(c_es_vacia(cola_duplicada) == false)
    {
	elemento = c_desencolar(cola_duplicada);
	c_insertar_elemento(cola_aux, elemento, 1);
    }
   
    return cola_aux;

}
