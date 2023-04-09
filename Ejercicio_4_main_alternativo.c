#include "Ejercicio_4.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char salto_linea;
    int numerador, denominador;
    printf("--Numerador--");
    printf("\n\nIngrese un numerador: ");
    scanf("%d%c", &numerador, &salto_linea);

    printf("\n\n--Denominador--");
    printf("\nIngrese un denominador (distinto de 0. Porfa ;) ): ");
    scanf("%d%c", &denominador, &salto_linea);
    
    if(denominador==0)
    {
	printf("La division por 0 no esta definida. Porfavor intente con un numero distinto de 0\n\n");
	exit(EXIT_FAILURE);
    }
    
    // si uno u otro tiene signo negativo, pero no ambos, entonces es negativo
    if( (numerador < 0 || denominador < 0)  && !(denominador < 0 && numerador < 0) )
    {
	printf("\nResultado: -%.4f", division(abs(numerador), abs(denominador), PRECISION));
	
    }
    else
    {

	printf("\nNumerador:%d\tDenominador:%d", numerador, denominador);
	printf("\nResultado: %.4f", division(numerador, denominador, PRECISION));
    }
    
    

    printf("\n\n");

    exit(EXIT_SUCCESS);

    return 0;
}
