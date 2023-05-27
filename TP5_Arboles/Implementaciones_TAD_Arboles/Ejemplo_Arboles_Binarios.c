#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <D:\Mario\Prog_2_2009\2023\TADs\Arboles\Arbolesbinarios\arbol-binario.h>
#include <D:\Mario\Prog_2_2009\2023\TADs\Tipos\tipo_elemento.h>

int altura(ArbolBinario A);
void hojas(ArbolBinario A);


int main()
{
    ArbolBinario a;
    TipoElemento x;
    NodoArbol N;

    printf("Creando el Arbol Binario Vacio (Tamaño = 10) !\n");
    a = a_crear();

    if (a_es_vacio(a)) {
        printf("El arbol esta vacio !\n");
    }

    // Creo el arbol vacio
    a = a_crear();

    // Inserto la Raiz
    x = te_crear(5);
    a_establecer_raiz(a, x);
    printf("Cantidad de Nodos: %d \n", a_cantidad_elementos(a));

    // Inserto uno por izquierda
    x = te_crear(3);
    a_conectar_hi(a, a_raiz(a), x);
    printf("Cantidad de Nodos: %d \n", a_cantidad_elementos(a));

    // Inserto uno por derecha
    x = te_crear(8);
    N = a_conectar_hd(a, a_raiz(a), x);
    printf("Cantidad de Nodos: %d \n", a_cantidad_elementos(a));

    // Inserto uno por derecha
    x = te_crear(10);
    N = a_conectar_hd(a, N, x);
    printf("Cantidad de Nodos: %d \n", a_cantidad_elementos(a));

    // Inserto uno por derecha
    x = te_crear(15);
    a_conectar_hd(a, N, x);
    printf("Cantidad de Nodos: %d \n", a_cantidad_elementos(a));

    // Inserto uno por derecha
    x = te_crear(13);
    N = a_conectar_hi(a, N, x);
    printf("Cantidad de Nodos: %d \n", a_cantidad_elementos(a));

    // Inserto uno por derecha
    x = te_crear(14);
    a_conectar_hi(a, NULL, x);
    printf("Cantidad de Nodos: %d \n", a_cantidad_elementos(a));

    // LLamo al mostrar arbol
    printf("-----------------------------------------------------\n");
    printf("Pre-Orden Desde la raiz\n");
    pre_orden(a_raiz(a));
    printf("\n");
    printf("-----------------------------------------------------\n");
    printf("In-Orden Desde la raiz\n");
    in_orden(a_raiz(a));
    printf("\n");
    printf("-----------------------------------------------------\n");
    printf("Post-Orden Desde la raiz\n");
    post_orden(a_raiz(a));
    printf("\n");

    printf("-----------------------------------------------------\n");
    printf("Altura del Arbol: %d \n", altura(a));
    printf("-----------------------------------------------------\n");

    hojas(a);

}

//Muestra el arbol a partir de un nodo (de ahi hacia abajo)
void pre_orden(NodoArbol N){
    TipoElemento x;
    if (N == NULL) {
        printf(".");
    }
    else {
        x = n_recuperar(N);
        printf(" %d", x->clave);
        pre_orden(n_hijoizquierdo(N));
        pre_orden(n_hijoderecho(N));
    }
}

//Muestra el arbol a partir de un nodo (de ahi hacia abajo)
void in_orden(NodoArbol N){
    TipoElemento x;
    if (N == NULL) {
        printf(".");
    }
    else {
        in_orden(n_hijoizquierdo(N));
        x = n_recuperar(N);
        printf(" %d", x->clave);
        in_orden(n_hijoderecho(N));
    }
}

//Muestra el arbol a partir de un nodo (de ahi hacia abajo)
void post_orden(NodoArbol N){
    TipoElemento x;
    if (N == NULL) {
        printf(".");
    }
    else {
        post_orden(n_hijoizquierdo(N));
        post_orden(n_hijoderecho(N));
        x = n_recuperar(N);
        printf(" %d", x->clave);
    }
}

//---------------------------------------------------------
//Calcula la Altura del Arbol
//---------------------------------------------------------
// Funcion que realmente calcula la altura
void altint(NodoArbol Q, int *h, int c){
    if (Q == NULL) {
        if (c > *h) {
            *h = c;
        }
    }
    else {
        altint(n_hijoizquierdo(Q), h, c++);
        altint(n_hijoderecho(Q), h, c++);
    }
}
// funcion que llama a la que calcula la altura
int altura(ArbolBinario A){
    int alt = 0;
    altint(a_raiz(A), &alt, 0);
    return alt;
}

// imprime las hojas
void hojasint(NodoArbol Q){
    TipoElemento x;

    if (Q == NULL) {
    }
    else {
        // averigua si es un hoja
        if ((n_hijoizquierdo(Q) == NULL) && (n_hijoderecho(Q) == NULL)) {
            x = n_recuperar(Q);
            printf("Hoja: %d \n",  x->clave);
        }
        // Llamo para el recorrido
        hojasint(n_hijoizquierdo(Q));
        hojasint(n_hijoderecho(Q));
    }
}
void hojas(ArbolBinario A){
    hojasint(a_raiz(A));
};


