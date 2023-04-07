#include<ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef DataEntry
#define DataEntry

int ingreso_normalizado_enteros_positivos(int limite_inferior, int limite_superior);
void quitaespacios(char* cadena);
void quitasalto(char* cadena);
int cadenatododigito(char* cadena);



#endif