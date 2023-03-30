#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int TerminoSerieFibonacci(int indice_de_termino_de_serie_fibonacci);


int main()
{
    int n;
    int exc = 1;
    while(exc)
    {
	printf("\nIngrese el indice del termino de la Serie Fibonacci: ");
	scanf("%d", &n);
	if(n<0)
	    exc = 0;
	else
	    printf("\n---> Fib(%d) = %d", n, TerminoSerieFibonacci(n));

    }


}



int TerminoSerieFibonacci(int n)
{
    // Suponemos que empezamos el indice de n-1.
    if(n<=0)
	return 0;
    else if (n==1)
	return 1;
    return TerminoSerieFibonacci(n-1) + TerminoSerieFibonacci(n-2);

}
