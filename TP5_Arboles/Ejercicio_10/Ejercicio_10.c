#include "Ejercicio_10.h"

void cargaenbucle(int cant_elem, int max_rango, int rep){
    int cont_rep=0;
    int altura_abb=0;
    int altura_avl=0;
    int cont_lista=0;
    int max_abb=-1;
    int max_avl=-1;
    int min_abb=201;
    int min_avl=201;
    int suma_abb=0;
    int suma_avl=0;
    float promedio_abb;
    float promedio_avl;

    TipoElemento elemento;

    while (cont_rep<rep)
    {
        ArbolBinarioBusqueda a=abb_crear();
        ArbolAVL Aavl=avl_crear();
        Cargar_Arbol(a,cant_elem,max_rango);
        abb_a_avl(abb_raiz(a),&Aavl);
        altint(abb_raiz(a),&altura_abb,0);
        altint(avl_raiz(Aavl),&altura_avl,0);
        printf("\n La altura del Arbol Binario de Búqueda es de %i\n",altura_abb);
        elemento=te_crear(altura_abb);
        max_abb = maximo(max_abb,elemento->clave);
        min_abb = minimo(min_abb,elemento->clave);
        suma_abb = suma_abb + altura_abb;
        elemento=te_crear(altura_avl);
        max_avl = maximo(max_avl,elemento->clave);
        min_avl = minimo(min_avl,elemento->clave);
        suma_avl = suma_avl + altura_avl;
        free(a);
        free(Aavl);
        printf("Altura del Arbol Binario de Búsqueda es %i \n",altura_abb);
        printf("Altura del Arbol Binario de Búsqueda Auto-Balanceado es %i \n",altura_avl);

        cont_rep++;
    }

    promedio_abb=suma_abb/rep;  
    promedio_avl=suma_avl/rep;

    printf("\nAnalisis de los datos del Arbol Binario de Búsqueda\n");
    printf("---------------------------------------------------");

    printf("\nAltura máxima %i \n",max_abb);
    printf("Altura mínima %i \n",min_abb);
    printf("\n Promedio de Alturas %.1f \n\n",promedio_abb);

    printf("Analisis de los datos del Arbol Binario de Búsqueda Auto-Balanceado\n");
    printf("-------------------------------------------------------------------");

    printf("\nAltura máxima %i \n",max_avl);
    printf("Altura mínima %i \n",min_avl);
    printf("\n Promedio de Alturas %.1f \n\n",promedio_avl);

}

