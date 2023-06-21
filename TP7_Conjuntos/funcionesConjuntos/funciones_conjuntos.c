#include "../Ejercicio 1 (TADs)/conjuntos.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "DataEntry.c"

void randomizarConjunto(Conjunto* conjunto, int tamanio, int clavemax, int clavemin) {
    TipoElemento X;
    srand(time(NULL));
    for (int i = 0; i < tamanio; i++) {
        X = te_crear(rand() % (clavemax - clavemin + 1) + clavemin);
        cto_agregar(*conjunto, X);
    }
}

void crearConjunto(Conjunto* Conjunto){
    TipoElemento X;
    bool * res;
    printf("Tamanio del conjunto:\n");
    int tamanio = ingreso_normalizado_enteros(1, 1000,res);
    for (int i = 0; i < tamanio + 1; i++) {
        X = te_crear(ingreso_normalizado_enteros(-1000,1000,res));
        cto_agregar(*Conjunto, X);
    }
}
