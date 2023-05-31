#include "funciones_arboles_binarios.c"


Lista recorridoPorAnchuraArbolN(ArbolBinarioBusqueda arbolN);
int nodosHojasArbolN(ArbolBinarioBusqueda arbolN);
int nodosHojasArbolNaux(NodoArbol nodo);
bool arbolesNariosSimilares(ArbolBinarioBusqueda arbol1, ArbolBinarioBusqueda arbol2);
bool arbolesNariosSimilaresaux(NodoArbol nodo1,NodoArbol nodo2);
NodoArbol padreDelNodo(NodoArbol nodo, ArbolBinarioBusqueda arbol);
NodoArbol padreDelNodoAux(NodoArbol nodoActual, NodoArbol nodoHijo);
Lista recorridoPorAnchuraArbolN(ArbolBinarioBusqueda arbolN);
Lista hermanosDelNodo(NodoArbol nodo, ArbolBinarioBusqueda arbol) ;

int nodosHojasArbolN(ArbolBinarioBusqueda arbolN) {
    NodoArbol raiz = abb_raiz(arbolN);
    return nodosHojasArbolNaux(raiz);
}

int nodosHojasArbolNaux(NodoArbol nodo) {
    if (nodo == NULL) {
        return 0;
    }
    if (n_hijoizquierdo(nodo) == NULL && n_hijoderecho(nodo) == NULL) {
        return 1;
    }
    
    int hojas = 0;
    if (n_hijoizquierdo(nodo) != NULL) {
        hojas += nodosHojasArbolNaux(n_hijoizquierdo(nodo));
    }
    if (n_hijoderecho(nodo) != NULL) {
        hojas += 1 + nodosHojasArbolNaux(n_hijoderecho(nodo));
    }
    
    return hojas;
}

Lista recorridoPorAnchuraArbolN(ArbolBinarioBusqueda arbolN) {
    Lista lista = l_crear();
    Lista cola = l_crear();
    NodoArbol raiz = abb_raiz(arbolN);
    
    if (raiz == NULL) {
        return lista;
    }
    
    l_agregar(cola, (TipoElemento)raiz);
    
    while (!l_es_vacia(cola)) {
        NodoArbol nodo = (NodoArbol)l_recuperar(cola, 1);  // Recuperamos el primer elemento de la lista
        l_eliminar(cola, 1);  // Eliminamos el primer elemento de la lista
        
        // Verificar si el nodo ya ha sido visitado
        bool visitado = false;
        for (int i = 1; i <= l_longitud(lista); i++) {
            NodoArbol nodoLista = (NodoArbol)l_recuperar(lista, i);
            if (nodo == nodoLista) {
                visitado = true;
                break;
            }
        }
        
        if (!visitado) {
            l_agregar(lista, (TipoElemento)n_recuperar(nodo));
            
            // Agregar los hijos del nodo actual a la cola
            NodoArbol hijoIzquierdo = (NodoArbol)n_hijoizquierdo(nodo);
            NodoArbol hijoDerecho = (NodoArbol)n_hijoderecho(nodo);
            
            if (hijoIzquierdo != NULL) {
                l_agregar(cola, (TipoElemento)hijoIzquierdo);
            }
            
            if (hijoDerecho != NULL) {
                l_agregar(cola, (TipoElemento)hijoDerecho);
            }
        }
    }
    
    // Liberar memoria de la lista auxiliar
    while (!l_es_vacia(cola)) {
        l_eliminar(cola, 1);
    }
    free(cola);
    
    return lista;
}



bool arbolesNariosSimilares(ArbolBinarioBusqueda arbol1, ArbolBinarioBusqueda arbol2){
    NodoArbol raiz1,raiz2;
    raiz1 = abb_raiz(arbol1);
    raiz2 = abb_raiz(arbol2);
    return arbolesNariosSimilaresaux(raiz1,raiz2);
}

