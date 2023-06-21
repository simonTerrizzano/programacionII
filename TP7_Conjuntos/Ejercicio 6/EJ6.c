#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "conjuntos.h"

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






/*Dados dos conjuntos de números naturales se pide determinar si uno es subconjunto 
propio del otro. Determinar la complejidad algorítmica. 

Ejemplo: si A = (3, 4, 5) y B = (1,2,3,4,5,6,7,8,9) entonces a “A” es un subconjunto 
propio del conjunto “B” porque todos los elementos de “A” están en “B” pero “A” <> 
“B”.*/


bool es_subconjunto(Conjunto a, Conjunto b)
{
    TipoElemento x;
    Conjunto cto_aux;
    int i;
    if (cto_es_vacio(a) && cto_es_vacio(b)) return false; //Si ambos son vacios no pueden ser subconjuntos
    if (cto_es_vacio(a) || cto_es_vacio(b)) return false; //Si uno es vacio y el otro no tampoco pueden ser subjuntos

    cto_aux = cto_diferencia(a,b);
    if (cto_es_vacio(cto_aux) == true) return false; //Si ambos conjuntos son iguales no pueden ser subconjuntos


    for (i = 1; i <= cto_cantidad_elementos(a); i++)
    {
        x = cto_recuperar(a,i);
        if (cto_pertenece(b, x->clave) == false) return false;
    }

    return true;
}



int main()
{
    Conjunto a = cto_crear();
    Conjunto b = cto_crear();
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

    //Muestro ambos conjuntos
    printf("\n\nMOSTRANDO CONJUNTO A Y B\n");
    cto_mostrar(a);
    cto_mostrar(b);

    //Paso por la funcion y muestro los resultados
    if (es_subconjunto(a,b) == true)
    {
        printf("EL CONJUNTO A ES SUBCONJUNTO PROPIO DE B\n");
    }
    else printf("EL CONJUNTO A NO ES SUBCONJUNTO PROPIO DE B\n");


    printf("\n\n COMPLEJIDAD ALGORITMICA \n");
    printf("La complejidad algoritmica de la funcion 'es_subconjuntos()' es O(n²) en el caso de usar la implementación con LISTAS ya que es un por cada elemento del conjunto A se recorreran como máximo todos los elementos del conjunto B ");
    printf("La complejidad algoritmica de la funcion 'es_subconjuntos()' es O(n log n) en el caso de usar la implementación con ARBOLES AVL ya que es un por cada elemento del conjunto A se realizará una búsqueda binaria en el conjunto B ");

    system("pause");
    return 0;
}
