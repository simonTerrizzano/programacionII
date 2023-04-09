#include "Ejercicio_2.c"

int main(void)
{
    int numero1_normalizado;
    int numero2_normalizado;

    printf("--1er Factor--");
    numero1_normalizado=ingreso_normalizado_enteros_positivos(-1000,1000);

    printf("--2do Factor--");
    numero2_normalizado=ingreso_normalizado_enteros_positivos(-1000,1000);

    printf("El producto de %i y %i es %i",numero1_normalizado,numero2_normalizado ,multiplicacion_recursiva(numero1_normalizado,numero2_normalizado));

    printf("\n\n");

    //system("PAUSE");
    exit(EXIT_SUCCESS);
    return 0;
}
