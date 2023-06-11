#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <math.h>

#include "tabla_hash_lista_colisiones.c" //Incluir TAD tabla hash
#include "arbol_avl.c" //Incluir TAD arbol AVL


//=======================================
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
//=======================================



/*5. Realizar una comparación de los tiempos de accesos a las claves entre un árbol AVL y 
una Tabla Hash. El operador debe poder indicarle cuantas claves se deben generar 
(entre 1 y 2000), cuantas repeticiones se realizaran y cuál es el rango de las claves a 
generar. Luego se tomarán claves al azar dentro del mismo rango y se buscaran en 
ambas estructuras. El proceso se repetirá “n” veces (repeticiones a ingresar por el
operador). Documentar la conclusión final respecto a los tiempos de accesos de 
ambas estructuras. */

int funcionHash(int clave)
{
    return clave % 2003; //2003 es primo
}



TablaHash CargarTH(int min, int max, int repeticiones)
{
    TablaHash th = th_crear(2003,&funcionHash);
    int numero;
    int i;

    for (i = 0; i < repeticiones; i++)
    {
        numero = rand() % ((max+1)- min) + min;
        th_insertar(th,te_crear(numero));
    }

    return th;
}

ArbolAVL CargarAVL(int min, int max, int repeticiones)
{
    ArbolAVL avl = avl_crear();
    int numero, i;

    for (i = 0; i < repeticiones; i++)
    {
        numero = rand() % ((max+1)- min) + min;
        avl_insertar(avl,te_crear(numero)); 
    }
    return avl;
}

#include <stdio.h>
#include <time.h>

void Tiempo_Busqueda(TablaHash th, ArbolAVL avl, int repeticiones, int max, int min)
{
    clock_t comienzo_th, final_th;
    clock_t comienzo_avl, final_avl;
    double tiempo_total;
    int clave;
    printf("===============================\n");

    // Comienzo el contador para la tabla hash
    comienzo_th = clock();
    for (int i = 0; i < repeticiones; i++)
    {
        clave = rand() % ((max+1)- min) + min;
        th_recuperar(th, clave);
    }
    final_th = clock();
    // Calculo el tiempo total en segundos
    tiempo_total = (double)(final_th - comienzo_th) / CLOCKS_PER_SEC;
    printf("Tiempo de ejecución (Tabla Hash): %.9f segundos\n", tiempo_total);

    // Comienzo el contador para el árbol AVL
    comienzo_avl = clock();
    for (int j = 0; j < repeticiones; j++)
    {
        clave = rand() % ((max+1)- min) + min;
        avl_buscar(avl, clave);
    }
    
    
    final_avl = clock();

    // Calculo el tiempo total en segundos
    tiempo_total = (double)(final_avl - comienzo_avl) / CLOCKS_PER_SEC;
    printf("Tiempo de ejecución (Árbol AVL): %.9f segundos\n", tiempo_total);
}




int main()
{

    TablaHash th;
    ArbolAVL avl;
    bool salir = false;
    int cantidad_claves, min,max, repeticiones,clave,i;
    char* input = malloc(sizeof(char));

    srand(time(NULL));

    while (!salir)
    {
        //Pregunto cuantas claves hay que generar
        while (true)
        {
            printf("Ingrese la cantidad de claves que va a contener la tabla hash y el arbol AVL (1 a 2000)\n");
            printf("Cantidad de claves:");
            gets(input);
            if (validarEntero(input))
            {
                cantidad_claves = strtol(input,NULL,10);
                if (cantidad_claves >= 1 && cantidad_claves <= 2000) input[0] = '\0'; break;     
            }

            printf("Se ingreso un dato incorrecto. Vuelva a intentarlo\n");
        }

        //Pido el minimo valor
        while (true)
        {
            printf("Ingrese el minimo valor a generar: ");
            gets(input);
            if (validarEntero(input))
            {
                min = strtol(input,NULL,10);
                if (min > 0 && min <= 2000) input[0]; break;
            }
            printf("Se ingreso un dato incorrecto. Vuelva a intentarlo\n");
        }

        //Pido el maximo valor
        while (true)
        {
            printf("Ingrese el maximo valor a generar: ");
            gets(input);
            if (validarEntero(input))
            {
                max = strtol(input,NULL,10);
                if (max > min && max <= 2000) input[0]; break;
            }
            printf("Se ingreso un dato incorrecto. Vuelva a intentarlo\n");
        }

        //Pido cantidad de repeticiones
        while (true)
        {
            printf("Ingrese la cantidad de veces que se va a repetir el proceso (1 a 5000):");
            gets(input);
            if (validarEntero(input))
            {
                repeticiones = strtol(input,NULL,10);
                if (repeticiones >= 1 && repeticiones <= 5000) input[0]; break;
                printf("Se ingreso un dato incorrecto. Vuelva a intentarlo\n");
            }
        }


        th = CargarTH(min,max,repeticiones);
        avl = CargarAVL(min,max,repeticiones);
        Tiempo_Busqueda(th,avl,repeticiones,max,min);

        //Consulo si quiere salir del programa
        printf("\nIngrese X si quiere salir o enter para continuar...\n");
        gets(input);
        if ((input[0] == 'x' || input[0] == 'X') && (strlen(input) == 1)) salir = true;



    }


    system("pause");
    return 0;
}