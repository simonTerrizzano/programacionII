#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <math.h>

#include "tabla_hash.h"
#include "arbol_avl.h"
#include "Validacion_datos.h"


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


/*
 @param intervalo minimo
 @param intermalo maximo 
*/
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
}


void Tiempo_Busqueda(TablaHash th, ArbolAVL avl, int clave)
{
    int i;
    struct timeval comienzo,final;
    gettimeofday(&comienzo,NULL);

    for (i = 0; i < 1000000; i++)
    {
        th_recuperar(th,432);
        th_recuperar(th,254);
        th_recuperar(th,2);
        th_recuperar(th,762);       
    }

    
    gettimeofday(&final,NULL);
    long microsegundos = final.tv_usec - comienzo.tv_usec;
    printf("Tiempo tabla hash = %ld", (final.tv_usec - comienzo.tv_usec));
}


int main()
{

    TablaHash th = th_crear(2003,&funcionHash);
    ArbolAVL avl = avl_crear();

    th_insertar(th,te_crear(2));
    th_insertar(th,te_crear(254));
    th_insertar(th,te_crear(762));
    th_insertar(th,te_crear(432));
    th_insertar(th,te_crear(26565));
    th_insertar(th,te_crear(58678));

    

 
    Tiempo_Busqueda(th,avl,432);


    system("pause");
    return 0;
}

