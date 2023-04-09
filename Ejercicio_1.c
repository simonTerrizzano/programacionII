#include "Ejercicio_1.h"

/*Construir una función recursiva que retorne verdadero si una cadena de caracteres
pasada como parámetro es un palíndromo. Ej. “neuquen” ya que se lee igual de atrás
hacia adelante.
Ejemplos:
palindromo(“neuquen”) => verdadero
palindromo(“palindromo”) => falso */

bool palindromo(char *palabra, int primero, int ultimo) {
    if(primero > ultimo) {//Caso base: miestra los numeros a evaluar no sean el mismo
        return true;
    }
    else {
        if (palabra[primero] != palabra[ultimo]) {//Evaluar si son diferentes
            return false;
        }
        else {
        return palindromo(palabra, primero+1, ultimo-1);//Correr un caracter para adentro
        }
    }
}