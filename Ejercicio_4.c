#include "Ejercicio_4.h"

/*Dados los números enteros m y n, construir una función recursiva que devuelva el
cociente de ambos, calculando el mismo mediante restas sucesivas. Se deberá tener
en cuenta que en el caso de que la división no sea exacta, se devolverán hasta 4 cifras
decimales (si es necesario).
Ejemplos:
division (10,2) => 5
division (22,3) => 7,3333*/

float division(int m, int n, int precision){
   
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

float calcular_parte_decimal(int m, int n, int precision){
    // Alpha: contiene la cantidad de veces que se debera multiplicar a m para que n pueda restarlo.
    int Alpha;
    
    Alpha = how_many_times(m,n);

    m = m * recursive_power(10, Alpha);

    return (division(m,n, precision-1) / (recursive_power(10, Alpha)));

}


int how_many_times(int m, int n){
    m = m * 10;
    if(m < n)
	return 1 + how_many_times(m, n);
    else
	return 1;


}

int recursive_power(int m, int k){
    if(k == 1)
	return m;
 
    else if(k == 0)
	return 1;

    return m * recursive_power(m,k-1);


}