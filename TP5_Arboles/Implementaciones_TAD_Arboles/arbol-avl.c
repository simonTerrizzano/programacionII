#include "arbol-avl.h"

static const int TAMANIO_MAXIMO = 100;

NodoArbol avl_rotar_derecha(NodoArbol nodo);

NodoArbol avl_rotar_izquierda(NodoArbol nodo);

int avl_altura_izq(NodoArbol nodo);

int avl_altura_der(NodoArbol nodo);

int avl_max(int a, int b);

enum Balanceo {
    DESBALANCEADO_DERECHA,
    APENAS_DESBALANCEADO_DERECHA,
    BALANCEADO,
    APENAS_DESBALANCEADO_IZQUIERDA,
    DESBALANCEADO_IZQUIERDA
};

ArbolAVL avl_crear() {
    ArbolAVL nuevo_arbol = (ArbolAVL) malloc(sizeof(struct ArbolAVLRep));
    nuevo_arbol->raiz = NULL;
    nuevo_arbol->cantidad_elementos = 0;
    return nuevo_arbol;
}

bool avl_es_vacio(ArbolAVL a) {
    return a->raiz == NULL;
}

bool avl_es_lleno(ArbolAVL a){
    return (a->cantidad_elementos == TAMANIO_MAXIMO);
}

bool avl_es_rama_nula(NodoArbol pa) {
    return pa == NULL;
}

int avl_cantidad_elementos(ArbolAVL a) {
    return a->cantidad_elementos;
}

NodoArbol avl_raiz(ArbolAVL a) {
    return a->raiz;
}

NodoArbol avl_crear_nodo(TipoElemento te) {
    NodoArbol na = (NodoArbol) malloc(sizeof(struct NodoArbolRep));
    na->datos = te;
    na->hi = NULL;
    na->hd = NULL;

    return na;
}

enum Balanceo avl_calcular_balanceo(NodoArbol nodo) {
    int diferenciaAltura = avl_altura_izq(nodo) - avl_altura_der(nodo);
    switch (diferenciaAltura) {
        case -2:
            return DESBALANCEADO_DERECHA;
        case -1:
            return APENAS_DESBALANCEADO_DERECHA;
        case 1:
            return APENAS_DESBALANCEADO_IZQUIERDA;
        case 2:
            return DESBALANCEADO_IZQUIERDA;
        default:
            return BALANCEADO;
    }
}

NodoArbol avl_insertar_recursivo(ArbolAVL a, TipoElemento te, NodoArbol pa) {
    if (pa == NULL) {
        return avl_crear_nodo(te);
    }

    if (te->clave < pa->datos->clave) {
        pa->hi = avl_insertar_recursivo(a, te, pa->hi);
    } else if (te->clave > pa->datos->clave) {
        pa->hd = avl_insertar_recursivo(a, te, pa->hd);
    } else {
        // Es una inserción de un elemento duplicado
        // decrementamos para compensar el incremento
        // hecho anteriormente
        a->cantidad_elementos--;
        return pa;
    }

    pa->FE = avl_max(avl_altura_izq(pa), avl_altura_der(pa)) + 1;
    enum Balanceo balanceState = avl_calcular_balanceo(pa);

    if (balanceState == DESBALANCEADO_IZQUIERDA) {
        if (te->clave < pa->hi->datos->clave) {
            // Caso rotación derecha
            pa = avl_rotar_derecha(pa);
        } else {
            // Caso rotación izquierda-derecha
            pa->hi = avl_rotar_izquierda(pa->hi);
            return avl_rotar_derecha(pa);
        }
    }

    if (balanceState == DESBALANCEADO_DERECHA) {
        if (te->clave > pa->hd->datos->clave) {
            // Caso rotación izquierda
            pa = avl_rotar_izquierda(pa);
        } else {
            // Caso rotación derecha-izquierda
            pa->hd = avl_rotar_derecha(pa->hd);
            return avl_rotar_izquierda(pa);
        }
    }

    return pa;
}

void avl_insertar(ArbolAVL a, TipoElemento te) {
    a->raiz = avl_insertar_recursivo(a, te, avl_raiz(a));
    a->cantidad_elementos++;
}

NodoArbol avl_buscar_minimo(NodoArbol nodoArbol) {
    NodoArbol actual = nodoArbol;

    while (actual && actual->hi != NULL)
        actual = actual->hi;

    return actual;
}

