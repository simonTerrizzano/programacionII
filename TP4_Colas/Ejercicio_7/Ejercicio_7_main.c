#include "Ejercicio_7.c"

int main(void)
{
    int tiempo = 0;
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
    tiempo = ingreso_normalizado_enteros(1,100);
    atenderVentanillas(tiempo,V1,V2,V3);
    system("PAUSE");
    return 0;
}
