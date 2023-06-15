#include "conjuntos_listas.c"
#include "listas_apuntadores.c"
#include "tipo_elemento.c"
#include "funciones_conjuntos.c"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


Conjunto UnionConjunto(Conjunto conj1, Conjunto conj2){
    Conjunto Resultado = cto_crear();
    for (int i = 0; i < cto_cantidad_elementos(conj1) + 1; i++)
    {
        cto_agregar(Resultado, cto_recuperar(conj1,i));
    }
    for (int J = 0; J < cto_cantidad_elementos(conj2) + 1; J++)
    {
        cto_agregar(Resultado, cto_recuperar(conj2,J));
    }
    return Resultado;
}

Conjunto InterseccionConjunto(Conjunto conj1, Conjunto conj2){
    TipoElemento X,Y;
    Conjunto resultado = cto_crear();
    for (int i = 0; i < cto_cantidad_elementos(conj1) + 1; i++)
    {
        X = cto_recuperar(conj1,i);
        for (int j = 0; j < cto_cantidad_elementos(conj2) + 1; j++)
        {
            Y = cto_recuperar(conj2,j);
            if (X->clave == Y->clave)
            {
                cto_agregar(resultado,X);
            }
        }
    }
    return resultado;
}

Conjunto DiferenciaConjunto(Conjunto conj1, Conjunto conj2){
    TipoElemento X,Y;
    Conjunto resultado = cto_crear();
    bool aparece;
    for (int i = 0; i < cto_cantidad_elementos(conj1) + 1; i++)
    {
        X = cto_recuperar(conj1,i);
        aparece = false;
        for (int j = 0; j < cto_cantidad_elementos(conj2) + 1; j++)
        {
            Y = cto_recuperar(conj2,j);
            if (X->clave == Y->clave)
            {
                aparece = true;
            }
        }
        if(!aparece){
            cto_agregar(resultado,X);
        }
    }
    return resultado;
}

bool perteneceConjunto(Conjunto conj1, TipoElemento X){
    bool resultado = false;
    TipoElemento Y;
    for (int i = 0; i < cto_cantidad_elementos(conj1) + 1; i++)
    {
        X = cto_recuperar(conj1, i);
        if (X->clave = Y->clave)
        {
            resultado = true;
            break;
        }
    }
    return resultado;
}

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    Conjunto conj1 = cto_crear();
    Conjunto conj2 = cto_crear();
    randomizarConjunto(&conj1,10,10,0);
    randomizarConjunto(&conj2,5,10,0);
    printf("====================================\n");
    printf("CONTENIDO DE AMBOS CONJUNTOS: \n");
    cto_mostrar(conj1);
    printf("-------------------------------\n");
    cto_mostrar(conj2);
    printf("====================================\n");
    printf("UNION DE LOS 2 CONJUNTOS: \n");
    cto_mostrar(UnionConjunto(conj1,conj2));
    printf("-------------------------------\n");
    printf("INTERSECCION DE LOS 2 CONJUNTOS: \n");
    cto_mostrar(InterseccionConjunto(conj1,conj2));
    printf("-------------------------------\n");
    printf("DIFERENCIA DE LOS 2 CONJUNTOS: \n");
    cto_mostrar(DiferenciaConjunto(conj1,conj2));
    printf("-------------------------------\n");
    int clave;
    printf("Clave a buscar si pertenece al conjunto 1: ");
    scanf("%d",&clave);
    TipoElemento X = te_crear(clave);
    if (perteneceConjunto(conj1, X))
    {
        printf("Pertenece al conjunto\n");
    }
    else{ printf("No pertenece al conjunto \n");}
    printf("====================================\n");
    system("PAUSE");
    return 0;
}
