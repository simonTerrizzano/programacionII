#include "Ejercicio_10.h"

void explosivo(int N, int B){

    if (N<=B)
    {
        printf(" %d ",N);
    }
    else{
        explosivo((N/B),B);
        explosivo(N-(N/B),B);

    }
}