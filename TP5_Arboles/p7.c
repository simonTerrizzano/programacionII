#include "funciones_arboles_binarios.c"

bool arbolesEquivalentesAux(NodoArbol nodo1, NodoArbol nodo2);
bool arbolesEquivalentes(ArbolBinarioBusqueda arbol1, ArbolBinarioBusqueda arbol2);

bool arbolesEquivalentes(ArbolBinarioBusqueda arbol1, ArbolBinarioBusqueda arbol2){
    NodoArbol raiz1= abb_raiz(arbol1);
    NodoArbol raiz2= abb_raiz(arbol2);
    bool resultado;
    bool condicion=false;
    resultado = arbolesEquivalentesAux(raiz1,raiz2);
    return resultado;
}

bool arbolesEquivalentesAux(NodoArbol nodo1, NodoArbol nodo2) {
    if (nodo1 == NULL && nodo2 == NULL) {
        return true;
    } else if (nodo1 == NULL || nodo2 == NULL) {
        return false;
    } else {
        TipoElemento X, Y;
        X = n_recuperar(nodo1);
        Y = n_recuperar(nodo2);
        if (X->clave != Y->clave) {
            return false;
        }
        bool izquierdo = arbolesEquivalentesAux(n_hijoizquierdo(nodo1), n_hijoizquierdo(nodo2));
        bool derecho = arbolesEquivalentesAux(n_hijoderecho(nodo1), n_hijoderecho(nodo2));
        return izquierdo && derecho;
    }
}

int main(int argc, char const *argv[])
{
    ArbolBinarioBusqueda arbol1, arbol2;
    bool * salida;
    arbol1 = crearArbol();
    pre_orden(abb_raiz(arbol1));
    arbol2 = crearArbol();
    if (arbolesEquivalentes(arbol1,arbol2))
    {
        printf("Son equivalentes");
    }
    else{
        printf("No son equivalentes");
    }
    
    system("PAUSE");
    return 0;
}
