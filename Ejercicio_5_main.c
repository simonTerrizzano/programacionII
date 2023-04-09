#include "Ejercicio_5.c"

int main()
{
    int numero_sin_puntos;
    char buffer[50];

    printf("--Numero para agregar separador de miles--");

    numero_sin_puntos=ingreso_normalizado_enteros(-999999999,999999999);

    char* numero_con_puntos;

    //itoa(numero_sin_puntos,numero_con_puntos,10); // itoa no es parte del standar. Por lo tanto solo correra en
    //bibliotecas que tengan implementaciones no standar.
    // sprintf agrega portabilidad al codigo
    sprintf(buffer,"%d",numero_sin_puntos);
    agregar_separador_de_miles(buffer);

    printf("\n\n");

    exit(EXIT_SUCCESS);

    return 0;
}
