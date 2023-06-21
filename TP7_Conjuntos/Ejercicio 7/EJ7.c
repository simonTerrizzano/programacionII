#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "conjuntos.h"
#include "conjuntos_listas.c"
#include "tipo_elemento.c"
#include "listas_apuntadores.c"

//========================================
bool validarEntero(char* cadena)
{
    int i;
    bool esNumero = false;
    int longitud = strlen(cadena);

    if (cadena[0] == '-') i = 1;
    else i = 0;

    for (i; i < longitud; i++)
    {
        //Valido que el input sea un NUMERO
        if (cadena[i] >= 48 && cadena[i] <=57)
        {
            if (cadena[i] != ' ') esNumero = true;
            else return false;
            
        }
        else return false;
    }

    return esNumero;
}
//========================================



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

    char* input = malloc(5*sizeof(char));

    printf("CARGANDO CONJUNTO A...\n\n");
    //Pido el conjunto A
    while (true)
    {
        printf("Ingrese un numero para el conjunto A (0 a 100000 | -1 para salir): ");
        gets(input);

        if (validarEntero(input) && strlen(input) > 0)
        {
            int num = strtol(input,NULL,10);
            
            if (num == -1) break; //Condicion de salida

            if (num > 0 && num < 100000) cto_agregar(a,te_crear(num));
            else printf("Numero fuera de los rangos.\n\n");
        }
        else printf("El dato ingresado es incorrecto.\n\n");

        input[0] = '\0'; //Limpio la variable
    }

    printf("\n\nCARGANDO CONJUNTO B...\n\n");
    //Pido el conjunto B
    while (true)
    {
        printf("Ingrese un numero para el conjunto B (0 a 100000 | -1 para salir): ");
        gets(input);

        if (validarEntero(input) && strlen(input) > 0)
        {
            int num = strtol(input,NULL,10);
            
            if (num == -1) break; //Condicion de salida

            if (num > 0 && num < 100000) cto_agregar(b,te_crear(num));
            else printf("Numero fuera de los rangos.\n\n");
        }
        else printf("El dato ingresado es incorrecto.\n\n");

        input[0] = '\0'; //Limpio la variable
    }

    printf("\n\nCARGANDO CONJUNTO C...\n\n");
    //Pido el conjunto C
    while (true)
    {
        printf("Ingrese un numero para el conjunto C (0 a 100000 | -1 para salir): ");
        gets(input);

        if (validarEntero(input) && strlen(input) > 0)
        {
            int num = strtol(input,NULL,10);
            
            if (num == -1) break; //Condicion de salida

            if (num > 0 && num < 100000) cto_agregar(c,te_crear(num));
            else printf("Numero fuera de los rangos.\n\n");
        }
        else printf("El dato ingresado es incorrecto.\n\n");

        input[0] = '\0'; //Limpio la variable
    }

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

    printf("\n\n COMPLEJIDAD ALGORITMICA \n");

    printf("La complejidad algoritmica de la funcion 'es_subconjuntos_parcial()' y 'es_subconjuntos_total()' es O(n²) en el caso de usar la implementación con LISTAS ya que es un por cada elemento del conjunto A se recorreran como máximo todos los elementos del conjunto B ");
    printf("La complejidad algoritmica de la funcion 'es_subconjuntos_parcial()' y 'es_subconjuntos_total()' es O(n log n) en el caso de usar la implementación con ARBOLES AVL ya que es un por cada elemento del conjunto A se realizará una búsqueda binaria en el conjunto B ");

    system("pause");
    return 0;
}
