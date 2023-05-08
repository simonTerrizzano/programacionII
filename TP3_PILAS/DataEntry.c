#include "DataEntry.h"

void ingreso_normalizado_string(char cadena[100], int limite_superior, bool *ptr_salida){
    /*Función que recibe una cadena a modificar 
    por ingreso de teclado y un limite en el largo que se quiere procesar*/

    char cadena_aux[100];
    int check=0;

    
    while (check!=1)
    {
        printf("\nIN--->  ");
        fgets(cadena_aux,100,stdin);
        quitasalto(cadena_aux);//Sacamis salto de linea agregado por fgets
        minus(cadena_aux);//Normalizamos a minúscula
	if(detecta_comando_exit(cadena_aux, ptr_salida))
	{
	    check = 1;
	    
	}
	else
	{
	    if (strlen(cadena)>limite_superior)//Verificamos el largo
	    {
		printf("El string debe tener menos de %i caracteres\n",limite_superior);
	    }
	    else{
		strcpy(cadena, cadena_aux); // si sale todo bien , copiamos la cadena :)
		check=1;
	    } 
	}
    }
}


// ptr_salida -> pone en 1 el contenido de ptr_salida si se detecta que se ha ingresado como string <<exit>>
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
            printf("\nIN[%d;%d]---> ",limite_inferior,limite_superior);
        }else
        {
            printf("\nIN[%d;%d]---> ",limite_inferior,limite_superior);
        }
        
        fgets(ingreso,11,stdin);
        fflush(stdin);
        quitasalto(ingreso);
	if(!detecta_comando_exit(ingreso, ptr_salida))
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

	    printf("\n");
	    return ingreso_normalizado;
    
	}
	else
	{
	    printf("\n");
	    return -1;
	}
    }
    return -1;
}

bool ingreso_normalizado_onda_digital(char* onda){

    bool res;
    int cont=0;
    mayus(onda);

    for (int i = 0; onda[i]; i++)
    {
        if(onda[i]!='L' && onda[i]!='H'){
            cont++;
        }
    }
    if (cont>=1)
    {
        res=false;
    }else
    {
        res=true;
    }
    return res;
    
    
}
int detecta_comando_exit(char *ingreso, bool *ptr_salida)
{
	if(!(strcmp(ingreso,"exit")))
	{
	    *ptr_salida = true;
	    return 1;
	    
	}
	else
	{ return 0;}
}
void quitaespacios(char* cadena){
    int i,j;
    i=0;
    j=0;
    char *cadenaaux = malloc(sizeof(char)*(strlen(cadena)+1));
    while (cadena[i]!='\0') {
        if(cadena[i]!=' '){
            *(cadenaaux+j)=*(cadena+i);
            j++;
        }
        i++;
    }
    strcpy(cadena, cadenaaux);
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
    bool res;
    res=false;
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
    
    return res;
}

void comienza_ingreso()
{
    printf("\n---INGRESO DE DATOS---\n--> escriba exit para salir\n");
    
}

bool ingreso_clave_aleatoria()
{
    bool salida;
    int SELECCION;
    printf("\nSeleccione como se completaran las claves de los elementos\n1 - Aleatoria\n2 - Manual\n");
    SELECCION = ingreso_normalizado_enteros(1, 2, &salida);

    return (SELECCION == 1);
    
}