NodoArbol avl_eliminar_recursivo(ArbolAVL arbol, NodoArbol nodoArbol, int claveABorrar) {
    if (nodoArbol == NULL) {
        arbol->cantidad_elementos++; // No lo encontramos, sumamos para compensar
        return nodoArbol;
    }

    if (claveABorrar < nodoArbol->datos->clave)
        nodoArbol->hi = avl_eliminar_recursivo(arbol, nodoArbol->hi, claveABorrar);
    else if (claveABorrar > nodoArbol->datos->clave)
        nodoArbol->hd = avl_eliminar_recursivo(arbol, nodoArbol->hd, claveABorrar);
    else {
        if (nodoArbol->hi == NULL && nodoArbol->hd == NULL) {
//            free(nodoArbol);
            nodoArbol = NULL;
        } else if (nodoArbol->hi == NULL && nodoArbol->hd != NULL) {
            nodoArbol = nodoArbol->hd;
//            NodoArbol temp = nodoArbol->hd;
//            free(nodoArbol);
//            return temp;
        } else if (nodoArbol->hi != NULL && nodoArbol->hd == NULL) {
            nodoArbol = nodoArbol->hi;
//            NodoArbol temp = nodoArbol->hi;
//            free(nodoArbol);
//            return temp;
        } else {
            // El nodo tiene 2 hijos, buscamos el sucesor en in-orden (o sea el menor del subárbol de la derecha)
            NodoArbol temp = avl_buscar_minimo(nodoArbol->hd);
            nodoArbol->datos->clave = temp->datos->clave;
            nodoArbol->datos->valor = temp->datos->valor;
            nodoArbol->hd = avl_eliminar_recursivo(arbol, nodoArbol->hd, temp->datos->clave);
        }
    }

    if (nodoArbol == NULL) {
        return nodoArbol;
    }

    // Actualizar altura y re-balancear el árbol de ser necesario
    nodoArbol->FE = avl_max(avl_altura_izq(nodoArbol), avl_altura_der(nodoArbol)) + 1;
    enum Balanceo balanceState = avl_calcular_balanceo(nodoArbol);

    if (balanceState == DESBALANCEADO_IZQUIERDA) {
        if (avl_calcular_balanceo(nodoArbol->hi) == BALANCEADO ||
                avl_calcular_balanceo(nodoArbol->hi) == APENAS_DESBALANCEADO_IZQUIERDA) {
            return avl_rotar_derecha(nodoArbol);
        }

        // avl_calcular_balanceo(nodoArbol->hi) === Balanceo.APENAS_DESBALANCEADO_DERECHA
        nodoArbol->hi = avl_rotar_izquierda(nodoArbol->hi);
        return avl_rotar_derecha(nodoArbol);
    }

    if (balanceState == DESBALANCEADO_DERECHA) {
        if (avl_calcular_balanceo(nodoArbol->hd) == BALANCEADO ||
                avl_calcular_balanceo(nodoArbol->hd) == APENAS_DESBALANCEADO_DERECHA) {
            return avl_rotar_izquierda(nodoArbol);
        }
        // avl_calcular_balanceo(nodoArbol->hd) === Balanceo.APENAS_DESBALANCEADO_DERECHA
        nodoArbol->hd = avl_rotar_derecha(nodoArbol->hd);
        return avl_rotar_izquierda(nodoArbol);
    }

    return nodoArbol;
}

void avl_eliminar(ArbolAVL a, int claveABorrar) {
    a->raiz = avl_eliminar_recursivo(a, avl_raiz(a), claveABorrar);
    a->cantidad_elementos--;
}

TipoElemento avl_buscar_recursivo(NodoArbol nodoArbol, int clave) {
    if (nodoArbol == NULL)
        return NULL;
    else if (clave < nodoArbol->datos->clave)
        return avl_buscar_recursivo(nodoArbol->hi, clave);
    else if (clave > nodoArbol->datos->clave)
        return avl_buscar_recursivo(nodoArbol->hd, clave);
    else
        return nodoArbol->datos;
}

TipoElemento avl_buscar(ArbolAVL a, int clave) {
    return avl_buscar_recursivo(avl_raiz(a), clave);
}


////////////////////////////////////
///  Funciones para el balanceo  ///
////////////////////////////////////

int avl_altura_izq(NodoArbol nodo) {
    if (nodo->hi == NULL) {
        return -1;
    }
    return nodo->hi->FE;
}

int avl_altura_der(NodoArbol nodo) {
    if (nodo->hd == NULL) {
        return -1;
    }
    return nodo->hd->FE;
}

int avl_max(int a, int b) {
    return a > b ? a : b;
}

/**
 *  * Rotación izquierda
 *   a                                     b
 *  / \                                   / \
 * c   b  -> a.avl_rotar_izquierda() ->  a   e
 *    / \                               / \
 *   d   e                             c   d
 */
NodoArbol avl_rotar_izquierda(NodoArbol nodo) {
    NodoArbol otro = nodo->hd;
    nodo->hd = otro->hi;
    otro->hi = nodo;
    nodo->FE = avl_max(avl_altura_izq(nodo), avl_altura_der(nodo)) + 1;
    otro->FE = avl_max(avl_altura_der(otro), nodo->FE) + 1;

    return otro;
}

/**
 * Rotación derecha
 *     b                                 a
 *    / \                               / \
 *   a   e -> b.avl_rotar_derecha() -> c   b
 *  / \                                   / \
 * c   d                                 d   e
 */
NodoArbol avl_rotar_derecha(NodoArbol nodo) {
    NodoArbol otro = nodo->hi;
    nodo->hi = otro->hd;
    otro->hd = nodo;
    nodo->FE = avl_max(avl_altura_izq(nodo), avl_altura_der(nodo)) + 1;
    otro->FE = avl_max(avl_altura_izq(otro), nodo->FE) + 1;

    return otro;
}
