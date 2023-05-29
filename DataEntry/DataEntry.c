#include "DataEntry.h"

void ingreso_normalizado_string(char cadena[100], int limite_superior){
    /*Función que recibe una cadena a modificar 
    por ingreso de teclado y un limite en el largo que se quiere procesar*/
 
    int check=0;

    
    while (check!=1)
    {
        printf("Ingrese un string:");
        fgets(cadena,100,stdin);
        quitasalto(cadena);//Sacamis salto de linea agregado por fgets
        minus(cadena);//Normalizamos a minúscula

        if (strlen(cadena)>limite_superior)//Verificamos el largo
        {
            printf("El string debe tener menos de %i caracteres\n",limite_superior);
        }
        else{
            check=1;
        } 
    }
}


int ingreso_normalizado_enteros(int limite_inferior, int limite_superior){
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



void quitaespacios(char* cadena){
    int i,j;
    i=0;
    j=0;
    char * cadenaaux;
    while (cadena[i]!='\0') {
        if(cadena[i]!=' '){
            cadenaaux[j]=cadena[i];
            j++;
        }
        i++;
    } 
}
void quitasalto(char* cadena){
    int i=0;
    while (cadena[i]!='\0') {
    if(cadena[i]=='\n'){
        cadena[i]='\0';
    }
    i++;
    }
}

void minus(char* cadena){
    for (int i = 0;cadena[i]; i++)
    {
        cadena[i]=tolower(cadena[i]);
    }
    
}

void mayus(char* cadena){
    for (int i = 0;cadena[i]; i++)
    {
        cadena[i]=toupper(cadena[i]);
    }
    
}


int cadenatododigito(char* cadena){
    
    for (int i = 0; cadena[i] != '\0'; i++){

	if(*(cadena+0) == '-')
	    continue;

	if (!isdigit(cadena[i]))
        {
            return 0;
        } 
    }
    return 1;
}

bool esNeg(char* cadena){
    int control=0;
    int conguion=0;
    bool res=false;
    for (int i = 0; cadena[i]; i++){

        if(cadena[i]=='-'){
            conguion++;
        }
        if (i>=1)
        {
            if (isdigit(cadena[i])!=1)
            {
                control++;
            } 
        }
        
    }
    if (control==0 && conguion==1 && cadena[0]=='-')
    {
        res=true;
    }
    

    return res;
}

bool esFlotante(char* cadena){
    int control=0;
    int punto=0;
    bool res=false;
    for (int i = 0; cadena[i]; i++){

        if(cadena[i]=='.'){
            punto++;
        }
        if (isdigit(cadena[i])!=1){
                control++;
            } 
        }
    
    if (punto==1 && control==1 && cadena[0] != '.' && cadena[strlen(cadena)-1]!='.')
    {
        res=true;
    }
    
}

void Cargar_Arbol(ArbolBinarioBusqueda A, int cant, int rango){
    TipoElemento X;
    int n;
    int cont=0;
    int cant_elem;
    int cant_elem_act;
    int arreglo[200];
    memset(arreglo, 0, 200*sizeof(int));
    int i=0;
    while(cont<cant){
        srand(time(NULL)); 
	    n=rand() % rango;
        X= te_crear(n);
        cant_elem = abb_cantidad_elementos(A);
        cant_elem_act=cant_elem;
        if (!numeroyaencontrado(n,arreglo,i))
        {
            abb_insertar(A,X);
            arreglo[i]=n;
            i++;
        }
        
        cant_elem = abb_cantidad_elementos(A);
        if (cant_elem_act==cant_elem)
        {
            cont--;
        }
        
        cont++;
    }    
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

//Muestra el arbol a partir de un nodo (de ahi hacia abajo)
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

//Muestra el arbol a partir de un nodo (de ahi hacia abajo)
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
