#ifndef TIPO_ELEMENTO_H
#define TIPO_ELEMENTO_H

// TAD de datos
struct TipoElementoRep {
    int clave;
    void *valor;
};

typedef struct TipoElementoRep *TipoElemento;

TipoElemento te_crear(int clave);
TipoElemento te_crearConValor(int clave, void* valor);

#endif // TIPO_ELEMENTO_H

