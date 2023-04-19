#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "DataEntry.c"
#include "listas.h"
#define CANTIDAD_CAR 101
#define TERMINOS 5


#ifndef ejercicio5
#define ejercicio5

/* comprobar_termino: se encarga de detectar que el termino a almacenar no contenga errores, esto es, detectar que:
> No haya espacios entre numeros/variables
> Que no se detecta mas de una variable o distinta a la ya establecida
> Al detectar el signo de exponente "^" que lo continue un digito y que esto ultimo signifique el fin del termino.

return: retorna 1 si se detectaron errores, 0 si no se detectaron errores.
 */
int comprobar_termino(char *ptr_termino, char *var, bool *VARSET);
void ingresar_termino(char *polinomio, char *letra_variable, bool *VARSET, bool *comando_salir_detectado);
bool operador_valido(char operador);


double calcular_monomio(int coeficiente, int exponente, double x);
double calcular_polinomio(Lista lista_exponentes, Lista lista_coeficientes, double x);
Lista calcular_outputs(Lista lista_exponentes, Lista lista_coeficientes, t_intervalo intervalo, double salto);
#endif
