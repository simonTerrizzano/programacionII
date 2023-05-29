#include "Ejercicio_10.h"

void cargaenbucle(int cant_elem, int max_rango, int rep){
    int cont_rep=0;
    int altura_abb=0;
    int altura_avl=0;

    Lista LRabb = l_crear();
    Lista LRavl = l_crear();
    TipoElemento elemento;

    while (cont_rep<rep)
    {
        ArbolBinarioBusqueda a=abb_crear();
        ArbolAVL Aavl;
        Cargar_Arbol(a,cant_elem,max_rango);
        abb_a_avl(abb_raiz(a),&Aavl);
        altint(abb_raiz(a),&altura_abb,0);
        altint(avl_raiz(Aavl),&altura_avl,0);
        printf("\n La altura del Arbol Binario de Búqueda es de %i\n",altura_abb);
        elemento=te_crear(altura_abb);
        l_agregar(LRabb,elemento);
        printf("\n La altura del Arbol Binario de Búqueda Auto-Balanciado es de %i\n",altura_avl);
        elemento=te_crear(altura_avl);
        
        l_agregar(LRavl,elemento);
        cont_rep++;
    }

    printf("\nAnalisis de los datos del Arbol Binario de Búsqueda\n");
    printf("---------------------------------------------------");

    analisisDatos(LRabb);

    printf("Analisis de los datos del Arbol Binario de Búsqueda Auto-Balanceado\n");
    printf("-------------------------------------------------------------------");
    analisisDatos(LRavl);
}

void analisisDatos(Lista lista){

    int cont_lista=0;
    int max=-1;
    int min=200;
    int suma=0;
    float promedio;

    TipoElemento elemento;
    

    while (cont_lista<l_longitud(lista))
    {
        cont_lista++;
        elemento = l_recuperar(lista,cont_lista);
        suma = suma + elemento->clave;
        max = maximo(max,elemento->clave);
        min = minimo(min,elemento->clave);
    }

    promedio=suma/l_longitud(lista);   
    
    printf("\nAltura máxima %i \n",max);
    printf("Altura mínima %i \n",min);
    printf("\n Promedio de Alturas %.1f \n\n",promedio);
}
