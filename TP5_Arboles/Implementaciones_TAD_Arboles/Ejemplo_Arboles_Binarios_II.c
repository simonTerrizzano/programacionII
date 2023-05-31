#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arbol-binario.h"
#include "tipo_elemento.h"

void pre_orden(NodoArbol N);
void in_orden(NodoArbol N);
void post_orden(NodoArbol N);
void cargar_arbol_binario(ArbolBinario A);
int nivel_nodo(ArbolBinario A, int N);

//Muestra el arbol a partir de un nodo (de ahi hacia abajo)
void pre_orden(NodoArbol N){
    TipoElemento x;
    if (N == NULL) {
        printf(".");
    }
    else {
        x = n_recuperar(N);
        printf(" %d", x->clave);
        //x->clave= x->clave * 2;//borrar
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

/*Función que solicita el ingreso de un número entero o de "." como representación de nulo. La misma 
devuelve verdadero en el primer caso y falso en el segundo.*/
bool ingresoEntero(int* n){
    char s[10];
    bool resultado = true;
    *n=0;
    printf("Ingrese una clave numérica o '.' para nulo: ");
    scanf("%s", s);
    if (s[0]=='.'){
        resultado = false;
    }else{
        for (int i = 0; s[i] != '\0'; i++) {
            if ((s[i]>='0')&&(s[i]<='9')){
                *n = *n * 10 + (s[i] - 48);}
        }
    }
    return resultado;
}

/*Función que carga un (sub)árbol en preorden a partir del nodo padre N recursivamente.
El entero sa indica cómo se enlazará el nuevo valor:
0: El nuevo nodo (con su TE) se asignará a la raíz de A. En este caso N no es utilizado.
-1: El nuevo nodo (con su TE) se enlazará como hijo izquierdo de N.
1: El nuevo nodo (con su TE) se enlazará como hijo derecho de N.*/
void Cargar_SubArbol(ArbolBinario A, NodoArbol N, int sa){
    TipoElemento X;
    NodoArbol N1;
    int n;
    bool b;
    if(!a_es_lleno(A)){
        b= ingresoEntero(&n);
        if (b){
            X= te_crear(n);
            
            if(sa == -1) N1 = a_conectar_hi(A, N, X);
            else if(sa == 1) N1 = a_conectar_hd(A, N, X);
            else N1 = a_establecer_raiz(A, X);

            Cargar_SubArbol(A, N1, -1);
            Cargar_SubArbol(A, N1, 1);
        }
    }    
}

/*Función que recibe el árbol a ser cargado y llama a la función recursiva que realiza
la carga nodo por nodo*/
void cargar_arbol_binario(ArbolBinario A){
    Cargar_SubArbol(A, NULL, 0);
}

/*Función recursiva que recibe un NodoArbol (inicialmente la raíz), la clave buscada,
 un apuntador a entero para poder devolver el nivel de la clave (si la encuentra) y 
 el nivel del NodoArbol Q*/
void nivelint(NodoArbol Q, int Cbuscada, int *h, int c){
    TipoElemento X;
    if (Q != NULL) {
        X= n_recuperar(Q);
        if (X->clave == Cbuscada) {
            *h = c;
        }else{
            nivelint(n_hijoizquierdo(Q), Cbuscada, h, c+1);
            nivelint(n_hijoderecho(Q), Cbuscada, h, c+1);
        }
    }
}


// Funcion que devuelve el nivel de una clave o -1 si esta no se encuentra en el árbol.
// Llama a la función recursiva que busca la clave y proporciona su nivel.
int nivel_nodo(ArbolBinario A, int N){
    int nivel = -1;
    nivelint(a_raiz(A), N, &nivel, 0);
    return nivel;
}

int main() {
    int n, nivel; 
    ArbolBinario A1;
    A1= a_crear();
    cargar_arbol_binario(A1);

        // LLamo al mostrar arbol
    printf("-----------------------------------------------------\n");
    printf("Pre-Orden Desde la raiz\n");
    pre_orden(a_raiz(A1));
    printf("\n");
    printf("-----------------------------------------------------\n");
    printf("In-Orden Desde la raiz\n");
    in_orden(a_raiz(A1));
    printf("\n");
    printf("-----------------------------------------------------\n");
    printf("Post-Orden Desde la raiz\n");
    post_orden(a_raiz(A1));
    printf("\n");

    printf("Ingrese una clave para obtener a que nivel del arbol se encuentra: ");
    scanf("%d", &n);
    nivel = nivel_nodo(A1, n);
    if(nivel == -1) printf("La clave no se encuentra en el arbol.\n");
    else printf("La clave %d se encuentra en el nivel %d del arbol.\n", n, nivel);
}