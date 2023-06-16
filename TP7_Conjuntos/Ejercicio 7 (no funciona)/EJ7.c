#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "conjuntos.h"


bool es_subconjunto_total(Conjunto a, Conjunto b)
{
    if (cto_es_vacio(a) || cto_es_vacio(b)) return false; //Si uno de los dos es vacio, no puede haber un subconjunto

    int i;
    TipoElemento x;

    for (i = 1; i < cto_cantidad_elementos(a); i++)
    {
        x = cto_recuperar(a,i);
        if (cto_pertenece(b,x->clave) != true) return false;
    }
    return true;
}


bool es_subconjunto_parcial(Conjunto a, Conjunto b)
{
    if (cto_es_vacio(a) || cto_es_vacio(b)) return false; //Si uno de los dos es vacio, no puede haber un subconjunto

    int i;
    int esta_enConjunto = 0;
    TipoElemento x;

    int mitad_a = round((cto_cantidad_elementos(a) / 2 ));

    for (i = 1; i < cto_cantidad_elementos(a); i++)
    {
        x = cto_recuperar(a,i);
        if (cto_pertenece(b,x->clave) == true) esta_enConjunto++;
        
    }

    if (esta_enConjunto >= mitad_a) return true;
    else return false;
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

    bool es_total = es_subconjunto_total(a,b);
    bool es_parcial = es_subconjunto_parcial(b,c);

    printf("BOOL TOTAL: %d\n", es_total);
    printf("BOOL PARCIAL: %d\n", es_parcial);





    system("pause");
    return 0;
}