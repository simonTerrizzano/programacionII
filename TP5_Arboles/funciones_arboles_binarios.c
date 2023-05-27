#include "arbol_binario_busqueda.c"
#include "nodo.c"
#include "listas_apuntadores.c"
#include "DataEntry.c"

void pre_orden(NodoArbol N);
void in_orden(NodoArbol N);
void post_orden(NodoArbol N);

ArbolBinarioBusqueda crearArbol();

ArbolBinarioBusqueda crearArbol(){
    bool fin = false;bool * correcto;
    TipoElemento X;
    ArbolBinarioBusqueda arbol = abb_crear();
    int temp, contadoralt = 1, contadornodo;
    while (!fin)
    {
        printf("Ingrese 1 para finalizar:\n");
        if (ingreso_normalizado_enteros(0,1,correcto)==1)
        {
            fin = true;
        }
        else{
            printf("Ingrese valor del nodo\n");
            temp = ingreso_normalizado_enteros(-1000, 1000, correcto);
            X = te_crear(temp);
            abb_insertar(arbol,X);
        }
    }
    return arbol;
}


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
