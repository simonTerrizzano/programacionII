#include "UtilidadesColas.c"

void atenderVentanillas(int tiempo,Cola ventanilla1,Cola ventanilla2,Cola ventanilla3);

void atenderVentanillas(int tiempo,Cola ventanilla1,Cola ventanilla2,Cola ventanilla3){
    TipoElemento X,Y,Z;
    int contador1=1,contador2=1,contador3=1;
    bool terminado1=true,terminado2=true,terminado3=true;
    X=c_desencolar(ventanilla1);
    Y=c_desencolar(ventanilla2);
    Z=c_desencolar(ventanilla3);
    while (!c_es_vacia(ventanilla1) || !c_es_vacia(ventanilla2) || !c_es_vacia(ventanilla1))
    {
        if (X->clave<Y->clave && X->clave<Z->clave && (!c_es_vacia(ventanilla1)||!terminado1))
        {
            printf("Cliente %d, Cola 1 \n",contador1);
            X->clave = X->clave - tiempo;
            if (X->clave<=0)
            {
                if (!c_es_vacia(ventanilla1))
                {
                    X=c_desencolar(ventanilla1);
                    contador1++;
                }
            }
            else{
                terminado1 = false;
            }
        }
        else if (Y->clave<Z->clave && (!c_es_vacia(ventanilla2)||!terminado2))
        {
            printf("Cliente %d, Cola 2 \n",contador2);
            Y->clave = Y->clave - tiempo;
            if (Y->clave<=0)
            {
                if (!c_es_vacia(ventanilla2))
                {
                    X=c_desencolar(ventanilla2);
                    contador2++;
                }
            }
            else{
                terminado2 = false;
            }
        }
        else if (!c_es_vacia(ventanilla3)||!terminado3)
        {
            printf("Cliente %d, Cola 3 \n",contador3);
            Z->clave = Z->clave - tiempo;
            if (Z->clave<=0)
            {
                if (!c_es_vacia(ventanilla3))
                {
                    X=c_desencolar(ventanilla3);
                    contador3++;
                }
            }
            else{
                terminado3 = false;
            }
        }
    }
    return;
}

int main(int argc, char const *argv[])
{
    int tiempo = 0;
    bool * temp;
    Cola V1=c_crear(),V3=c_crear(),V2=c_crear();
    printf("Se creara la cola ventanilla 1 \n");
    crearCola(V1);
    printf("Se creara la cola ventanilla 2 \n");
    crearCola(V2);
    printf("Se creara la cola ventanilla 2 \n");
    crearCola(V3);
    printf("Ventanilla 1: ");
    c_mostrar(V1);
    printf("\n");
    printf("Ventanilla 2: ");
    c_mostrar(V2);
    printf("\n");
    printf("Ventanilla 3: ");
    c_mostrar(V3);
    printf("\n");
    printf("Cuanto tiempo se dispondra para atender las ventanillas?: ");
    tiempo = ingreso_normalizado_enteros(1,100,temp);
    atenderVentanillas(tiempo,V1,V2,V3);
    system("PAUSE");
    return 0;
}
