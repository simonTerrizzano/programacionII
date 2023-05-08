#ifndef punto6
#define punto6
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipo_elemento.h"
#include "DataEntry.h"
#include "ejercicio_2.h"


Pila p_eliminar_ocurrencias_recursivo(Pila p_src, int clave_buscada);
void p_proc_el_recur(Pila p_src, Pila p_modf, int clave_buscada);
Pila p_eliminar_ocurrencias_iter(Pila p_src, int clave);
#endif
