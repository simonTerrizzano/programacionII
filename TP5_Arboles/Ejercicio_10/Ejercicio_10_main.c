#include "Ejercicio_10.c"

int main(void){
    int cant_elem;
    int max_rango;
    int rep;

    printf("Ingrese la cantidad de elementos a cargar en los arboles\n");
    cant_elem = ingreso_normalizado_enteros(1,2000);

    printf("Ingrese el límite máximo para las claves a cargar en los arboles\n");
    printf("--El rango mínimo se estableserá como la cantidad de elemento multiplicado por 3 (x3)-- \n");
    max_rango = ingreso_normalizado_enteros(cant_elem*3,999999999);

    printf("Ingrese la cantidad de veces que quiere que se repita la prueba\n");

    rep=ingreso_normalizado_enteros(1,200);
    cargaenbucle(cant_elem, max_rango, rep);

    printf("Podemos concluir que a medida que crece la cantidad de nodos en ambos arboles se hace mayor la diferencia en altura.\n");
    printf("La altura de los arboles binarios de búsqueda es siempre mayores o iguales de a la de los arboles AVL.\n");
    printf("La diferencia crece notablemente sí se realiza una carga ascendente de las claves.\n");

    return 0;
}
