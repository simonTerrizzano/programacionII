#include "DataEntry_Arboles.h"

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

void Cargar_Arbol(ArbolBinarioBusqueda A, int cant){
    TipoElemento X;
    int n;
    int cont=1;
    bool b=true;
    while(cont<cant){
        b= ingresoEntero(&n);
        if (b){
            X= te_crear(n);
            
            abb_insertar(A,X);
            cont++;
        }
    }    
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