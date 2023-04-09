#include "Ejercicio_9.h"

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
divisiblePor7 (110) => falso*/

bool divpor7(int numavalid){
    int dig;
    if (numavalid<70){//Caso base: Cuendo el numero sea menos que 70
        if (numavalid%7==0)//Si es divisible por 7
        {
            return true;
        }
        else{
            return false;
        }
    }
    /*SI es mayor a 70*/
    dig=numavalid%10;//Se aisla último digito
    numavalid=numavalid/10;//Se le saca el ultimo digito
    numavalid-=dig*2;//Se le resta el digito aislado por 2
    return divpor7(numavalid); //Llamada recursiva
}