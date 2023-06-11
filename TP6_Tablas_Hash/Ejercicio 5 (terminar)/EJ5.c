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


void Tiempo_Busqueda(TablaHash th, ArbolAVL avl, int clave)
{
    int i;
    struct timeval comienzo_th,final_th;
    struct timeval comienzo_avl,final_avl;

    printf("===============================\n");

    //Comienzo el contador
    gettimeofday(&comienzo_th,NULL);
    th_recuperar(th,clave);
    gettimeofday(&final_th,NULL);
    long microsegundos_th = final_th.tv_usec - comienzo_th.tv_usec;
    printf("Tiempo tabla hash (microsegundos) = %Lf\n", (double) microsegundos_th*1e-6);


    gettimeofday(&comienzo_avl,NULL);
    avl_buscar(avl,clave);
    gettimeofday(&final_avl,NULL);
    long microsegundos_avl = final_avl.tv_usec - comienzo_avl.tv_usec;
    printf("Tiempo arbol AVL (microsegundos) = %Lf\n", (double) microsegundos_avl*1e-6);
    
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

        for (i = 0; i < repeticiones; i++)
        {
            clave = rand() % ((max+1)- min) + min;
            Tiempo_Busqueda(th,avl,clave);
        }

        //Consulo si quiere salir del programa
        printf("\nIngrese X si quiere salir o enter para continuar...\n");
        gets(input);
        if ((input[0] == 'x' || input[0] == 'X') && (strlen(input) == 1)) salir = true;



    }


    system("pause");
    return 0;
}