#include "Ejercicio_2.h"

/*Dados dos números enteros m y n, construir una función recursiva que devuelva el
producto de ambos, calculando el mismo como sumas sucesivas. Esto es:
m*n=m+m+...+m, n veces.
Ejemplos:
producto(5, 3) => 15
producto (10, 4) => 40*/

int multiplicacion_recursiva(int m, int n)
{
    /*Solamente se esperan como entrada digitos enteros, por lo tanto debemos comprobar que las entradas
    sean digitos enteros
    Sabemos que si multiplicando y multiplicador son negativos será equivalente a que ambos sean positivos*/
    if(n<0 && m<0){
	n = abs(n);
	m = abs(m);
    }


    // CASOS BASE:
    // I) si n = 0, entonces la multiplicación será 0.
    // II) si n = 1, entonces la multiplicación será igual al multiplicando.
    
    if(n==0)
	return 0;
	else if(n==1)
	    return m;
    
    // Si alguno de los dos fuera negativo
    if((n < 0 || m < 0))
	return ((-abs(m)) - abs(multiplicacion_recursiva(m, abs(n) - 1)));

    return m + multiplicacion_recursiva(m, n-1);

}