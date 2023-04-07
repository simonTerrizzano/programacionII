#include "Ejercicio_10.c"


int main(void)
{
    int num_a_explotar;
 
    int bomba;

    printf("--Número a explotar--\n");
    num_a_explotar=ingreso_normalizado_enteros_positivos(2,1000);

    printf("--Bomba--\n");
    bomba=ingreso_normalizado_enteros_positivos(0,99999999);


    explosivo(num_a_explotar,bomba);

    return 0;
}
