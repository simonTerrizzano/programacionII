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

/*Dados dos conjuntos de números naturales se pide determinar si son iguales sin 
importar la posición de sus elementos. Determinar la complejidad algorítmica.
Ejemplo: si A = (3, 4, 5, 6) y B = (3, 5, 4, 6) entonces a “A” es igual “B” y viceversa.*/


bool iguales(Conjunto a, Conjunto b)
{
    if (cto_es_vacio(a) && cto_es_vacio(b)) return true; //Ambos conjuntos son vacios, por lo tanto son iguales
    if (cto_es_vacio(a) || cto_es_vacio(b)) return false; //Uno de los dos conjuntos es vacio por lo tanto no pueden ser iguales

    if (cto_cantidad_elementos(a) != cto_cantidad_elementos(b)) return false; //Si los conjuntos tienen distinto tamanio tampoco pueden ser iguales

    int i;
    TipoElemento x;
    for (i = 1; i < cto_cantidad_elementos(a); i++)
    {
        x = cto_recuperar(a,i);
        if (cto_pertenece(b,x->clave) != true) return false;
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
    if (iguales(a,b) == true)
    {
        printf("EL CONJUNTO A ES IGUAL AL CONJUNTO B\n");
    }
    else printf("EL CONJUNTO A ES DISTINTO AL CONJUNTO B\n");


    printf("\n\n COMPLEJIDAD ALGORITMICA \n");
    printf("La complejidad algoritmica de la funcion 'iguales()' es O(N) ya que\nes un bucle con el tamanio del conjunto A que en el peor de los casos se ejecutaria N veces\nsiendo N el tamanio de A\n\n.");

    system("pause");
    return 0;
}