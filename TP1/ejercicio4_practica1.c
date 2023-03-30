#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PRECISION 4

/*Dados los números enteros m y n, construir una función recursiva que devuelva el
cociente de ambos, calculando el mismo mediante restas sucesivas. Se deberá tener
en cuenta que en el caso de que la división no sea exacta, se devolverán hasta 4 cifras
decimales (si es necesario).
Ejemplos:
division (10,2) => 5
division (22,3) => 7,3333*/

// division: Dado un numerador m(int), un denominador n(int), y la precision del decimal(int). Calculara la division por medio de restas sucesivas de forma recursiva. Devuelve un float.
float division(int m, int n, int precision);
// calcular_parte_decimal: Se encarga de hacer el calculo de la parte decimal. 
float calcular_parte_decimal(int m, int n, int precision);
// Calcula cuantas veces m debera ser multiplicado por 10 para poder comenzar a ser restado por n.
int how_many_times(int m, int n);
// De manera recursiva calculara m a la potencia k.
int recursive_power(int m, int k);
int main()
{
    int exec = 1;
    int numerator, denominator;
    while(exec)
    {
	printf("\nIngrese Numerador: ");
	scanf("%d", &numerator);
	printf("\n\nIngrese Denominador: ");
	scanf("%d", &denominator);
	if(denominator)
	    printf("\nResultado: %.4f", division(numerator, denominator, PRECISION));
	else
	    exec = 0;

    }
    
    
}


// CASOS BASE:
/*
  DIVISION = {
  contador_de_multiplicaciones = 0;
  SI (m == 0): return 0;
  SI (m == n): return 1;
  SI (m > n):
  return (m-n) + DIVISION(m-n, n);
  SI (m<n):
  return CALCULADOR_DECIMALES(m,n);



  CALCULADOR_DECIMALES:
  contador++;
  m = BIGGER(m,n);
  if (m-n > 0): contador++;
  CALCULADOR DECIMALES(m-n, n, 1);
  
  }

 */
float division(int m, int n, int precision)
{
   
    printf("\nNumerador : %d \tDenominador: %d \t Precision: %d\n", m, n, precision);
    // si el numerador es 0, devuelve 0;
    if(m == 0 || precision == 0)
	return 0;
    // si el numerador es mayor o igual al denominador procede con la division;
    else if(m >= n)
	return 1 + division(m-n, n, precision);
    // si el numerador es mas chico que el denominador, entonces se procede para el calculo decimal.
    else if(m < n)
	return calcular_parte_decimal(m,n, precision);
    
    
}

float calcular_parte_decimal(int m, int n, int precision)
{
    // Alpha: contiene la cantidad de veces que se debera multiplicar a m para que n pueda restarlo.
    int Alpha;
    
    Alpha = how_many_times(m,n);
    printf("\nAlpha: %d\n", Alpha);
    m = m * recursive_power(10, Alpha);
    printf("\nNew Numerator: %d\n", m);
    return (division(m,n, precision-1) / (recursive_power(10, Alpha)));

}


int how_many_times(int m, int n)
{
    m = m * 10;
    if(m < n)
	return 1 + how_many_times(m, n);
    else
	return 1;


}

int recursive_power(int m, int k)
{
    if(k == 1)
	return m;
 
    else if(k == 0)
	return 1;

    return m * recursive_power(m,k-1);


}
