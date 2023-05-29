#include "Ejercicio_10.c"

int main(void){
    int cant_elem;
    int max_rango;
    int rep;

    printf("Ingrese la cantidad de elementos a cargar en los arboles\n");
    cant_elem = ingreso_normalizado_enteros(1,2000);

    printf("Ingrese el límite máximo para las claves a cargar en los arboles\n");
    max_rango = ingreso_normalizado_enteros(1,10000);

    printf("Ingrese la cantidad de veces que quiere que se repita la prueba\n");

    rep=ingreso_normalizado_enteros(1,200);
    cargaenbucle(cant_elem, max_rango, rep);

    return 0;
}
