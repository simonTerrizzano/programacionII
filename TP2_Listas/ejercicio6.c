#include "listas_cursores.c"
#include "tipo_elemento.c"
#include "DataEntry.c"

bool esSubLista(Lista lista1, Lista lista2);
void generarValoresLista(Lista lista, int num);

bool esSubLista(Lista lista1, Lista lista2){
    if (l_es_vacia(lista1)||l_es_vacia(lista2))
    {
        printf("Las listas estan vacias, se cerrara el programa \n");
        system("PAUSE");
    }
    TipoElemento x;
    Iterador iter1,iter2;
    int contador = 0;
    iter1 = iterador(lista1);
    iter2 = iterador(lista2);
    for (int i = 1; i < l_longitud(lista2)+1; i++)
    {
        x = siguiente(iter2);
        if (l_buscar(lista1,x->clave)!=NULL)
        {
            contador = contador + 1;
        }
    }
    printf("\nsiendo x la longitud de la lista 1 y siendo y la longitud de la lista 2... \n");
    printf("La notacion asintotica de la funcion, es de o(x*y)\n");
    if (contador == l_longitud(lista2))
    {
        return true;
    }
    else{
        return false;
    }
}

void generarValoresLista(Lista lista, int num){
    for (int i = 0; i < num; i++)
    {
        unsigned int seed;
        srand(seed);
        TipoElemento x = te_crear(rand()%10);
        l_agregar(lista, x);
    }
    
}

int main(int argc, char const *argv[])
{
    Lista lista1, lista2;
    lista1 = l_crear(lista1);
    lista2 = l_crear(lista2);
    generarValoresLista(lista1,10);
    generarValoresLista(lista2,3);
    l_mostrarLista(lista1);
    l_mostrarLista(lista2);
    if (esSubLista(lista1,lista2))
    {
        printf("\nEs sublista\n");
        system("PAUSE");
    }
    else{
        printf("\nNo es sublista\n");
        system("PAUSE");
    }
    return 0;
}
