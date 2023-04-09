#include "Ejercicio_10.h"

/*Se dice que N es un número explosivo cuando éste explota en varios fragmentos más
chicos que él, dada una bomba B. Si se tiene que N es el número y B la bomba, tales
que N es mayor que B, se puede hacer que N explote en dos números N1 = N / B
(división entera) y N2 = N - (N / B).
Pero B es una bomba que produce una reacción en cadena, si N1 o N2 son mayores que
B, estos también explotan con la regla anterior, hasta que se encuentre que el número
no es mayor que B; entonces se dice que ya no se puede explotar el número.
Escribe una función recursiva que retorne una lista con los pedazos del número N,
dado que se tiene la bomba B.
Ejemplos:
Número: 10
Bomba: 3
explosion(10, 3) => [3 2 1 1 3]
Número: 20
Bomba: 5
explosion(20, 5) => [4 3 2 2 1 1 1 1 5]*/

void explosivo(int N, int B){

    if (N<=B)//Caso base si N es menos o igual que la bomba explota
    {
        printf(" %d ",N);
    }
    else{
        explosivo((N/B),B);//Exploción N1
        explosivo(N-(N/B),B);//Explosión N2

    }
}