#include "listas_cursores.c"
#include "tipo_elemento.c"
#include "DataEntry.c"

bool esSubLista(Lista lista1, Lista lista2);
int generarValoresLista(Lista lista, int num);
int ingresoValorLista(Lista lista);

bool esSubLista(Lista lista1, Lista lista2){
    if (l_es_vacia(lista1)||l_es_vacia(lista2))
    {
        printf("Las listas estan vacias, se cerrara el programa \n");
        system("PAUSE");
    }
    TipoElemento x;
    Iterador iter1,iter2;
    int contador = 0;
    iter1 = iterador(lista1);
    iter2 = iterador(lista2);
    for (int i = 1; i < l_longitud(lista2)+1; i++)
    {
        x = siguiente(iter2);
        if (l_buscar(lista1,x->clave)!=NULL)
        {
            contador = contador + 1;
        }
    }
    printf("\nsiendo x la longitud de la lista 1 y siendo y la longitud de la lista 2... \n");
    printf("La notacion asintotica de la funcion, es de o(x*y)\n");
    if (contador == l_longitud(lista2))
    {
        return true;
    }
    else{
        return false;
    }
}

int generarValoresLista(Lista lista, int num){
    bool fin=false;
    for (int i = 0; i < num; i++)
    {
        unsigned int seed;
        srand(seed);
        TipoElemento x = te_crear(rand()%10);
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
        if (esSubLista(lista1,lista2))
        {
        printf("\nEs sublista\n");
            system("PAUSE");
        }
        else{
            printf("\nNo es sublista\n");
            system("PAUSE");
        }
    }
    else{
        if (ingresoValorLista(lista1)!=0){
            return;
        }
        printf("\n");
        system("PAUSE");
        printf("\n");
        if (ingresoValorLista(lista2)!=0){
            return;
        }
        l_mostrarLista(lista1);
        l_mostrarLista(lista2);
        system("PAUSE");
        if (esSubLista(lista1,lista2))
        {
        printf("\nEs sublista\n");
            system("PAUSE");
        }
        else{
            printf("\nNo es sublista\n");
            system("PAUSE");
        }
    }
    
    return 0;
}

