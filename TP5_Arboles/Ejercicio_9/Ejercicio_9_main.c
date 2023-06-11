#include "Ejercicio_9.c"

int main(void)
{
    ArbolBinarioBusqueda A1;
    ArbolAVL A2;
    int cant;
    int altura_abb=0;
    int altura_avl=0;
    printf("Ingrese cantidad de Nodos aleatorios a insertar en el Arbol");
    cant=ingreso_normalizado_enteros(0,100);
    A1= abb_crear();
    Cargar_Arbol(A1,cant);
    A2 = abb_a_avl_interfaz(A1);
    printf("Arbol Binario de Búsqueda\n");
    printf("-----------------------------------------------------\n");
    printf("Pre-Orden Desde la raiz\n");
    pre_orden(abb_raiz(A1));
    printf("\n");
    printf("-----------------------------------------------------\n");
    printf("In-Orden Desde la raiz\n");
    in_orden(abb_raiz(A1));
    printf("\n");
    printf("-----------------------------------------------------\n");
    printf("Post-Orden Desde la raiz\n");
    post_orden(abb_raiz(A1));
    printf("\n");
    
    printf("Arbol AVL\n");
    printf("-----------------------------------------------------\n");
    printf("Pre-Orden Desde la raiz\n");
    pre_orden(avl_raiz(A2));
    printf("\n");
    printf("-----------------------------------------------------\n");
    printf("In-Orden Desde la raiz\n");
    in_orden(avl_raiz(A2));
    printf("\n");
    printf("-----------------------------------------------------\n");
    printf("Post-Orden Desde la raiz\n");
    post_orden(avl_raiz(A2));
    printf("\n");

    altint(abb_raiz(A1),&altura_abb,0);
    altint(avl_raiz(A2),&altura_avl,0);

    
    printf("La altura del Arbol Binario de Busqueda es de %i\n", altura_abb);
    printf("La altura del Arbol Binario de Busqueda Auto-Balanceado es de %i \n\n", altura_avl);

    printf("Determinamos que la Complejidad Algoritmica de este ejercicio es de O(n) siendo n la cantidad de elementos que esten cargados en el Arbol Binario de Búsqueda\n");

    return 0;
}
