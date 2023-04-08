#include "Ejercicio_5.h"

/*Generar un algoritmo recursivo que le ponga los “.” de los miles a un String de
números.
Ejemplos:
agregarSeparadorMiles (“123456”) => “123.456”
agregarSeparadorMiles (“12345678”) => “12.345.678” */

/*
  Caso Base: Si el (strlen(string) == 1) entonces devuelve un char y deja de llamar a la funcion.
  Dado un string de numeros, llamemoslo SNUM. Sea C(i-1) un caracter de SNUM, donde i es un numero natural.
  > C(1) denota el primer caracter de SNUM
  > C(max) denota el ultimo caracter no nulo de SNUM
  > Sea ptr un puntero a  caracter arbitrario de SNUM.
  > ptr apunta al caracter en posicion i.
  > Q denota la sumatoria de la cantidad de caracteres desde i+1 hasta max.
  > Si (Q mod 3 == 0) y el tamaño de strlen(SNUM) > 3 entonces se agregara un punto.
  EJEMPLO:
  > SNUM = 1200; stlen(4);
  ptr apunta a C(1). i = 1;
  Como la cantidad de caracteres restantes es 3, y
  (3 mod 3) == 0
  [strlen(SNUM) > 3]
  >> agrega un punto.
  fin.
 */
void agregar_separador_de_miles(char *str){
    printf("%c", *str);
    if(strlen(str) > 1)
    {
	if((strlen(str) > 3) && (((strlen(str) - 1) % 3) == 0))
	{
	    printf(".", *str);
	    agregar_separador_de_miles(str+1);
	}
	else
	    agregar_separador_de_miles(str+1);
    }   
}