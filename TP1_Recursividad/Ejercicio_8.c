#include "Ejercicio_8.h"

/*
Definir una función recursiva que dado un conjunto devuelva una lista con los
subconjuntos del mismo tales que la suma de los elementos de cada subconjunto
sumen una cantidad dada. Por ejemplo: Dado el conjunto A = {10, 3, 1, 7, 4, 2}. La
lista de los conjuntos que sumen 7 sería: R = [{3, 4}, {1, 4, 2}, {7}]
Ejemplos:
subconjuntosQueSumanN ({10, 3, 1, 7, 4, 2}, 7) => {{3, 4}, {1, 4, 2}, {7}}
subconjuntosQueSumanN ({10, 3, 1, 7, 4, 2}, 10) => {{10}, {3,7}, {3, 1, 4, 2}, {1, 7, 2}} 

*/

void encontrarSubconjuntosQueSumanN(int* arreglo, int n, int sumaRequerida, int* subconjunto, int tamSubconjunto, int pos, int sumaRequeridaOriginal, int paso) {
    // si el numero a llegar es mayor que 0 y si a la vez ya se imprimieron los valores del conjunto, se termina la funcion. (Validacion para entradas negativas) 
    if(sumaRequeridaOriginal<0){
        if (paso == 1 || sumaRequerida > sumaRequeridaOriginal*-1)
        {
            return;
        }
    }
    // Si se llega a la suma requerida, se imprime el subconjunto que se armo.
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
        // paso marca que ya se imprimio el subconjunto armado
        paso = 1;
        return;
    }
    // se llama la funcion recursiva en el caso de que el numero del arreglo[pos] sea negativo, al igual que al numero a llegar.
    // si este if no estuviera, en el caso de que hallan determinados numeros negativos, la funcion finalizaria sin llegar a imprimir los subconjuntos negativos
    if (arreglo[pos]<0 && sumaRequeridaOriginal<0 && paso==0)
    {
        subconjunto[tamSubconjunto] = arreglo[pos];
        // se llama la funcion recursiva para hallar si el subconjunto conformado por el numero arreglo[pos] y otro subconjunto conformado por el siguiente numero cumple la condicion de la funcion recursiva
        encontrarSubconjuntosQueSumanN(arreglo, n, sumaRequerida - arreglo[pos], subconjunto, tamSubconjunto + 1, pos + 1,sumaRequeridaOriginal,paso);
        encontrarSubconjuntosQueSumanN(arreglo, n, sumaRequerida, subconjunto, tamSubconjunto, pos + 1,sumaRequeridaOriginal,paso);
    }
    // si se pasa de 0 la resta de los subconjuntos o si no hay mas elementos para llegar a la condicion de la funcion recursiva finaliza la funcion
    if (pos >= n || sumaRequerida < 0) {
        return;
    }
    // se llama la funcion recursiva para numeros positivos
    else{
        subconjunto[tamSubconjunto] = arreglo[pos];
        // se llama la funcion recursiva para hallar si el subconjunto conformado por el numero arreglo[pos] y otro subconjunto conformado por el siguiente numero cumple la condicion
        encontrarSubconjuntosQueSumanN(arreglo, n, sumaRequerida - arreglo[pos], subconjunto, tamSubconjunto + 1, pos + 1,sumaRequeridaOriginal,paso);
        encontrarSubconjuntosQueSumanN(arreglo, n, sumaRequerida, subconjunto, tamSubconjunto, pos + 1,sumaRequeridaOriginal,paso);
    }
    
}
