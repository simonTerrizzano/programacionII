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

int* explocion(int num, int bomba, int* tamanio) {
    if (num <= bomba) {
        //Si el numero es menor o igual a la bomba, se aloja en memoria un array el cual se le asignara el numero al array y se incrementara el tamaño para luego alojar el array en el cual se alojaran todos los int que cumplen la condicion 
        int* arr = malloc(sizeof(int));
        *arr = num;
        *tamanio = 1;
        return arr;
    } else {
        //se crean dos contadores del tamaño del array que devolveran las llamadas recursivas
        int tamanio1, tamanio2;
        //se crean los arrays que tendran los numeros resultantes de la operacion
        int* arr1 = explocion(num / bomba, bomba, &tamanio1);
        int* arr2 = explocion(num - (num / bomba), bomba, &tamanio2);
        //se crea array principal
        int* arr = malloc((tamanio1 + tamanio2) * sizeof(int));
        // se asignaran los valores de los distintos arrays alojados en memoria al array "arr"
        for (int i = 0; i < tamanio1; i++) {
            arr[i] = arr1[i];
        }
        for (int i = 0; i < tamanio2; i++) {
            arr[tamanio1 + i] = arr2[i];
        }
        // se cambiara el tamaño al de los dos array creados por las llamadas recursivas
        *tamanio = tamanio1 + tamanio2;
        // liberar memoria
        free(arr1);
        free(arr2);
        return arr;
    }
}
