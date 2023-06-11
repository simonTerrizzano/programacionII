#include Ejercicio_4.h

void compararListas(Lista lista1, Lista lista2){
    if (l_es_vacia(lista1)||l_es_vacia(lista2))
    {
        printf("almenos una de las listas estan vacias, se cerrara el programa \n");
        system("PAUSE");
    }
    
    int clavesM1 = 0, clavesM2 = 0, contador1 = 0, contador2 = 0;
    bool end1 = false,end2 = false;
    Iterador it1 = iterador(lista1), it2;
    TipoElemento x, y;
    for (int i = 0; i < l_longitud(lista1); i++)
    {
        x = siguiente(it1);
        it2 = iterador(lista2);
        for (int j = 0; j < l_longitud(lista2); j++)
        {
            y = siguiente(it2);
            if (x->clave>y->clave)
            {
                clavesM1=clavesM1+1;
            }
            else if (x->clave<y->clave)
            {
                clavesM2=clavesM2+1;
            }
        }
    }
    
    printf("\n");
    if (clavesM1>clavesM2)
    {
        printf("La lista 1 es mayor que la lista 2, teniendo la lista 1 %d comparaciones mayores y la lista 2 %d comparaciones mayores",clavesM1,clavesM2);
    }
    else if (clavesM1<clavesM2)
    {
        printf("La lista 1 es menor que la lista 2, teniendo la lista 1 %d comparaciones mayores y la lista 2 %d comparaciones mayores",clavesM1,clavesM2);
    }
    else{
        printf("La lista 1 es de igual tamanio que la lista 2, teniendo la lista 1 %d comparaciones mayores y la lista 2 %d comparaciones mayores",clavesM1,clavesM2);
    }
    printf("\nsiendo x la longitud de la lista 1 y siendo y la longitud de la lista 2... \n");
    printf("La notacion asintotica de la funcion, sin contar las funciones que se llaman del tad, es de  o(y*x)\n");
    return;
}

void generarValoresLista(Lista lista, int num){
    for (int i = 0; i < num; i++)
    {
        TipoElemento x = te_crear(rand()%100);
        l_agregar(lista, x);
    }
    
}

int ingresoValorLista(Lista lista){
    bool fin = false;
    bool error = false;
    bool numero;
    TipoElemento x;
    printf("Ingrese 1 para ingresar numeros, o 2 para ingresar char");
    if (ingreso_normalizado_enteros(1,2,&fin)==1)
    {
        while (!fin)
        {
            printf("Ingresar 100001 para finalizar el ingreso");
            x = te_crear(ingreso_normalizado_enteros(-100000,100001,&error));
            if (error){return -1;}
            if(x->clave==100001){return 0;}
            l_agregar(lista, x);
            if (l_es_llena(lista)){return 1;}
        }
    }
    else{
        printf("Ingresar un numero para finalizar el ingreso\n");
        while (!fin)
        {
            char caracter;
            
            while (scanf(" %c", &caracter) == 1 && !isdigit(caracter)) {
            // Realizar operaciones con el caracter ingresado
                printf("Ingresó el caracter '%c'\n", caracter);
                x = te_crear(caracter);
                l_agregar(lista, x);
                if (l_es_llena(lista)){return 1;}
            }
            fin = true;
        }
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    Lista lista1, lista2;
    int temp;
    bool tempbool;
    lista1 = l_crear(lista1);
    lista2 = l_crear(lista2);
    printf("Generar valores al azar 1 \n Ingresar valores 2\n");
    temp = ingreso_normalizado_enteros(1,2,&tempbool);
    if (temp == 1){
        generarValoresLista(lista1,10);
        generarValoresLista(lista2,3);
        l_mostrarLista(lista1);
        l_mostrarLista(lista2);
        compararListas(lista1,lista2);
        system("PAUSE");
    }
    else{
        if (ingresoValorLista(lista1)!=0){
            return -1;
        }
        printf("\n");
        system("PAUSE");
        printf("\n");
        if (ingresoValorLista(lista2)!=0){
            return -1;
        }
        l_mostrarLista(lista1);
        l_mostrarLista(lista2);
        system("PAUSE");
        compararListas(lista1,lista2);
        system("PAUSE");
    }
    
    return 0;
}
