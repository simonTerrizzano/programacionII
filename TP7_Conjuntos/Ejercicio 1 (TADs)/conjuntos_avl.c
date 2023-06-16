#include <stdlib.h>
#include "conjuntos.h"
#include "arbol_avl.h"
#include "listas.h"



struct ConjuntoRep {
    ArbolAVL arbolAvl;
};

Conjunto cto_crear() {
    Conjunto conjunto = (Conjunto) malloc(sizeof(struct ConjuntoRep));
    conjunto->arbolAvl = avl_crear();
    return conjunto;
}

bool cto_es_vacio(Conjunto conjunto) {
    return avl_es_vacio(conjunto->arbolAvl);
}

bool cto_es_lleno(Conjunto conjunto) {
    return avl_es_lleno(conjunto->arbolAvl);
}

int cto_cantidad_elementos(Conjunto conjunto) {
    return avl_cantidad_elementos(conjunto->arbolAvl);
}

void cto_agregar(Conjunto conjunto, TipoElemento elemento) {
    avl_insertar(conjunto->arbolAvl, elemento);
}

void cto_borrar(Conjunto conjunto, int clave) {
    avl_eliminar(conjunto->arbolAvl, clave);
}

bool cto_pertenece(Conjunto conjunto, int clave) {
    return avl_buscar(conjunto->arbolAvl, clave) != NULL;
}

//-------------------------------------------------------------------------
// Hace la Union recorriendo el AVL del conjunto A primero
//-------------------------------------------------------------------------
void unioninta(NodoArbol q, Conjunto rta) {
    if (!avl_es_rama_nula(q)){
        unioninta(n_hijoizquierdo(q), rta);
        cto_agregar(rta, n_recuperar(q));
        unioninta(n_hijoderecho(q), rta);
    }
}
// por cada elemento de B antes verifica que ya no este en la union
void unionintb(NodoArbol q, Conjunto rta) {
    if (!avl_es_rama_nula(q)){
        unionintb(n_hijoizquierdo(q), rta);
        if (!cto_pertenece(rta, n_recuperar(q)->clave)) { //ACA HUBO MODIFICACION SE AGREGO EL "->CLAVE"
            cto_agregar(rta, n_recuperar(q));
        }
        unionintb(n_hijoderecho(q), rta);
    }
}
// Llama a las 2 rutinas de arriba para armar la union
Conjunto cto_union(Conjunto conjunto_a, Conjunto conjunto_b) {
    Conjunto resultado = cto_crear();

    unioninta(avl_raiz(conjunto_a->arbolAvl),resultado);
    unionintb(avl_raiz(conjunto_b->arbolAvl),resultado);

    return resultado;
}

//-------------------------------------------------------------------------
// recorre un arbol AVL de conjunto y verifica en B si pertenece
//-------------------------------------------------------------------------
void interaconb(NodoArbol q, Conjunto B, Conjunto rta){
    if(!avl_es_rama_nula(q)){
        if(cto_pertenece(B, n_recuperar(q)->clave)){
            cto_agregar(rta, n_recuperar(q));
        }
        interaconb(n_hijoizquierdo(q), B, rta);
        interaconb(n_hijoderecho(q), B, rta);
    }
}

Conjunto cto_interseccion(Conjunto conjunto_a, Conjunto conjunto_b) {
    Conjunto resultado = cto_crear();
    interaconb(avl_raiz(conjunto_a->arbolAvl), conjunto_b, resultado);
    return resultado;
}

//-------------------------------------------------------------------------
// recorre un arbol AVL del conjunto A y verifica en B si pertenece
//-------------------------------------------------------------------------
void difaconb(NodoArbol q, Conjunto B, Conjunto rta){
    if(!avl_es_rama_nula(q)){
        if(!cto_pertenece(B, n_recuperar(q)->clave)){
            cto_agregar(rta, n_recuperar(q));
        }
        difaconb(n_hijoizquierdo(q), B, rta);
        difaconb(n_hijoderecho(q), B, rta);
    }
}

Conjunto cto_diferencia(Conjunto conjunto_a, Conjunto conjunto_b) {
    Conjunto resultado = cto_crear();
    difaconb(avl_raiz(conjunto_a->arbolAvl), conjunto_b, resultado);
    return resultado;
}

//---------------------------------------------------------------------
// Toma el elemento de la i-esima posicion segun el recorrido in-orden
//---------------------------------------------------------------------
void recupera(NodoArbol q, Lista L){
    if(!avl_es_rama_nula(q)){
        recupera(n_hijoizquierdo(q), L);
        l_agregar(L, n_recuperar(q));
        recupera(n_hijoderecho(q), L);
    }
}

TipoElemento cto_recuperar(Conjunto conjunto, int posicion_ordinal) {
    if (cto_cantidad_elementos(conjunto) < posicion_ordinal){
        return NULL;
    }
    // Ahora llamo a la rutina que realmente lo retorna
    Lista L = l_crear();
    recupera(avl_raiz(conjunto->arbolAvl), L);
    return l_recuperar(L, posicion_ordinal);
}

//----------------------------------------------------------
//muestra el arbol AVL que contiene el conjunto en IN-ORDEN
//----------------------------------------------------------
void inorden(NodoArbol q){
    if (!avl_es_rama_nula(q)) {
        inorden(n_hijoizquierdo(q));
        printf(" %d ", n_recuperar(q)->clave);
        inorden(n_hijoderecho(q));
    }
}

void cto_mostrar(Conjunto conjunto) {
    if (cto_es_vacio(conjunto)){
        printf("Conjunto Vacio \n");
        return;
    }
    printf("Conjunto: ");
    inorden(avl_raiz(conjunto->arbolAvl));
    printf("\n");
    return;
}
