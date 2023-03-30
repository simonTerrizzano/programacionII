#include "Ejercicio_1.h"

bool palindromo(char *palabra, int primero, int ultimo) {
    if(primero > ultimo) {
        return true;
    }
    else {
        if (palabra[primero] != palabra[ultimo]) {
            return false;
        }
        else {
        return palindromo(palabra, primero+1, ultimo-1);
        }
    }
}