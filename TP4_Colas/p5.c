#include "UtilidadesColas.c"

Cola divisorParcial(Cola C);
Cola divisorTotal(Cola C);

Cola divisorParcial(Cola C){
    Cola temp,respaldo;
    Cola temp2 = c_crear();
    Cola resultado = c_crear();
    TipoElemento X,Y;
    int contador = 0;
    respaldo=copiarCola(C);
    while (!c_es_vacia(C))
    {
        X = c_desencolar(C);
        temp = copiarCola(respaldo);
        while (!c_es_vacia(temp))
        {
            Y = c_desencolar(temp);
            if(Y->clave % X->clave == 0){
                contador++;
            }
        }
        if (contador >= c_longitud(respaldo)/2)
        {
            c_encolar(resultado, X);
        }
        contador = 0;
    }
    while (!c_es_vacia(respaldo))
    {
        X = c_desencolar(respaldo);
        c_encolar(temp2,X);
    }
    while (!c_es_vacia(temp2))
    {
        X=c_desencolar(temp2);
        c_encolar(C,X);
    }
    return resultado;
}

Cola divisorTotal(Cola C){
    Cola temp,respaldo;
    Cola temp2 = c_crear();
    Cola resultado = c_crear();
    TipoElemento X,Y;
    int contador = 0;
    respaldo=copiarCola(C);
    while (!c_es_vacia(C))
    {
        X = c_desencolar(C);
        temp = copiarCola(respaldo);
        while (!c_es_vacia(temp))
        {
            Y = c_desencolar(temp);
            if(Y->clave % X->clave == 0){
                contador++;
            }
        }
        if (contador >= c_longitud(respaldo))
        {
            c_encolar(resultado, X);
        }
        contador = 0;
    }
    while (!c_es_vacia(respaldo))
    {
        X = c_desencolar(respaldo);
        c_encolar(temp2,X);
    }
    while (!c_es_vacia(temp2))
    {
        X=c_desencolar(temp2);
        c_encolar(C,X);
    }
    return resultado;
}

void Divisores(Cola C){
    if (c_es_vacia(C))
    {
        printf("La cola esta vacia, se cerrara el programa.");
        return;
    }
    
    Cola dparcial, dcompleto;
    dparcial = divisorParcial(C);
    if (c_es_vacia(dparcial))
    {
        printf("No hay divisores parciales en la cola");
    }
    else{
        printf("Los divisores parciales de la cola son: \n");
        c_mostrar(dparcial);
    }
    dcompleto = divisorTotal(C);
    if (c_es_vacia(dcompleto))
    {
        printf("No hay divisores totales en la cola");
    }
    else{
        printf("Los divisores totales de la cola son: \n");
        c_mostrar(dcompleto);
    }
    return;
}

int main(int argc, char const *argv[])
{
    TipoElemento X;
    Cola resultado;
    Cola cola = c_crear();
    printf("Se creara la cola \n");
    crearCola(cola);
    printf("La cola es la siguiente: \n");
    c_mostrar(cola);
    Divisores(cola);
    printF("La complejidad algoritmica de la funcion Divisores sin contar las funciones de los TAD de colas es de O(n^6)");  //Complejidad algoritmica
    system("PAUSE");
    return 0;
}
