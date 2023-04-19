#include "listas_cursores.c"
#include "tipo_elemento.c"
#include "DataEntry.c"

void compararListas(Lista lista1, Lista lista2);
void ingresarValoresLista(Lista lista);
void generarValoresLista(Lista lista, int num);

void compararListas(Lista lista1, Lista lista2){
    if (l_es_vacia(lista1)||l_es_vacia(lista2))
    {
        printf("almenos una de las listas estan vacias, se cerrara el programa \n");
        system("PAUSE");
    }
    
    int clavesM1 = 0, clavesM2 = 0, contador1 = 0, contador2 = 0;
    bool end1 = false,end2 = false;
    Iterador it1 = iterador(lista1), it2;
    TipoElemento x, y;
    for (int i = 0; i < l_longitud(lista1); i++)
    {
        x = siguiente(it1);
        it2 = iterador(lista2);
        for (int j = 0; j < l_longitud(lista2); j++)
        {
            y = siguiente(it2);
            if (x->clave>y->clave)
            {
                clavesM1=clavesM1+1;
            }
            else if (x->clave<y->clave)
            {
                clavesM2=clavesM2+1;
            }
        }
    }
    
    printf("\n");
    if (clavesM1>clavesM2)
    {
        printf("La lista 1 es mayor que la lista 2, teniendo la lista 1 %d claves mayores y la lista 2 %d claves mayores",clavesM1,clavesM2);
    }
    else if (clavesM1<clavesM2)
    {
        printf("La lista 1 es menor que la lista 2, teniendo la lista 1 %d claves mayores y la lista 2 %d claves mayores",clavesM1,clavesM2);
    }
    else{
        printf("La lista 1 es de igual tamanio que la lista 2, teniendo la lista 1 %d claves mayores y la lista 2 %d claves mayores",clavesM1,clavesM2);
    }
    printf("\nsiendo x la longitud de la lista 1 y siendo y la longitud de la lista 2... \n");
    printf("La notacion asintotica de la funcion, sin contar las funciones que se llaman del tad, es de  o(y*x)\n");
    return;
}

void generarValoresLista(Lista lista, int num){
    for (int i = 0; i < num; i++)
    {
        TipoElemento x = te_crear(rand()%100);
        l_agregar(lista, x);
    }
    
}

int main(int argc, char const *argv[])
{
    Lista lista1,lista2;
    lista1 = l_crear();
    lista2 = l_crear();
    generarValoresLista(lista1,10);
    generarValoresLista(lista2,10);
    l_mostrarLista(lista1);
    l_mostrarLista(lista2);
    compararListas(lista1,lista2);
    system("PAUSE");
    return 0;
}