bool arbolesNariosSimilaresaux(NodoArbol nodo1,NodoArbol nodo2){
    if (nodo1 == NULL && nodo2 == NULL) {
        return true;
    } else if (nodo1 == NULL || nodo2 == NULL) {
        return false;
    } else {
        bool izquierdo = arbolesNariosSimilaresaux(n_hijoizquierdo(nodo1), n_hijoizquierdo(nodo2));
        bool derecho = arbolesNariosSimilaresaux(n_hijoderecho(nodo1), n_hijoderecho(nodo2));
        return izquierdo && derecho;
    }
}

NodoArbol padreDelNodo(NodoArbol nodo, ArbolBinarioBusqueda arbol) {
    NodoArbol raiz = abb_raiz(arbol);
    return padreDelNodoAux(raiz, nodo);
}

NodoArbol padreDelNodoAux(NodoArbol nodoActual, NodoArbol nodoHijo) {
    if (nodoActual == NULL || nodoHijo == NULL) {
        return NULL;
    }

    if (n_hijoderecho(nodoActual) == nodoHijo) {
        return nodoActual;
    }

    if (n_hijoizquierdo(nodoActual) == nodoHijo) {
        return nodoActual;
    }

    // Buscar el nodo padre en los hijos izquierdos
    NodoArbol primerHijo = n_hijoderecho(nodoActual);
    while (primerHijo != NULL) {
        NodoArbol padre = padreDelNodoAux(primerHijo, nodoHijo);
        if (padre != NULL) {
            return padre;
        }
        primerHijo = n_hijoizquierdo(primerHijo);
    }

    return NULL;
}

Lista hermanosDelNodo(NodoArbol nodo, ArbolBinarioBusqueda arbol) {
    Lista listaHermanos = l_crear();

    NodoArbol padre = padreDelNodo(nodo, arbol);
    if (padre == NULL) {
        return listaHermanos;
    }

    NodoArbol primerHijo = n_hijoizquierdo(padre);
    while (primerHijo != NULL) {
        if (primerHijo != nodo) {
            l_agregar(listaHermanos, n_recuperar(primerHijo));
        }
        primerHijo = n_hijoderecho(primerHijo);
    }

    return listaHermanos;
}



int main(int argc, char const *argv[])
{
    ArbolBinarioBusqueda arbol, arbol2;
    Lista lista;
    bool *salida;
    printf("Se creará el árbol 1:\n");
    arbol = crearArbol();
    lista = recorridoPorAnchuraArbolN(arbol);
    l_mostrarLista(lista);
    printf("Los nodos hojas del árbol son %d\n", nodosHojasArbolN(arbol));
    TipoElemento elemento = abb_buscar(arbol, ingreso_normalizado_enteros(-1000, 1000, salida));
    NodoArbol nodo = encontrarNodo(arbol, elemento->clave);
    if (nodo != NULL) {
        NodoArbol nodoPadre = padreDelNodo(nodo, arbol);
        if (nodoPadre != NULL) {
            printf("El nodo padre del nodo escrito es: %d\n", n_recuperar(nodoPadre)->clave);
        } else {
            printf("El nodo no tiene padre.\n");
        }
    } else {
        printf("El nodo no fue encontrado en el árbol.\n");
    }
    nodo = encontrarNodo(arbol, elemento->clave);
    if (nodo != NULL) {
        Lista nodosHermanos = hermanosDelNodo(nodo, arbol);
        if (!l_es_vacia(nodosHermanos)) {
            printf("Los nodos hermanos del nodo escrito son : ");
            l_mostrarLista(nodosHermanos);
        } else {
            printf("El nodo no tiene hermanos.\n");
        }
    } else {
        printf("El nodo no fue encontrado en el árbol.\n");
    }
    printf("Se creara el arbol 2 \n");
    arbol2 = crearArbol();
    if (arbolesNariosSimilares(arbol, arbol2))
    {
        printf("los arboles son similares");
    }
    else{
        printf("No son similares");
    }
    system("PAUSE");
    return 0;
}