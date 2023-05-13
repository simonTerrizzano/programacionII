#include "UtilidadesColas.c"

Cola elementosNoRepetidos(Cola cola);

Cola elementosNoRepetidos(Cola cola){
    TipoElemento X, Y;
    int repeticiones = 0;
    Cola temp;
    Cola temp2 = c_crear();
    Cola respaldo;
    Cola resultado = c_crear();
    respaldo = copiarCola(cola);
    while (!c_es_vacia(cola))
    {
        X = c_desencolar(cola);
        temp = copiarCola(respaldo);
        while (!c_es_vacia(temp))
        {
            Y = c_desencolar(temp);
            if (X->clave == Y->clave)
            {
                repeticiones++;
            }
        }
        if (repeticiones == 1)
        {
            c_encolar(resultado,X);
        }
        repeticiones = 0;
    }
    while (!c_es_vacia(respaldo))
    {
        X = c_desencolar(respaldo);
        c_encolar(temp2,X);
    }
    while (!c_es_vacia(temp2))
    {
        X = c_desencolar(temp2);
        c_encolar(cola,X);
    }
    return resultado;
}

int main(int argc, char const *argv[])
{
    TipoElemento X;
    Cola resultado;
    Cola cola = c_crear();
    printf("Se creara la cola \n");
    crearCola(cola);
    resultado = elementosNoRepetidos(cola);
    printf("Cola original: \n");
    c_mostrar(cola);
    printf("\nCola de numeros no repetidos: \n");
    c_mostrar(resultado);
    system("PAUSE");
    return 0;
}
