#include "conjuntos.h"
#include "listas.h"
#include "tipo_elemento.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void randomizarConjunto(Conjunto* conjunto, int tamanio, int clavemax, int clavemin) {
    TipoElemento X;
    for (int i = 0; i < tamanio; i++) {
        X = te_crear(rand() % (clavemax - clavemin + 1) + clavemin);
        cto_agregar(*conjunto, X);
    }
}

