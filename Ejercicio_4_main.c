#include "Ejercicio_4.c"

int main(void)
{
    int numerador, denominador;

    printf("--Numerador--");
    numerador=ingreso_normalizado_enteros(0,1000);

    printf("--Denominador--");
    denominador=ingreso_normalizado_enteros(0,1000);

    printf("\nResultado: %.4f", division(numerador, denominador, PRECISION));

    printf("\n\n");

    system("PAUSE");

    return 0;
}
