#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
//RESOLVER ERRORES
long int multiplicacion_recursiva(long int multiplicando, long int multiplicador);
int main()
{
    int m, n;
    int executing = true;
    while(executing)
    {

	printf("Ingrese multiplicando: ");
	scanf("%d", &m);
	getchar();
	printf("Ingrese multiplicador: ");
	scanf("%d", &n);
	getchar();
	if( m == 0 && n == 0)
	{
	    executing = false;
	    
	}
	else 
	{
	   printf("--->%d\n", multiplicacion_recursiva(m, n));
	}
	
	
    }
}

long int multiplicacion_recursiva(long int m, long int n)
{
    //Solamente se esperan como entrada digitos enteros, por lo tanto debemos comprobar que las entradas
    //sean digitos enteros
    // Sabemos que si multiplicando y multiplicador son negativos será equivalente a que ambos sean positivos
    if(n<0 && m<0)
    {
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
