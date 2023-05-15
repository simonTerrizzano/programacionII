#ifndef Ejercicio_2
#define Ejercicio_2

#include <time.h>

#include "C:\Users\PC\Documents\ProgramacionII\programacionII\TP4_Colas\Implementaciones_TAD_Colas\colas.h"
#include "C:\Users\PC\Documents\ProgramacionII\programacionII\DataEntry\DataEntry.h"

void Randomizar(Cola cola);
bool estaEnCola(Cola cola, TipoElemento X);
int colarse(Cola C, TipoElemento X, int pos);
int contarElementos(Cola C);
Cola copiarCola(Cola C);
Cola invertirCola(Cola C);

#endif