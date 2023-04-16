#include "Ejercicio_3.h"

/*Generar un algoritmo recursivo que calcule el k-ésimo número de la serie de Fibonacci.
Ejemplos:
terminoSeridFibonacci (1) => 1
terminoSeridFibonacci (6) => 8 */

int fibonacci(int n){
    if (n <= 1) {//Caso base: mientras el número a evaluar sea mayor o igual que 1
        return 1;
    }
    return fibonacci(n-1) + fibonacci(n-2);//Llamada recursiva llamndo a los numeros anteriores de la serie
};