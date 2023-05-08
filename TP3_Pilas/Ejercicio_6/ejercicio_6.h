#ifndef ejercicio_6
#define ejercicio_6
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "C:\Users\PC\Documents\ProgramacionII\programacionII\programacionII\TP3_Pilas\Implementaciones_TAD_Pilas\pilas.h"
#include "C:\Users\PC\Documents\ProgramacionII\programacionII\programacionII\DataEntry\DataEntry.h"
#include "C:\Users\PC\Documents\ProgramacionII\programacionII\programacionII\TP3_Pilas\Implementaciones_TAD_Pilas\funcionalidades_extra_pila.h"


Pila p_eliminar_ocurrencias_recursivo(Pila p_src, int clave_buscada);
void p_proc_el_recur(Pila p_src, Pila p_modf, int clave_buscada);
Pila p_eliminar_ocurrencias_iter(Pila p_src, int clave);
#endif