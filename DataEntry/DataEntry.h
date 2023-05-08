#include<ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<math.h>

#ifndef DataEntry
#define DataEntry

int ingreso_normalizado_enteros(int limite_inferior, int limite_superior);
void ingreso_normalizado_string(char cadena[100], int limite_superior);
bool ingreso_normalizado_onda_digital(char* cadena);
void quitaespacios(char* cadena);
void quitasalto(char* cadena);
int cadenatododigito(char* cadena);
bool esNeg(char* cadena);
void minus(char* cadena);
void mayus(char* cadena);



#endif