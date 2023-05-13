#include "colasApuntadores.c"
#include <time.h>
#include "DataEntry.c"

void Randomizar(Cola cola,int num);
bool estaEnCola(Cola cola, TipoElemento X);
int colarse(Cola C, TipoElemento X, int pos);

void Randomizar(Cola cola,int num){
    TipoElemento X;
    srand(time(0));
    for (int i = 0; i < num; i++)
    {
        X = te_crear(rand()%100);
        c_encolar(cola,X);
    }
}

bool estaEnCola(Cola cola, TipoElemento X){
    Cola temp = c_crear();
    TipoElemento Y;
    bool encontrado = false;
    if (c_es_vacia(cola))
    {
        return encontrado;
    }
    
    while (!c_es_vacia(cola))
    {
        Y = c_desencolar(cola);
        c_encolar(temp, Y);
        if (Y->clave == X->clave)
        {
            encontrado = true;
        }
    }
    while (!c_es_vacia(temp))
    {
        c_encolar(cola,c_desencolar(temp));
    }
    return encontrado;
}

int colarse(Cola C, TipoElemento X, int pos){
    int contador=1;
    TipoElemento Y;
    Cola temp = c_crear();
    if (c_es_vacia(C) && pos == 1)
    {
        c_encolar(C,X);
        return 0;
    }
    else if (c_es_vacia(C) && (pos > 1 || pos < 1))
    {
        return -1;
    }
    else if (pos>c_longitud(C))
    {
        return -1;
    }
    else{
        while (contador != pos)
        {
            Y = c_desencolar(C);
            c_encolar(temp, Y);
            contador ++;
        }
        c_encolar(temp,X);
        while (!c_es_vacia(C))
        {
            Y = c_desencolar(C);
            c_encolar(temp, Y);
        }
        while (!c_es_vacia(temp))
        {
            Y=c_desencolar(temp);
            c_encolar(C,Y);
        }
        return 1;
    }
    
}

int contarElementos(Cola C);
Cola copiarCola(Cola C);
Cola invertirCola(Cola C);

Cola invertirCola(Cola C){
    Cola temp = c_crear();
    Cola tempRet = c_crear();
    TipoElemento X;
    while (!c_es_vacia(C))
    {
        X = c_desencolar(C);
        c_encolar(temp, X);
        c_encolar(tempRet, X);
    }
    while (!c_es_vacia(temp))
    {
        X = c_desencolar(temp);
        c_encolar(C,X);
    }
    return tempRet;
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

int contarElementos(Cola C){
    return c_longitud(C);
}

int main(int argc, char const *argv[])
{
    bool * tempb;
    int temp,temp2;
    TipoElemento X;
    Cola cola = c_crear();
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
            X = te_crear(ingreso_normalizado_enteros(-1000,1000,tempb));
            c_encolar(cola,X);
            temp2 = temp2 - 1;
        }
    }
    c_mostrar(cola);
    printf("\n");
    printf("La longitud de la cola es de %d",c_longitud(cola));
    printf("\n");
    X = te_crear(ingreso_normalizado_enteros(-1000,1000,tempb));
    printf("\n");
    if (estaEnCola(cola, X))
    {
        printf("Esta en cola");
    }
    else{
        printf("No esta en cola");
    }
    printf("\n");
    c_mostrar(cola);
    printf("\n");
    printf("Ingrese clave del Tipo elemento a insertar: ");
    X=te_crear(ingreso_normalizado_enteros(-1000,1000,tempb));
    printf("\n Ingrese la posicion a la cual insertarlo: ");
    int pos = ingreso_normalizado_enteros(-100,100,tempb);
    int resultado = colarse(cola,X,pos);
    if (resultado==1)
    {
        printf("\n Se inserto el tipoelemento en la posicion %d \n",pos);
        c_mostrar(cola);
    }
    else if (resultado == 0)
    {
        printf("\n Se inserto el tipoelemento en el inicio de la lista \n",pos);
        c_mostrar(cola);
    }
    else{
        printf("Error al insertar tipoelemento");
    }
    
    system("PAUSE");
    return 0;
}
