#include "UtilidadesColas.c"
#include "limits.h"

void atenderVentanillas(int tiempo,Cola ventanilla1,Cola ventanilla2,Cola ventanilla3);
void atenderVentanillas(int tiempo,Cola ventanilla1,Cola ventanilla2,Cola ventanilla3){
    int contadorC1 = 1,contadorC2 = 1,contadorC3 = 1;
    bool Vvacia1 = false,Vvacia2 = false, Vvacia3 = false;
    TipoElemento X,Y,Z;
    X = c_desencolar(ventanilla1);
    Y = c_desencolar(ventanilla2);
    Z = c_desencolar(ventanilla3);
    while (!Vvacia1 || !Vvacia2 || !Vvacia3)
    {
        if (!Vvacia1)                                                                   //Si no es vacia la ventanilla 1, se restara el tiempo que le quede de atencion al cliente de la ventanilla 1
        {
            X->clave = X->clave - tiempo;
            if (X->clave<=0 && !Vvacia1)
            {
                printf("Cliente %d Cola 1\n",contadorC1);                               // Se imprimira el cliente atendido de la ventanilla 1, si es que no le queda mas tiempo de atencion
                contadorC1++;
                if (!c_es_vacia(ventanilla1))
                {
                    X=c_desencolar(ventanilla1);                                        // Si No es vacia la ventanilla 1 , se atendera el siguiente cliente. si lo es se cambiara Vvacia a true
                }
                else{
                    Vvacia1 = true;
                }
            }
        }
        if(!Vvacia2){                                                                   //Si no es vacia la ventanilla 2, se restara el tiempo que le quede de atencion al cliente de la ventanilla 2
            Y->clave = Y->clave - tiempo;
            if (Y->clave<=0 && !Vvacia2)
            {
                printf("Cliente %d Cola 2\n",contadorC2);                               // Se imprimira el cliente atendido de la ventanilla 2, si es que no le queda mas tiempo de atencion
                contadorC2++;
                if (!c_es_vacia(ventanilla2))
                {
                    Z=c_desencolar(ventanilla2);                                       // Si No es vacia la ventanilla 2 , se atendera el siguiente cliente. si lo es se cambiara Vvacia a true
                }
                else{
                    Vvacia2 = true;
                }
            }
        }
        if (!Vvacia3)                                                                   //Si no es vacia la ventanilla 3, se restara el tiempo que le quede de atencion al cliente de la ventanilla 3
        {
            Z->clave = Z->clave - tiempo;
            if (Z->clave<=0 && !Vvacia3)
            {
                printf("Cliente %d Cola 3\n",contadorC3);                               // Se imprimira el cliente atendido de la ventanilla 3, si es que no le queda mas tiempo de atencion
                contadorC3++;
                if (!c_es_vacia(ventanilla3))
                {
                    Z=c_desencolar(ventanilla3);                                       // Si No es vacia la ventanilla 3 , se atendera el siguiente cliente. si lo es se cambiara Vvacia a true
                }
                else{
                    Vvacia3 = true;
                }
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
    if (c_es_vacia(V1)||c_es_vacia(V2)||c_es_vacia(V3))                 //Se valida que no esten vacias las colas
    {
        printf("No se permiten colas vacias");
        system("PAUSE");
        return -1;
    }
    
    printf("Cuanto tiempo se dispondra para atender las ventanillas?: ");
    tiempo = ingreso_normalizado_enteros(1,100,temp);
    atenderVentanillas(tiempo,V1,V2,V3);
    system("PAUSE");
    return 0;
}

