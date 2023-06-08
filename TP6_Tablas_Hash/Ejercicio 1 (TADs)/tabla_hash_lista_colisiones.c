#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "tabla_hash.h"
#include "listas.h"

struct TipoRegistroTabla {
    TipoElemento tipo_elemento;
    bool ocupado;
    Lista lista_colisiones;
};

struct TablaHashRep {
    int (*hash_function)(int);
    int capacidad;
    struct TipoRegistroTabla *tabla;
};

TablaHash th_crear(int capacidad, int (*hash_function)(int)) {
    int i;
    TablaHash nueva_tabla_hash = (TablaHash) malloc(sizeof(struct TablaHashRep));
    nueva_tabla_hash->capacidad = capacidad;
    nueva_tabla_hash->hash_function = hash_function;

    nueva_tabla_hash->tabla = (struct TipoRegistroTabla *) malloc(capacidad * sizeof(struct TipoRegistroTabla));
    for (i = 0; i < capacidad; ++i) {
        nueva_tabla_hash->tabla[i].tipo_elemento = NULL;
        nueva_tabla_hash->tabla[i].ocupado = false;
        nueva_tabla_hash->tabla[i].lista_colisiones = l_crear();
    }
    return nueva_tabla_hash;
}

void th_insertar(TablaHash th, TipoElemento te) {
    int pos = th->hash_function(te->clave);
    struct TipoRegistroTabla *registroTabla = &th->tabla[pos];
    if (!registroTabla->ocupado) {
        registroTabla->tipo_elemento = te;
        registroTabla->ocupado = true;
    } else {
        if (registroTabla->tipo_elemento->clave != te->clave &&
                l_buscar(registroTabla->lista_colisiones, te->clave) == NULL) {
            l_agregar(registroTabla->lista_colisiones, te);
        }
    }
}

void th_eliminar(TablaHash th, int clave) {
    int pos = th->hash_function(clave);
    struct TipoRegistroTabla *registroTabla = &th->tabla[pos];
    if (registroTabla->ocupado) {
        if (registroTabla->tipo_elemento->clave == clave) {
            if (!l_es_vacia(registroTabla->lista_colisiones)) {
                registroTabla->tipo_elemento = l_recuperar(registroTabla->lista_colisiones, 1);
                l_eliminar(registroTabla->lista_colisiones, 1);
            } else {
                registroTabla->ocupado = false;
                registroTabla->tipo_elemento = NULL;
            }
        } else {
            l_borrar(registroTabla->lista_colisiones, clave);
        }
    }
}

TipoElemento th_recuperar(TablaHash th, int clave) {
    int pos = th->hash_function(clave);
    struct TipoRegistroTabla *registroTabla = &th->tabla[pos];
    if (registroTabla->ocupado) {
        if (registroTabla->tipo_elemento->clave == clave) {
            return registroTabla->tipo_elemento;
        } else {
            return l_buscar(registroTabla->lista_colisiones, clave);
        }
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
            Iterador iter = iterador(registroTabla.lista_colisiones);
            while (hay_siguiente(iter)) {
                TipoElemento e = siguiente(iter);
                printf(" -> %i ", e->clave);
            }
            free(iter);
            printf("\n");
        } else if (!soloOcupados) {
            printf("  tabla[%i] [ libre ]\n", i);
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
