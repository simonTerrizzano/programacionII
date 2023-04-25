

void p_devolver(Pila p_dest, Pila p_src)
{
    TipoElemento te_aux;
    while(p_es_vacia(p_src) == false)
    {
	te_aux = p_desapilar(p_src);
	p_apilar(p_dest, te_aux);
    }

}

void p_insertar(Pila pila, TipoElemento elemento_nuevo , unsigned int pos)
{

    TipoElemento elemento;
    Pila pila_auxiliar;
    pila_auxiliar = p_crear();
    while(p_es_vacia(pila) == false && pila->cantidad>=pos)
    {
	elemento = p_desapilar(pila);
	p_apilar(pila_auxiliar, elemento);
    }
    p_apilar(pila, elemento_nuevo);
    p_devolver(pila, pila_auxiliar);
}
