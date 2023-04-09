#include "Ejercicio_4.h"

/*Dados los números enteros m y n, construir una función recursiva que devuelva el
cociente de ambos, calculando el mismo mediante restas sucesivas. Se deberá tener
en cuenta que en el caso de que la división no sea exacta, se devolverán hasta 4 cifras
decimales (si es necesario).
Ejemplos:
division (10,2) => 5
division (22,3) => 7,3333*/

// float_division: recibe enteros positivos m,n y precision. Donde n es distinto de 0. y precision >= 1.
// retorna: un numero k (real) donde k al multiplicarlo por n me da un numero igual(o muy cercano) a m. 
// m = n*k --> m/n = k
// NOTA 1: La funcion tiene como dominio enteros positivos. Si m o n fuera negativo(y no ambos), entonces al numero devuelto se le agrega signo negativo. 
// si ambos son negativos entonces el signo queda de igual manera positivo.
// NOTA 2: En este ejercicio la precision es de 4.
float division(unsigned int m, unsigned int n, unsigned int precision){
   
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
// calcular_parte_decimal: recibe enteros positivos m, n y precision. 
// retorna: el valor decimal correspondiente de la division.
float calcular_parte_decimal(unsigned int m, unsigned int n, unsigned int precision){
    // Alpha: contiene la cantidad de veces que se debera multiplicar a m para que n pueda restarlo.
    int Alpha;
    Alpha = how_many_times(m,n);
    // m es escalador x10 la cantidad de veces para que pueda realizarse la resta.
    m = m * recursive_power(10, Alpha);
    // se llama a division para que haga el calculo. Y se corre la coma <<a la izquierda>> la cantidad de veces que se ha corrido <<a la derecha>> para
    // obtener el numero correspondiente.
    return (division(m,n, precision-1) / (recursive_power(10, Alpha)));

}

// how_many_times: Recibe como argumento dos numeros enteros positivos, m y n. 
// Retorno: la funcion devolvera cuantas veces se debe de escalar x10 el numero m para que este resulte mayor o igual a n.
// nota: partimos de la premisa de que m es menor que n. 

int how_many_times(unsigned int m, unsigned int n){
    m = m * 10;
    if(m < n)
	return 1 + how_many_times(m, n);
    else
	return 1;


}
// recursive_power: recibe un entero m y otro k.
// retorno: devuelve m a la potencia k.
int recursive_power(int m, int k){
    if(k == 1)
	return m;
 
    else if(k == 0)
	return 1;

    return m * recursive_power(m,k-1);


}
