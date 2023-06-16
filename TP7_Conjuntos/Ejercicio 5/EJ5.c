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

/* Desarrollar un algoritmo capaz de resolver la diferencia simétrica (por la clave) entre 
dos conjuntos. La diferencia simétrica es una operación entre dos conjuntos donde el 
conjunto resultante está conformado por los elementos no comunes a los dos 
conjuntos. */

Conjunto Dif_simetrica(Conjunto cto_a, Conjunto cto_b)
{
    //Si ambos conjuntos son vacios retorno NULL
    if (cto_es_vacio(cto_a) && cto_es_vacio(cto_b)) return NULL;

    Conjunto cto_aux = cto_crear();
    Conjunto cto_simetrico = cto_crear();
    int i;
    TipoElemento a,x;
    
    //Uso la funcion de interseccion para obtener un conjunto con las claves comunes
    cto_aux = cto_interseccion(cto_a,cto_b);

    for (i = 1; i <= cto_cantidad_elementos(cto_a); i++)
    {
        a = cto_recuperar(cto_a,i);
        if (cto_pertenece(cto_aux,a->clave) == false)
        {
            cto_agregar(cto_simetrico,a);
        }
    }
    for (i = 1; i <= cto_cantidad_elementos(cto_b); i++)
    {
        a = cto_recuperar(cto_b,i);
        if (cto_pertenece(cto_aux,a->clave) == false)
        {
            cto_agregar(cto_simetrico,a);
        }
    }

    return cto_simetrico;

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

    printf("\n\nMOSTRANDO DIFERENCIA SIMETRICA...\n");
    Conjunto c = Dif_simetrica(a,b);
    cto_mostrar(c);


    system("pause");
    return 0;
}