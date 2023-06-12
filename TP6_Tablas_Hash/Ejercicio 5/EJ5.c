#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <math.h>

#include "tabla_hash.h" //Incluir TAD tabla hash
#include "arbol_avl.h" //Incluir TAD arbol AVL


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


double Tiempo_Busqueda_hash(TablaHash th, int repeticiones, int max, int min)
{
    struct timeval comienzo, final;
    int clave,i;

    // Comienzo el contador para la tabla hash
    gettimeofday(&comienzo,0);
    for (i = 0; i < repeticiones; i++)
    {
        clave = rand() % ((max+1)- min) + min;
        th_recuperar(th, clave);
    }
    //Freno el contador de tiempo
    gettimeofday(&final,0);
    //Calculo los segundos
    long seconds = final.tv_sec - comienzo.tv_sec;
    //Calculo los microsegundos
    long microseconds = final.tv_usec - comienzo.tv_usec;
    double tiempo_total = seconds + microseconds*1e-6;
    printf("Tiempo tabla hash: %.5f segundos\n", tiempo_total);
    return tiempo_total;

}

double Tiempo_Busqueda_avl(ArbolAVL avl, int repeticiones, int max, int min)
{
    struct timeval comienzo, final;
    int clave,i;

    // Comienzo el contador para la tabla hash
    gettimeofday(&comienzo,0);
    for (i = 0; i < repeticiones; i++)
    {
        clave = rand() % ((max+1)- min) + min;
        TipoElemento x = te_crear(clave);
        avl_buscar(avl,x->clave);
    }
    gettimeofday(&final,0);
    long seconds = final.tv_sec - comienzo.tv_sec;
    long microseconds = final.tv_usec - comienzo.tv_usec;
    double tiempo_total = seconds + microseconds*1e-6;
    printf("Tiempo arbol AVL: %Lf segundos\n", tiempo_total);
    return tiempo_total;

}



int main()
{

    TablaHash th;
    ArbolAVL avl;
    bool salir = false;
    int cantidad_claves, min,max, repeticiones, repeticiones_busqueda,clave,i;
    char* input = malloc(sizeof(char));
    double tiempo_AVL = 0;
    double tiempo_HASH = 0;

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
                if (cantidad_claves >= 1 && cantidad_claves <= 2000) {input[0] = '\0'; break;}     
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
                if (min > 0 && min <= 2000) {input[0]; break;}
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
                if (max > min && max <= 2000) {input[0]; break;}
            }
            printf("Se ingreso un dato incorrecto. Vuelva a intentarlo\n");
        }

        //Pido cantidad de numeros a buscae
        while (true)
        {
            printf("Ingrese la cantidad de numeros a buscar (1 a 5000000):");
            gets(input);
            if (validarEntero(input))
            {
                repeticiones_busqueda = strtol(input,NULL,10);
                if (repeticiones_busqueda >= 1 && repeticiones_busqueda <= 5000000) {input[0]; break;}
                printf("Se ingreso un dato incorrecto. Vuelva a intentarlo\n");
            }
        }


        //Pido cantidad de repeticiones
        while (true)
        {
            printf("Ingrese la cantidad de veces que se va a repetir el proceso (1 a 5000):");
            gets(input);
            if (validarEntero(input))
            {
                repeticiones = strtol(input,NULL,10);
                if (repeticiones >= 1 && repeticiones <= 5000) {input[0]; break;}
                printf("Se ingreso un dato incorrecto. Vuelva a intentarlo\n");
            }
        }


        for (i = 0; i < repeticiones; i++)
        {
            th = CargarTH(min,max,repeticiones);
            avl = CargarAVL(min,max,repeticiones);
            tiempo_HASH = tiempo_HASH + Tiempo_Busqueda_hash(th,repeticiones_busqueda,max,min);
            tiempo_AVL = tiempo_AVL + Tiempo_Busqueda_avl(avl,repeticiones_busqueda,max,min);
        }

        printf("\nCONCLUSIONES:\n");
        printf("Promedio de tiempo HASH --> %.5f \n", tiempo_HASH / (double) repeticiones);
        printf("Promedio de tiempo AVL --> %.5f \n", tiempo_AVL / (double) repeticiones);



        //Consulo si quiere salir del programa
        printf("\nIngrese X si quiere salir o enter para continuar...\n");
        gets(input);
        if ((input[0] == 'x' || input[0] == 'X') && (strlen(input) == 1)) salir = true;



    }


    system("pause");
    return 0;
}
