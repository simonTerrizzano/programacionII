#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void punto_10(int N, int B, int *ptr_array);


/* punto_10: Recibe un enteros positivos N y B; y una direccion de memoria en la que se contendra un entero.
   calculara cada fragmento y lo guardara en ptr_array.

   

   
*/
void punto_10(int N, int B, int *ptr_array)
{
    
    int n1, n2;
    // SI N es menor o igual a la bomba entonces no explota
    if(N <= B)
    {  *ptr_array = B;
    }
    else
    {
    // si N es mayor que B 
    // nuevos fragmentos 
    n1 = (int) N/B;
    //printf("\n%d", n1);
    n2 = N - n1;
    // se guarda el fragmento 
    *ptr_array = n1;
    punto_10(n2, B, ptr_array+1);
    }
}
