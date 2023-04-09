#include "Ejercicio_4.c"

int main(void)
{
    int numerador, denominador;

    printf("--Numerador--");
    numerador=ingreso_normalizado_enteros(-1000,1000);

    printf("--Denominador--");
    denominador=ingreso_normalizado_enteros(-1000,1000);
    if(denominador==0)
    {
	printf("La division por 0 no esta definida. Porfavor intente con un numero distinto de 0 la proxima vez\n\n");
	exit(EXIT_FAILURE);
    }
    
    if( (numerador < 0 || denominador < 0)  && !(denominador < 0 && numerador < 0) )
    {
	printf("\nResultado: -%.4f", division(abs(numerador), abs(denominador), PRECISION));
	
    }
    else
    {

	printf("\nNumerador:%d\tDenominador:%d", numerador, denominador);
	printf("\nResultado: %.4f", division(abs(numerador), abs(denominador), PRECISION));
    }
    
    printf("\n\n");

    exit(EXIT_SUCCESS);

    return 0;
}
