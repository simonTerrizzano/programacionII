#include "Ejercicio_8.h"

/*Escribir una función recursiva que implemente el método que se describe para saber si
un número es divisible por 7. Se separa la primera cifra de la derecha, se la multiplica
por 2, y se resta este producto de lo que queda a la izquierda y así sucesivamente,
hasta que el resultado obtenido sea un número menor a 70. El número original será
múltiplo de 7 si el resultado da cero o múltiplo de 7.
Ejemplos:
32291 -> 1x2=2.
3229 - 2 =
3227 -> 7x2=14.
322 - 14 =
308 -> 8x2=16
30 - 16 =
14 -> Múltiplo de 7
divisiblePor7 (32291) => verdadero
110 -> 0 x 2 = 0
11 – 0 =
11 -> No múltiplo de 7
divisiblePor7 (110) => falso */

void encontrarSubconjuntosQueSumanN(int* arreglo, int n, int sumaRequerida, int* subconjunto, int tamSubconjunto, int pos, int sumaRequeridaOriginal, int paso) {
    if(sumaRequeridaOriginal<0){
        if (paso == 1 || sumaRequerida > sumaRequeridaOriginal*-1)
        {
            return;
        }
    }
    if (sumaRequerida == 0) {
        for (int i = 0; i < tamSubconjunto; i++) {
            if (i == 0)
            {
                printf("{");
            }
            if(i < tamSubconjunto - 1){
                printf("%d,", subconjunto[i]);
            }
            else{
                printf("%d", subconjunto[i]);
            }
            if (i == tamSubconjunto-1)
            {
                printf("}");
            }
        }
        paso = 1;
        return;
    }
    if (arreglo[pos]<0 && sumaRequeridaOriginal<0 && paso==0)
    {
        subconjunto[tamSubconjunto] = arreglo[pos];
        encontrarSubconjuntosQueSumanN(arreglo, n, sumaRequerida - arreglo[pos], subconjunto, tamSubconjunto + 1, pos + 1,sumaRequeridaOriginal,paso);
        encontrarSubconjuntosQueSumanN(arreglo, n, sumaRequerida, subconjunto, tamSubconjunto, pos + 1,sumaRequeridaOriginal,paso);
    }
    if (pos >= n || sumaRequerida < 0) {
        return;
    }
    else{
        subconjunto[tamSubconjunto] = arreglo[pos];
        encontrarSubconjuntosQueSumanN(arreglo, n, sumaRequerida - arreglo[pos], subconjunto, tamSubconjunto + 1, pos + 1,sumaRequeridaOriginal,paso);
        encontrarSubconjuntosQueSumanN(arreglo, n, sumaRequerida, subconjunto, tamSubconjunto, pos + 1,sumaRequeridaOriginal,paso);
    }
    
}