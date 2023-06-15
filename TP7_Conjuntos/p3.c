#include "conjuntos_listas.c"
#include "listas_apuntadores.c"
#include "tipo_elemento.c"
#include "funciones_conjuntos.c"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

Conjunto UnionVariosConjuntos(Conjunto conjuntos){
    Conjunto temp, resultado = cto_crear();
    TipoElemento X;
    for (int i = 0; i < cto_cantidad_elementos(conjuntos)+1; i++)
    {
        temp = (Conjunto)cto_recuperar(conjuntos, i)->valor;
        for (int j = 0; j < cto_cantidad_elementos(temp)+1; j++)
        {
            X=cto_recuperar(temp,j);
            cto_agregar(resultado,X);
        }
    }
    return resultado;
}

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    TipoElemento X;
    Conjunto conjuntos = cto_crear();
    Conjunto conjunto1 = cto_crear(), conjunto2 = cto_crear(), conjunto3 = cto_crear();
    randomizarConjunto(&conjunto1,10,35,0);
    randomizarConjunto(&conjunto2,7,35,0);
    randomizarConjunto(&conjunto3,4,35,0);
    printf("=========================================\n");
    printf("Contenido del conjunto 1: \n");
    cto_mostrar(conjunto1);
    printf("=========================================\n");
    printf("Contenido del conjunto 2: \n");
    cto_mostrar(conjunto2);
    printf("=========================================\n");
    printf("Contenido del conjunto 3: \n");
    cto_mostrar(conjunto3);
    X = te_crear_con_valor(1,(void*)conjunto1);
    cto_agregar(conjuntos,X);
    X = te_crear_con_valor(2,(void*)conjunto2);
    cto_agregar(conjuntos,X);
    X = te_crear_con_valor(3,(void*)conjunto3);
    cto_agregar(conjuntos,X);
    printf("=========================================\n");
    printf("Contenido del conjunto union de los tres conjuntos: \n");
    cto_mostrar(UnionVariosConjuntos(conjuntos));
    system("PAUSE");
    return 0;
}
