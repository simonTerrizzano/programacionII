#ifndef CONVERSOR_BASE
#define CONVERSOR_BASE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilas.h"
#include "DataEntry.h"
// p_numero_a_base: Convierte un Numero_Decimal a cierta Base y lo muestra en pantalla.
// Base debe de ser un numero entre 2 y 16.
void p_numero_a_base(int Numero_Decimal, unsigned int Base);
#endif
