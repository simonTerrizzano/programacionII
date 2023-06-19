#include "conjuntos_listas.c"
#include "listas_apuntadores.c"
#include "tipo_elemento.c"
#include "funciones_conjuntos.c"
#include "DataEntry.c"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


bool transitividadConjuntos(Conjunto conjunto1, Conjunto conjunto2, Conjunto conjunto3){
    if(cto_cantidad_elementos(cto_interseccion(conjunto1, conjunto2)) == cto_cantidad_elementos(conjunto1)){
        if (cto_cantidad_elementos(cto_interseccion(conjunto2, conjunto3)) == cto_cantidad_elementos(conjunto2))
        {
            return true;
        }
    }
    return false;
}

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    TipoElemento X;
    bool * correcto;
    Conjunto conj1 = cto_crear();
    Conjunto conj2 = cto_crear();
    Conjunto conj3 = cto_crear();
    printf("Transitividad de 3 Conjuntos: \n");
    printf("1. Generar claves aleatorias para los conjuntos\n2. Ingresar claves de conjuntos \n");
    int opcion = ingreso_normalizado_enteros(1,2,correcto);
    if (opcion == 1){
        printf("Valor maximo a tomar de los conjuntos: \n");
        int max = ingreso_normalizado_enteros(5,1000,correcto);
        printf("Cantidad de valores del conjunto 1: ");
        int cantidad = ingreso_normalizado_enteros(1,100,correcto);
        randomizarConjunto(&conj1,cantidad,max,max*-1);
        printf("Cantidad de valores del conjunto 2: ");
        cantidad = ingreso_normalizado_enteros(1,100,correcto);
        randomizarConjunto(&conj2,cantidad,max,max*-1);
        printf("Cantidad de valores del conjunto 3: ");
        cantidad = ingreso_normalizado_enteros(1,100,correcto);
        randomizarConjunto(&conj3,cantidad,max,max*-1);
    }
    else{
        printf("Se generara el conjunto 1: \n");
        crearConjunto(&conj1);
        printf("Se generara el conjunto 2: \n");
        crearConjunto(&conj2);
        printf("Se generara el conjunto 3: \n");
        crearConjunto(&conj3);
    }
    printf("====================================\n");
    printf("CONTENIDO DE LOS CONJUNTOS: \n");
    cto_mostrar(conj1);
    printf("-------------------------------\n");
    cto_mostrar(conj2);
    printf("-------------------------------\n");
    cto_mostrar(conj3);
    printf("====================================\n");
    
    if (transitividadConjuntos(conj1,conj2,conj3))
    {
        printf("EL CONJUNTO 1 ES SUB CONJUNTO DEL CONJUNTO 3 \n");
    }
    else{
        printf("EL CONJUNTO 1 NO ES SUB CONJUNTO DEL CONJUNTO 3 \n");
    }
    system("PAUSE");
    return 0;


}
