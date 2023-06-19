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
    TipoElemento X;
    bool * condicion;
    Conjunto conjuntos = cto_crear();
    Conjunto conjunto = cto_crear();
    printf("Ingresa la cantidad de conjuntos que se generaran");
    int cantidadconjuntos = ingreso_normalizado_enteros(2,20,condicion);
    printf("Valor maximo a tomar de los conjuntos: \n");
    int max = ingreso_normalizado_enteros(5,1000,condicion);
    for (int i = 0; i < cantidadconjuntos; i++)
    {
        srand(time(NULL) * ((i * 200)%50));
        randomizarConjunto(&conjunto,max,max*-1,0);
        X = te_crear_con_valor(i,(void*)conjunto);
        cto_agregar(conjuntos,X);
    }
    printf("Claves de los conjuntos: \n");
    for (int j = 0; j < cantidadconjuntos; j++)
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
