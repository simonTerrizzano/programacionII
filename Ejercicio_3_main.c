#include "Ejercicio_3.c"

int main(void)
{
    int ingreso_normalizado;

    printf("--Serie de fibonacci--\n");
    ingreso_normalizado=ingreso_normalizado_enteros(1,40);

    printf("\nEl número %i de la serie de Fibonacci es %i", ingreso_normalizado,fibonacci(ingreso_normalizado));

    printf("\n\n");

    system("PAUSE");

    return 0;
}
