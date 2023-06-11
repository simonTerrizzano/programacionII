#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "tabla_hash.h"
#include "listas.h"

struct TipoRegistroTabla {
    TipoElemento tipo_elemento;
    bool ocupado;
};

struct TablaHashRep {
    int (*hash_function)(int);   //puntero a la funcion hash
    int capacidad;
    struct TipoRegistroTabla *tabla;
    struct TipoRegistroTabla *zona_overflow;
};

TablaHash th_crear(int capacidad, int (*hash_function)(int)) {
    int i;
    TablaHash nueva_tabla_hash = (TablaHash) malloc(sizeof(struct TablaHashRep));
    nueva_tabla_hash->capacidad = capacidad;
    nueva_tabla_hash->hash_function = hash_function;

    nueva_tabla_hash->tabla = (struct TipoRegistroTabla *) malloc(capacidad * sizeof(struct TipoRegistroTabla));
    nueva_tabla_hash->zona_overflow = (struct TipoRegistroTabla *) malloc(capacidad * sizeof(struct TipoRegistroTabla));
    for (i = 0; i < capacidad; ++i) {
        nueva_tabla_hash->tabla[i].tipo_elemento = NULL;
        nueva_tabla_hash->tabla[i].ocupado = false;
        nueva_tabla_hash->zona_overflow[i].tipo_elemento = NULL;
        nueva_tabla_hash->zona_overflow[i].ocupado = false;
    }

    return nueva_tabla_hash;
}

void th_insertar(TablaHash th, TipoElemento te) {
    int pos = th->hash_function(te->clave);
    struct TipoRegistroTabla *registroTabla = &th->tabla[pos];
    if (!registroTabla->ocupado) {
        registroTabla->tipo_elemento = te;
        registroTabla->ocupado = true;
    } else if (registroTabla->tipo_elemento->clave == te->clave) {
        // La clave ya existe, no se hace nada
    } else {
        int i = 0;
        bool encontreLugarVacio = false;
        while (i < th->capacidad && !encontreLugarVacio) {
            struct TipoRegistroTabla *registroZO = &th->zona_overflow[i];
            if (registroZO->ocupado) {
                if (registroZO->tipo_elemento->clave == te->clave) {
                    // La clave ya existe, no se hace nada
                    break;
                }
                i++;
            } else {
                encontreLugarVacio = true;
            }
            if (encontreLugarVacio) {
                registroZO->ocupado = true;
                registroZO->tipo_elemento = te;
            }
        }
    }
}

void th_eliminar(TablaHash th, int clave) {
    int pos = th->hash_function(clave);
    struct TipoRegistroTabla *registroTabla = &th->tabla[pos];
    // Si está en la tabla, lo libero
    if (registroTabla->ocupado && registroTabla->tipo_elemento->clave == clave) {
        registroTabla->ocupado = false;
        registroTabla->tipo_elemento = NULL;
        return;
    }

    // Si no está en la tabla, lo busco en la zona de overflow y, si está, lo libero
    int i = 0;
    while (i < th->capacidad) {
        struct TipoRegistroTabla *registroZO = &th->zona_overflow[i];
        if (registroZO->ocupado && registroZO->tipo_elemento->clave == clave) {
            registroZO->ocupado = false;
            registroZO->tipo_elemento = NULL;
            break;
        }
        i++;
    }
}

TipoElemento th_recuperar(TablaHash th, int clave) {
    int pos = th->hash_function(clave);
    struct TipoRegistroTabla *registroTabla = &th->tabla[pos];
    // Si está en la tabla, lo devuelvo
    if (registroTabla->ocupado && registroTabla->tipo_elemento->clave == clave) {
        return registroTabla->tipo_elemento;
    }

    // Si no está en la tabla, lo busco en la zona de overflow
    int i = 0;
    while (i < th->capacidad) {
        struct TipoRegistroTabla *registroZO = &th->zona_overflow[i];
        if (registroZO->ocupado && registroZO->tipo_elemento->clave == clave) {
            return registroTabla->tipo_elemento;
        }
        i++;
    }
    return NULL;
}

void th_mostrar_interna(TablaHash th, bool soloOcupados) {
    int i;
    printf("Contenido de la tabla hash:\n");
    for (i = 0; i < th->capacidad; i++) {
        struct TipoRegistroTabla registroTabla = th->tabla[i];
        if (registroTabla.ocupado) {
            printf("  tabla[%i] [ocupado] %i", i, registroTabla.tipo_elemento->clave);
            printf("\n");
        } else if (!soloOcupados) {
            printf("  tabla[%i] [ libre ]\n", i);
        }
    }
    printf(" Zona de overflow:\n");
    for (i = 0; i < th->capacidad; i++) {
        struct TipoRegistroTabla registroTabla = th->zona_overflow[i];
        if (registroTabla.ocupado) {
            printf("  zo[%i] [ocupado] %i", i, registroTabla.tipo_elemento->clave);
            printf("\n");
        } else if (!soloOcupados) {
            printf("  zo[%i] [ libre ]\n", i);
        }
    }
    printf("\n");
}

void th_mostrar(TablaHash th) {
    th_mostrar_interna(th, false);
}


void th_mostrar_solo_ocupados(TablaHash th) {
    th_mostrar_interna(th, true);
}
