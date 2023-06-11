#include "Ejercicio_3.h"

bool multiploLista(Lista lista1, Lista lista2){
    Iterador ite1 = iterador(lista1);
    Iterador ite2 = iterador(lista2);
    int contador=0, contadorescalar=0,escalar=0;
    TipoElemento x,y;
    for (int i = 0; i < l_longitud(lista1); i++)
    {
        x=siguiente(ite1);
        y=siguiente(ite2);
        if (y->clave%x->clave == 0)
        {
            if (escalar == 0) {
                escalar = y->clave / x->clave;
                contadorescalar = contadorescalar + 1;
            } 
            else if (y->clave / x->clave != escalar) {
                contadorescalar = 0;
            }
            else{
                contadorescalar = contadorescalar + 1;
            }
        }
        else{
            printf("\n la lista 1 y 2 no son multiplos\n");
            return false;
        }
    }
    printf("La lista 1 y 2 son multiplos");
    if (contadorescalar == l_longitud(lista1))
    {
        printf("\n la lista 1 y 2 tienen un multiplo en comun, el %d\n", escalar);
    }
    return true;
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
void generarValoresLista(Lista lista, int num){
    for (int i = 0; i < num; i++)
    {
        TipoElemento x = te_crear(rand()%100);
        l_agregar(lista, x);
    }
    
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
        generarValoresLista(lista2,10);
        l_mostrarLista(lista1);
        l_mostrarLista(lista2);
        if (l_longitud(lista1)==l_longitud(lista2))
        {
            multiploLista(lista1,lista2);
            system("PAUSE");
        }
        else{
            printf("Las listas no tienen la misma longitud, el programa se cerrara\n");
            system("PAUSE");
            return -1;
        }
        
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
        if (l_longitud(lista1)==l_longitud(lista2))
        {
            multiploLista(lista1,lista2);
            system("PAUSE");
        }
        else{
            printf("Las listas no tienen la misma longitud, el programa se cerrara\n");
            system("PAUSE");
            return -1;
        }
    }
    return 0;
}

