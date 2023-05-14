#include "UtilidadesColas.c"
#include "limits.h"

int valorMasCercano(int a, int b, int c, int Obj);
int valorMasCercano(int a, int b, int c, int Obj) {
    int distanciaA = abs(a - Obj);
    int distanciaB = abs(b - Obj);
    int distanciaC = abs(c - Obj);

    if (distanciaA <= distanciaB && distanciaA <= distanciaC) {
        return a;
    } else if (distanciaB <= distanciaC) {
        return b;
    } else {
        return c;
    }
}

void atenderVentanillas(int tiempo,Cola ventanilla1,Cola ventanilla2,Cola ventanilla3);
void atenderVentanillas(int tiempo,Cola ventanilla1,Cola ventanilla2,Cola ventanilla3){
    int terminoAtenderC1 = 1,terminoAtenderC2 = 1,terminoAtenderC3 = 1;
    int anteriorAtendido=0, atender;
    int rempl = 999999;
    int contadorC1 = 1,contadorC2 = 1,contadorC3 = 1;
    TipoElemento X,Y,Z;
    X = c_desencolar(ventanilla1);
    Y = c_desencolar(ventanilla2);
    Z = c_desencolar(ventanilla3);
    while ((X->clave!=0 || Y->clave != 0 || Z->clave != 0) && (!c_es_vacia(ventanilla1) || !c_es_vacia(ventanilla2) || !c_es_vacia(ventanilla3)))
    {
        if (anteriorAtendido == 0 && (!c_es_vacia(ventanilla1) &&!c_es_vacia(ventanilla2) && !c_es_vacia(ventanilla3)))
        {
            atender = valorMasCercano(X->clave, Y->clave, Z->clave, tiempo);
            if (X->clave == atender && X->clave != 0)
            {
                terminoAtenderC1=0;
                printf("Cliente %d , Cola 1 \n", contadorC1);
                X->clave=X->clave-tiempo;
                if (!c_es_vacia(ventanilla1) && X->clave<=0)
                {
                    X=c_desencolar(ventanilla1);
                    terminoAtenderC1=1;
                    contadorC1++;
                }
                anteriorAtendido = 1;
            }
            else if(Y->clave == atender && Y->clave != 0)
            {
                terminoAtenderC2=0;
                printf("Cliente %d , Cola 2 \n", contadorC2);
                Y->clave=Y->clave-tiempo;
                if (!c_es_vacia(ventanilla2) && Y->clave<=0)
                {
                    X=c_desencolar(ventanilla2);
                    terminoAtenderC2=1;
                    contadorC2++;
                }
                anteriorAtendido = 2;
            }
            else if(Z->clave == atender && Z->clave != 0)
            {
                terminoAtenderC3=0;
                printf("Cliente %d , Cola 3 \n", contadorC3);
                Z->clave=Z->clave-tiempo;
                if (!c_es_vacia(ventanilla3) && Z->clave<=0)
                {
                    X=c_desencolar(ventanilla3);
                    terminoAtenderC3=1;
                    contadorC3++;
                }
                anteriorAtendido = 3;
            }
        }
        else{
            if(anteriorAtendido == 1 && (!c_es_vacia(ventanilla1) && !c_es_vacia(ventanilla2) && !c_es_vacia(ventanilla3))){
                atender = valorMasCercano(rempl , Y->clave, Z->clave, tiempo);
                if(Y->clave == atender && Y->clave != 0)
                {
                    terminoAtenderC2=0;
                    printf("Cliente %d , Cola 2 \n", contadorC2);
                    Y->clave=Y->clave-tiempo;
                    if (!c_es_vacia(ventanilla2) && Y->clave<=0)
                    {
                        X=c_desencolar(ventanilla2);
                        terminoAtenderC2=1;
                        contadorC2++;
                    }
                    anteriorAtendido = 2;
                }
                else if(Z->clave == atender && Z->clave != 0)
                {
                    terminoAtenderC3=0;
                    printf("Cliente %d , Cola 3 \n", contadorC3);
                    Z->clave=Z->clave-tiempo;
                    if (!c_es_vacia(ventanilla3) && Z->clave<=0)
                    {
                        X=c_desencolar(ventanilla3);
                        terminoAtenderC3=1;
                        contadorC3++;
                    }
                    anteriorAtendido = 3;
                }
            }
            else if(anteriorAtendido == 2 && (!c_es_vacia(ventanilla1) && !c_es_vacia(ventanilla2) && !c_es_vacia(ventanilla3))){
                atender = valorMasCercano(X->clave,rempl , Z->clave, tiempo);
                if (X->clave == atender && X->clave != 0)
                {
                    terminoAtenderC1=0;
                    printf("Cliente %d , Cola 1 \n", contadorC1);
                    X->clave=X->clave-tiempo;
                    if (!c_es_vacia(ventanilla1) && X->clave<=0)
                    {
                        X=c_desencolar(ventanilla1);
                        terminoAtenderC1=1;
                        contadorC1++;
                    }
                    anteriorAtendido = 1;
                }
                else if(Z->clave == atender && Z->clave != 0)
                {
                    terminoAtenderC3=0;
                    printf("Cliente %d , Cola 3 \n", contadorC3);
                    Z->clave=Z->clave-tiempo;
                    if (!c_es_vacia(ventanilla3) && Z->clave<=0)
                    {
                        X=c_desencolar(ventanilla3);
                        terminoAtenderC3=1;
                        contadorC3++;
                    }
                    anteriorAtendido = 3;
                }
            }
            else if(anteriorAtendido == 3 && (!c_es_vacia(ventanilla1) && !c_es_vacia(ventanilla2) && !c_es_vacia(ventanilla3))){
                atender = valorMasCercano(X->clave, Y->clave, rempl , tiempo);
                if (X->clave == atender && X->clave != 0)
                {
                    terminoAtenderC1=0;
                    printf("Cliente %d , Cola 1 \n", contadorC1);
                    X->clave=X->clave-tiempo;
                    if (!c_es_vacia(ventanilla1) && X->clave<=0)
                    {
                        X=c_desencolar(ventanilla1);
                        terminoAtenderC1=1;
                        contadorC1++;
                    }
                    anteriorAtendido = 1;
                }
                else if(Y->clave == atender && Y->clave != 0)
                {
                    terminoAtenderC2=0;
                    printf("Cliente %d , Cola 2 \n", contadorC2);
                    Y->clave=Y->clave-tiempo;
                    if (!c_es_vacia(ventanilla2) && Y->clave<=0)
                    {
                        X=c_desencolar(ventanilla2);
                        terminoAtenderC2=1;
                        contadorC2++;
                    }
                    anteriorAtendido = 2;
                }
            }
            else{
                return;
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
