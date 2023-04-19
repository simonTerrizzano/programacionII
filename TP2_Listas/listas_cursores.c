#include "listas.h"
#define TAMANIO_MAXIMO 100
#define NULO -1 // NULO: nos sirve para indicar el fin del arreglo

// Como se puede observar, en la definicion de nodo no se tendra como siguiente un puntero a otro nodo, si no mas bien un entero.
struct nodo
{
    TipoElemento datos; // el dato que contiene el nodo
    int siguiente; // posicion siguiente 

};

// cursor: se trata de un arreglo de nodos.
struct ListaRep
{
    struct nodo *cursor; // apunta al arreglo de nodos
    int inicio;
    int libre; // contiene el nodo libre
    int cantidad; // mantiene cuenta de cantidad de nodos
};


struct IteradorRep
{
    Lista lista;
    int posicion_actual;

};


Lista l_crear()
{
    Lista nueva_lista = (Lista) malloc(sizeof(struct ListaRep)); 
    nueva_lista->cursor = calloc(TAMANIO_MAXIMO, sizeof(struct nodo)); // se crea el array
    //con los nodos
    nueva_lista->cantidad = 0;
    nueva_lista->inicio = NULO; 
    // Encadeno todos los libres
    for(int i = 0; i < TAMANIO_MAXIMO-2; i++)
    {
	nueva_lista->cursor[i].siguiente = i+1;

    }

    nueva_lista->libre = 0; // comenzamos del 0 al maximo indice del array tomandolos como
    //libres
    nueva_lista->inicio = NULO;
    nueva_lista->cursor[TAMANIO_MAXIMO-1].siguiente = NULO; // indicamos que el ultimo no
    //apunta a ningun lado

    // se retorna la lista creada
    return nueva_lista;
    
}

bool l_es_llena(Lista lista){return (lista->cantidad == TAMANIO_MAXIMO); }
bool l_es_vacia(Lista lista){return (lista->cantidad == 0);}
int l_longitud(Lista lista){return lista->cantidad;}
void l_agregar(Lista lista, TipoElemento elemento)
{
    if(l_es_llena(lista)) {return;} // controlo que la lista no este llena
    int p;
    p = lista->libre; // tomo la posicion del nodo libre
    lista->libre = lista->cursor[p].siguiente; // ahora el libre sera el siguiente
    lista->cursor[p].datos = elemento;
    lista->cursor[p].siguiente = NULO;

    // controlo que no sea el primero de la lista
    if(lista->inicio == NULO)
    {
	lista->inicio = p;
    }
    else
    {
	// lo ubico al final

	// q toma el primer indice la lista
	int q = lista->inicio;
	// recorre hasta encontrar el ultimo
	while(lista->cursor[q].siguiente != NULO)
	{
	    q = lista->cursor[q].siguiente;
	}
	// ahora el que antes era el ultimo apuntara al nuevo nodo y el nuevo nodo sera el
	//ultimo
	lista->cursor[q].siguiente = p;
	
    }

    lista->cantidad++;
}



void l_borrar(Lista lista, int clave)
{
    if(l_es_vacia(lista)) {return;} // controlo lista vacia
    int q, p;
    p = lista->inicio;
    // borro las claves que coinciden con el inicio
    while((p != NULO) && (lista->cursor[p].datos->clave == clave))
    {
	q=p;
	lista->inicio = lista->cursor[p].siguiente;
	// recupero el nodo en el libre para no perderlo
	lista->cursor[q].siguiente = lista->libre;
	lista->libre = q;
	// descuento 1 y arranco de nuevo desde inicio
	lista->cantidad--;
	p = lista->inicio;
	

    }
    // Borro las claves en el resto de la lista
    // nos colocamos en la cabecera con <p>
    p=lista->inicio;
    while((p!=NULO))
    {

	q = lista->cursor[p].siguiente;
	     
	// si encontramos una coincidencia entonces
	if(lista->cursor[q].datos->clave == clave)
	{
	    lista->cursor[p].siguiente = lista->cursor[q].siguiente;
	    lista->cursor[q].siguiente = lista->libre;
	    lista->libre = q;
	    lista->cantidad--;
	}
	else
	{
	    p = lista->cursor[p].siguiente;
              	    
	}
	
    }
}
void l_insertar(Lista lista, TipoElemento elemento, int pos)
{
    if(l_es_llena(lista) == true) {return;}
    int p = lista->libre; // toma la primera posicion libre
    lista->libre = lista->cursor[p].siguiente; // el siguiente sera el nuevo libre
    lista->cursor[p].datos = elemento;
    lista->cursor[p].siguiente = NULO;
    // controlo si cambia el inicio
    if(pos==1)
    {
	lista->cursor[p].siguiente = lista->inicio;
	lista->inicio = p;

    }
    else
    {
	int temp = lista->inicio; // buca la posicion del resto de la lista
	for(int i = 0; i < pos - 2; i++)
	{
	    temp = lista->cursor[temp].siguiente;
	    
	}
	lista->cursor[p].siguiente = lista->cursor[temp].siguiente;
	lista->cursor[temp].siguiente = p;
	
    }

    lista->cantidad++;
}

void l_eliminar(Lista lista, int pos)
{
    int p;
    int actual = lista->inicio;
    if(1<=pos && pos<=l_longitud(lista))
    {
	if(pos==1)
	{
	    p=actual;
	    lista->inicio = lista->cursor[actual].siguiente;
	    lista->cursor[p].siguiente = lista->libre;
	    lista->libre = p;
	}
	else
	{
	    for(int i = 0; i < pos - 2; i++)
	    {
		actual = lista->cursor[actual].siguiente;

	    }
	    p = lista->cursor[actual].siguiente;
	    lista->cursor[actual].siguiente = lista->cursor[p].siguiente; // nodo en pos +
	    //1
	    lista->cursor[lista->libre].siguiente = p;
	    lista->libre = p;
	}
	lista->cantidad--;	
    }
}


TipoElemento l_buscar(Lista lista, int clave)
{
    int p;
    p = lista->inicio;
    while(p!=NULO)
    {
	if(lista->cursor[p].datos->clave == clave)
	{
	    return lista->cursor[p].datos;
	}

	p = lista->cursor[p].siguiente;

    }
    
    return NULL;
}

void l_mostrarLista(Lista lista)
{
    int p = lista->inicio;
    printf("\nContenido de la lista:\n");
    while(p!=NULO)
    {
	printf("%3d / ", lista->cursor[p].datos->clave);
	p = lista->cursor[p].siguiente;
    }

    printf("\n\n");

}

Iterador iterador(Lista lista)
{
    Iterador iter = (Iterador) malloc(sizeof(struct IteradorRep));
    iter->lista = lista;
    iter->posicion_actual = 0;
    return iter;
}

bool hay_siguiente(Iterador iterador)
{
    return((iterador->posicion_actual != NULO));
}

TipoElemento siguiente(Iterador iterador)
{
    TipoElemento actual = iterador->lista->cursor[iterador->posicion_actual].datos;
    iterador->posicion_actual = iterador->lista->cursor[iterador->posicion_actual].siguiente;
    return actual;
}
