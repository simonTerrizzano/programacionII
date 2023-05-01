#include "punto6.c"
int main()
{
    bool exit;
    Pila pila_1 = p_crear();
    p_cargar_con_enteros(pila_1);
    Pila modf = p_eliminar_ocurrencias_recursivo(pila_1, ingreso_normalizado_enteros(0, 500, &exit));
    p_mostrar(modf);

    printf("\n\n\n");
    p_mostrar(pila_1);

}
