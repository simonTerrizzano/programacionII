#include "ejercicio_6.h"

Lista comunPilaCola(Cola cola, Pila pila){//si la cola o la pila están vacias que retorne una lista vacia
    if (c_es_vacia(cola)||p_es_vacia(pila))
    {
        return NULL;
    }

    Lista LR=l_crear();

    Pila Paux=p_crear();

    Cola Caux=c_crear();
    Cola CBusqueda=c_crear();

    TipoElemento elemento;
    TipoElemento elemento_a_buscar;
    TipoElemento elemento_a_guardar;

    int indice=0;
    int contadorPila;
    int contadorCola=0;

    char arrpos[20][100];
    char posiciones[10];
    char posPila[3];
    char posCola[3];
    char sep[1];
    sep[0]=':';
    sep[1]='\0';


    while (c_es_vacia(cola)!=true)
    {
        elemento=c_desencolar(cola);
        c_encolar(Caux,elemento);
        c_encolar(CBusqueda,elemento);
    }
    while (c_es_vacia(Caux)!=true)
    {
        elemento=c_desencolar(Caux);
        c_encolar(cola,elemento);
    }
    

    while (c_es_vacia(CBusqueda)!=true)
    {
        elemento_a_buscar=c_desencolar(CBusqueda);
        contadorCola++;
        contadorPila=0;
        while (!p_es_vacia(pila))//hace una vuelta a la pila por cada elemento de la cola
        {
            contadorPila++;
            elemento=p_desapilar(pila);
            p_apilar(Paux,elemento);
            if (elemento_a_buscar->clave==elemento->clave)//si coiciden las claves castea las posiciones a string
                                                          //y los concatena con un ':' para darle el formato a mostrar
            {
                char posiciones[20];
                sprintf(posPila,"%d", contadorPila);
                sprintf(posCola,"%d", contadorCola);
                strcat(strcpy(posiciones, posPila), sep);
                strcat(strcpy(posiciones, posiciones), posCola);
                for (int i = 0;i < strlen(posiciones)-1; i++)
                {
                    arrpos[indice][i]=posiciones[i];//copia las posiciones a un arreglo que contiene todas las posiciones
                                                    //de los elementos que que coincidieron
                }
                
                elemento_a_guardar=te_crear_con_valor(elemento->clave, &arrpos[indice]);//guarda clave y posiciones
                indice++;

                l_agregar(LR,elemento_a_guardar);//agregamos el elemento a la lista resuultado
            }
        }

            
            
        while (!p_es_vacia(Paux))
        {
            elemento=p_desapilar(Paux);
            p_apilar(pila,elemento);
        }//devolvemos la pila
        
    }
    return LR;//retornamos la lista resultado
    
}

/*
Algoritmo de busqueda secuencial para encontrar un numero determinado en un arreglo
*/
bool numeroyaencontrado(int numero,int *arreglo,int n){
    for (int i = 0; i < n; i++)
    {
        if (numero==arreglo[i])
        {
            return true;
        }
    }
    return false;
}
