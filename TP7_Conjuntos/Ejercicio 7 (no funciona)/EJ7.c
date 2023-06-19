#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "conjuntos.h"
#include "conjuntos_listas.c"
#include "tipo_elemento.c"
#include "listas_apuntadores.c"


bool es_subconjunto_total(Conjunto a, Conjunto b)
{
    if (cto_es_vacio(a) || cto_es_vacio(b)) return false;

    for (int i = 1; i <= cto_cantidad_elementos(a); i++)
    {
        TipoElemento x = cto_recuperar(a, i);
        if (!cto_pertenece(b, x->clave))
            return false;
    }
    return true;
}


bool es_subconjunto_parcial(Conjunto a, Conjunto b)
{
    if (cto_es_vacio(a) || cto_es_vacio(b)) return false;

    int esta_enConjunto = 0;

    for (int i = 1; i <= cto_cantidad_elementos(a); i++)
    {
        TipoElemento x = cto_recuperar(a, i);
        if (cto_pertenece(b, x->clave))
            esta_enConjunto++;
    }

    int mitad_a = cto_cantidad_elementos(a) / 2;
    return (esta_enConjunto >= mitad_a);
}



int main()
{

    Conjunto a = cto_crear();
    Conjunto b = cto_crear();
    Conjunto c = cto_crear();

    cto_agregar(a,te_crear(3));
    cto_agregar(a,te_crear(4));
    cto_agregar(a,te_crear(5));

    cto_agregar(b,te_crear(1));
    cto_agregar(b,te_crear(2));
    cto_agregar(b,te_crear(3));
    cto_agregar(b,te_crear(4));
    cto_agregar(b,te_crear(5));
    cto_agregar(b,te_crear(6));
    cto_agregar(b,te_crear(7));
    cto_agregar(b,te_crear(8));
    cto_agregar(b,te_crear(9));

    cto_agregar(c,te_crear(2));
    cto_agregar(c,te_crear(4));
    cto_agregar(c,te_crear(6));
    cto_agregar(c,te_crear(8));
    cto_agregar(c,te_crear(7));

    cto_mostrar(a);
    cto_mostrar(b);
    cto_mostrar(c);
    bool es_totalab = es_subconjunto_total(a,b);
    bool es_totalac = es_subconjunto_total(a,c);
    bool es_totalba = es_subconjunto_total(b,a);
    bool es_totalbc = es_subconjunto_total(b,c);
    bool es_totalca = es_subconjunto_total(c,a);
    bool es_totalcb = es_subconjunto_total(c,b);
    bool es_parcialab = es_subconjunto_parcial(a,b);
    bool es_parcialac = es_subconjunto_parcial(a,c);
    bool es_parcialba = es_subconjunto_parcial(b,a);
    bool es_parcialbc = es_subconjunto_parcial(b,c);
    bool es_parcialca = es_subconjunto_parcial(c,a);
    bool es_parcialcb = es_subconjunto_parcial(c,c);
    if (es_totalab)
    {
        printf("a es sub conjunto total de b\n");
    }
    if (es_totalac)
    {
        printf("a es sub conjunto total de c\n");
    }
    if (es_totalba)
    {
        printf("b es sub conjunto total de a\n");
    }
    if (es_totalbc)
    {
        printf("b es sub conjunto total de c\n");
    }
    if (es_totalca)
    {
        printf("c es sub conjunto total de a\n");
    }
    if (es_totalcb)
    {
        printf("c es sub conjunto total de b\n");
    }
    if (es_parcialab && !es_totalab)
    {
        printf("a es sub conjunto parcial de b\n");
    }
    if (es_parcialac && !es_totalac)
    {
        printf("a es sub conjunto parcial de c\n");
    }
    if (es_parcialba && !es_totalba)
    {
        printf("b es sub conjunto parcial de a\n");
    }
    if (es_parcialbc && !es_totalbc)
    {
        printf("b es sub conjunto parcial de c\n");
    }
    if (es_parcialca && !es_totalca)
    {
        printf("c es sub conjunto parcial de a\n");
    }
    if (es_parcialcb && !es_totalcb)
    {
        printf("c es sub conjunto parcial de b\n");
    }









    system("pause");
    return 0;
}
