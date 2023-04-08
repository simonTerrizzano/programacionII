#include "Ejercicio_5.c"

int main(void)
{
    int numero_sin_puntos;

    printf("--Numero para agregar separador de miles--");

    numero_sin_puntos=ingreso_normalizado_enteros(0,999999999);

    char* numero_con_puntos;

    itoa(numero_sin_puntos,numero_con_puntos,10);

    agregar_separador_de_miles(numero_con_puntos);

    // printf("%s",numero_con_puntos);

    return 0;
}
