#include "ejercicio_2.c"

int main(void)
{
    Pila pila=p_crear();
    Pila duplicada;
    TipoElemento x;
    for (int i = 1; i < 9; i++)
    {
        x=te_crear(i);
        p_apilar(pila,x);
    }
    x=te_crear(20);
    p_insertar(pila,x,2);
    p_insertar(pila,x,7);
    duplicada=p_duplicar(pila);
    p_eliminar_elemento(pila,20);
    // p_mostrar(pila);
    p_mostrar(pila);
    printf("\n%i\n",p_contar_elementos(pila));

    // p_apilar(pila,x);
    if(p_buscar_clave(pila,4)){
        printf("La clave se encuentra en la pila\n");
    }else{
        printf("La clave no se encuentra en la pila\n");
    }
    printf("\n%i\n",p_contar_elementos(pila));
    if(p_buscar_clave(pila,34)){
        printf("La clave se encuentra en la pila\n");
    }else{
        printf("La clave no se encuentra en la pila\n");
    }
    printf("\n%i\n",p_contar_elementos(pila));
    p_mostrar(pila);
    printf("\n");
    p_mostrar(duplicada);

    p_intercambiar(pila, 2,4);
    printf("\n");
    p_mostrar(pila);

    return 0;
}

