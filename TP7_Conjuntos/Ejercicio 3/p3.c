#include "conjuntos_listas.c"
#include "listas_apuntadores.c"
#include "tipo_elemento.c"
#include "funciones_conjuntos.c"
#include "DataEntry.c"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


Conjunto UnionVariosConjuntos(Conjunto conjuntos){
    Conjunto temp, resultado = cto_crear();
    TipoElemento X;
    for (int i = 0; i < cto_cantidad_elementos(conjuntos)+1; i++)
    {
        temp = (Conjunto)cto_recuperar(conjuntos, i)->valor;
        for (int j = 0; j < cto_cantidad_elementos(temp)+1; j++)
        {
            X=cto_recuperar(temp,j);
            cto_agregar(resultado,X);
        }
    }
    return resultado;
}

int main(int argc, char const *argv[])
{
    TipoElemento X,Y;
    char * input;
    bool * condicion;
    bool fin = false;
    int num;
    Conjunto conjuntos = cto_crear();
    Conjunto conjunto = cto_crear();
    printf("Se crearan los conjuntos\n");
    printf("Ingresa la cantidad de conjuntos que se ingresaran: \n");
    int cantidadconjuntos = ingreso_normalizado_enteros(2,20,condicion);
    for (int i = 1; i < cantidadconjuntos+1; i++)
    {
        while(!fin){
            printf("Conjunto %d\n",i);
            printf("Ingrese -1 para finalizar\n");
            num = ingreso_normalizado_enteros(-10000,10000,condicion);
            if(num == -1){
                fin = true;
            }
            else{
                Y = te_crear(num);
                cto_agregar(conjunto,Y);
            }
        }
        X = te_crear_con_valor(i,(void*)conjunto);
        cto_agregar(conjuntos,X);
        conjunto = cto_crear();
        fin = false;
    }
    printf("Claves de los conjuntos: \n");
    for (int j = 1; j < cantidadconjuntos + 1; j++)
    {
        printf("Conjunto %d: \n",j);
        conjunto = (Conjunto)cto_recuperar(conjuntos,j)->valor;
        cto_mostrar(conjunto);
    }
    
    printf("=========================================\n");
    printf("Contenido del conjunto union de los tres conjuntos: \n");
    cto_mostrar(UnionVariosConjuntos(conjuntos));
    system("PAUSE");
    return 0;
}
