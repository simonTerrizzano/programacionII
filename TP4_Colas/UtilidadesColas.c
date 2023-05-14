#include "colasApuntadores.c"
#include <time.h>
#include "DataEntry.c"

void crearCola(Cola cola);
void Randomizar(Cola cola,int num);
Cola copiarCola(Cola C);

void crearCola(Cola cola){
    bool * tempb;
    int temp,temp2,i=1;;
    TipoElemento X;
    printf("Crear la cola o randomizarla? : \n  1-randomizarla \n  2-crearla\n");
    temp = ingreso_normalizado_enteros(1,2,tempb);
    if(temp == 1){
        printf("\n Cuantas claves se le generaran a la cola?: \n");
        temp2 = ingreso_normalizado_enteros(1,99,tempb);
        Randomizar(cola,temp2);
    }
    else{
        printf("\n Cuantas claves se le agregara a la cola?: \n");
        temp2 = ingreso_normalizado_enteros(1,99,tempb);
        while (temp2 != 0)
        {
            printf("Clave del TipoElemento %d : ",i);
            X = te_crear(ingreso_normalizado_enteros(-1000,1000,tempb));
            c_encolar(cola,X);
            i=i+1;
            temp2 = temp2 - 1;
        }
    }
}

void Randomizar(Cola cola,int num){
    TipoElemento X;
    srand(time(0));
    for (int i = 0; i < num; i++)
    {
        X = te_crear(rand()%100 + 1);
        c_encolar(cola,X);
    }
}

Cola copiarCola(Cola C){
    Cola temp = c_crear();
    Cola CCopia = c_crear();
    TipoElemento X;
    while (!c_es_vacia(C))
    {
        X = c_desencolar(C);
        c_encolar(temp,X);
    }
    while (!c_es_vacia(temp))
    {
        X = c_desencolar(temp);
        c_encolar(CCopia,X);
        c_encolar(C,X);
    }
    return CCopia;
}
