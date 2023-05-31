#include "arbol_binario_busqueda.c"
#include "nodo.c"
#include "listas_apuntadores.c"
#include "DataEntry.c"

void pre_orden(NodoArbol N);
void in_orden(NodoArbol N);
void post_orden(NodoArbol N);

ArbolBinarioBusqueda crearArbol();

int ingreso_normalizado_enteros(int limite_inferior, int limite_superior, bool *ptr_salida);

int ingreso_normalizado_enteros(int limite_inferior, int limite_superior, bool *ptr_salida){
    /*Esta función recibe un limite inferior y un limite superior 
    y devuelve el ingreso realizado solo si está entre esos limites*/
    char ingreso[11];
    int ingreso_normalizado;
    bool fin = false;
    char * ptr;

    while (!fin)
    {   
        if (limite_inferior<0)
        {
            printf("\nIngrese un numero (Número entero entre %i y %i):\n",limite_inferior,limite_superior);
        }else
        {
            printf("\nIngrese un numero (Número entero positivo entre %i y %i):\n",limite_inferior,limite_superior);
        }
        
        fgets(ingreso,11,stdin);
        fflush(stdin);
        quitasalto(ingreso);

	if(!(strcmp(ingreso,"exit")))
	{
	    *ptr_salida = true;
	    return -1;
	    
	}
	else
	{
	    ingreso_normalizado=strtol(ingreso, &ptr, 10);//Convierte el ingreso en char a un int en base 10

	    if (limite_inferior<0)
	    {
		if (esNeg(ingreso)==true)
		{
                ingreso_normalizado=atoi(ingreso);
                if (ingreso_normalizado<limite_inferior){//Comprueba limite inferior
                    printf("\nError: Ingrese un numero mayor o igual que %i.\n",limite_inferior);
                }
                else//Si el ingreso está dentro del rango sale del bucle
                {
                    fin=true;
                }
            }else{
                if (cadenatododigito(ingreso)!=1){//Comprueba si el ingreso es un digito
		    printf("\nError: Por favor solo ingrese números enteros positivos.\n");
                }
                else if (ingreso_normalizado>limite_superior)//Comprueba limite superior
                {
                    printf("\nError: Ingrese un numero menor o igual que %i.\n",limite_superior);
                }
                else if (ingreso_normalizado<limite_inferior){//Comprueba limite inferior
                    printf("\nError: Ingrese un numero mayor o igual que %i.\n",limite_inferior);
                }
                else//Si el ingreso está dentro del rango sale del bucle
                {
                    fin=true;
                }
            }
        }else{
            if (cadenatododigito(ingreso)!=1){//Comprueba si el ingreso es un digito
                printf("\nError: Por favor solo ingrese numeros enteros positivos.\n");
            }
            else if (ingreso_normalizado>limite_superior)//Comprueba limite superior
            {
                printf("\nError: Ingrese un numero menor o igual que %i.\n",limite_superior);
            }
            else if (ingreso_normalizado<limite_inferior){//Comprueba limite inferior
                printf("\nError: Ingrese un numero mayor o igual que %i.\n",limite_inferior);
            }
            else//Si el ingreso está dentro del rango sale del bucle
            {
                fin=true;
            }
        }
	}
	printf("\n");
	return ingreso_normalizado;
    }
    
}

ArbolBinarioBusqueda crearArbol(){
    bool fin = false;bool * correcto;
    TipoElemento X;
    ArbolBinarioBusqueda arbol = abb_crear();
    int temp, contadoralt = 1, contadornodo;
    while (!fin)
    {
        printf("Ingrese 1 para finalizar:\n");
        if (ingreso_normalizado_enteros(0,1,correcto)==1)
        {
            fin = true;
        }
        else{
            printf("Ingrese valor del nodo\n");
            temp = ingreso_normalizado_enteros(-1000, 1000, correcto);
            X = te_crear(temp);
            abb_insertar(arbol,X);
        }
    }
    return arbol;
}


void pre_orden(NodoArbol N){
    TipoElemento x;
    if (N == NULL) {
        printf(".");
    }
    else {
        x = n_recuperar(N);
        printf(" %d", x->clave);
        pre_orden(n_hijoizquierdo(N));
        pre_orden(n_hijoderecho(N));
    }
}

void in_orden(NodoArbol N){
    TipoElemento x;
    if (N == NULL) {
        printf(".");
    }
    else {
        in_orden(n_hijoizquierdo(N));
        x = n_recuperar(N);
        printf(" %d", x->clave);
        in_orden(n_hijoderecho(N));
    }
}

void post_orden(NodoArbol N){
    TipoElemento x;
    if (N == NULL) {
        printf(".");
    }
    else {
        post_orden(n_hijoizquierdo(N));
        post_orden(n_hijoderecho(N));
        x = n_recuperar(N);
        printf(" %d", x->clave);
    }
}