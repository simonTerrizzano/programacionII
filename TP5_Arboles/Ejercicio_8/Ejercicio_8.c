#include "funciones_arboles_binarios.c"

bool hojasAlmismoNivelAux(NodoArbol nodo, int nivel_actual, int *nivel_hojas);
int alturaArbolN(ArbolBinarioBusqueda arbol);
void alturaArbolNaux(NodoArbol nodo, int *altura, int contador);
int nivelNodo(ArbolBinarioBusqueda arbol, NodoArbol nodoObj);
void nivelNodoAux(NodoArbol nodo, NodoArbol nodoObj, int *nivel);
Lista nodosInternosN(ArbolBinarioBusqueda arbol);
void nodosInternosNaux(NodoArbol nodo, Lista lista);
bool hojasAlmismoNivel(ArbolBinarioBusqueda arbol);
bool hojasAlmismoNivelAux(NodoArbol nodo, int nivel_actual, int *nivel_hojas);

int alturaArbolN(ArbolBinarioBusqueda arbol) {
    int altura = 0;
    alturaArbolNaux(abb_raiz(arbol), &altura, 0);
    return altura;
}

void alturaArbolNaux(NodoArbol nodo, int *altura, int contador) {
    if (nodo == NULL) {
        if (contador > *altura) {
            *altura = contador;
        }
        return;
    }
    alturaArbolNaux(n_hijoizquierdo(nodo), altura, contador + 1);
    alturaArbolNaux(n_hijoderecho(nodo), altura, contador);
}

int nivelNodo(ArbolBinarioBusqueda arbol, NodoArbol nodoObj) {
    int resultado = 0;
    nivelNodoAux(abb_raiz(arbol), nodoObj, &resultado);
    return resultado;
}

void nivelNodoAux(NodoArbol nodo, NodoArbol nodoObj, int *nivel) {
    if (nodo == NULL) {
        return;
    }

    if (nodo == nodoObj) {
        (*nivel)++;
        return;
    }

    (*nivel)++;
    nivelNodoAux(n_hijoizquierdo(nodo), nodoObj, nivel);
    nivelNodoAux(n_hijoderecho(nodo), nodoObj, nivel);
    (*nivel)--;
}

Lista nodosInternosN(ArbolBinarioBusqueda arbol) {
    Lista lista = l_crear();
    nodosInternosNaux(abb_raiz(arbol), lista);
    return lista;
}

void nodosInternosNaux(NodoArbol nodo, Lista lista) {
    if (nodo == NULL) {
        return;
    }

    if (n_hijoderecho(nodo) != NULL || n_hijoizquierdo(nodo) != NULL) {
        l_agregar(lista, n_recuperar(nodo));
    }

    nodosInternosNaux(n_hijoizquierdo(nodo), lista);
    nodosInternosNaux(n_hijoderecho(nodo), lista);
}

bool hojasAlmismoNivel(ArbolBinarioBusqueda arbol) {
    int nivel_hojas = -1;
    return hojasAlmismoNivelAux(abb_raiz(arbol), 0, &nivel_hojas);
}

bool hojasAlmismoNivelAux(NodoArbol nodo, int nivel_actual, int *nivel_hojas) {
    if (nodo == NULL) {
        return true;
    }

    if (n_hijoizquierdo(nodo) == NULL && n_hijoderecho(nodo) == NULL) {
        // Es un nodo hoja
        if (*nivel_hojas == -1) {
            *nivel_hojas = nivel_actual;
        } else if (nivel_actual != *nivel_hojas) {
            return false;
        }
    }

    bool mismo_nivel_izquierdo = hojasAlmismoNivelAux(n_hijoizquierdo(nodo), nivel_actual + 1, nivel_hojas);
    bool mismo_nivel_derecho = hojasAlmismoNivelAux(n_hijoderecho(nodo), nivel_actual + 1, nivel_hojas);

    return mismo_nivel_izquierdo && mismo_nivel_derecho;
}

int main(int argc, char const *argv[])
{
    ArbolBinarioBusqueda arbol= crearArbol();
    bool * correcto;
    printf("La altura del arbol es : %d\n",alturaArbolN(arbol));
    printf("Ingrese clave del nodo nodo: ");
    NodoArbol nodo = n_crear(te_crear(ingreso_normalizado_enteros(-1000,1000,correcto)));
    printf("El nivel del nodo es: %d \n",nivelNodo(arbol,nodo));
    Lista lista = nodosInternosN(arbol);
    printf("Nodos internos: \n");
    l_mostrarLista(lista);
    if(hojasAlmismoNivel(arbol)){
        printf("Las hojas estan al mismo nivel");
    }
    else{
        printf("Las hojas no estan al mismo nivel");
    }
    system("PAUSE");
    return 0;
}
