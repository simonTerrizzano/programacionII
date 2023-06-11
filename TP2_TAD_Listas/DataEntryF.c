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

/*

>>Controlar que al leer la cadena siempre haya operadores entre términos, esto es, por ejemplo:
4x^2 3x no debe estar permitido. Lo correcto es 4x^2 ∗ 3x

>>Se restringirá el polinomio a una variable, por lo tanto, se deberá comprobar que en el
polinomio se encontró uno y solo un símbolo no numérico que represente a la variable. En
este caso restringiremos para que la variable sea representada por una letra del alfabeto.

>>Los exponentes solamente pueden ser números reales positivos. Sin embargo, se restringira a
solamente números naturales.

>> El grado maximo será 9
 */
int comprobar_polinomio(char *actual)
{
    bool buscando_operando;
    bool space;
    bool ultimo_leido_numero;
    buscando_operando = false;
    ultimo_leido_numero = false;
    unsigned char variable;
    variable = '\0'; // Se inicializa con un NULL para establecer que todavia no se ha encontrado variable.
   
    while(*(actual) != '\0')
    {
	if((*(actual)) == '+' || (*(actual)) == '-' || (*(actual) == '*') || (*(actual))
	   == '/')
	{
	    if(buscando_operando){return -1;}
	    else
	    {
		ultimo_leido_numero = false;
		buscando_operando = true;
	    }
	    
	}
	    
	//si lo leido es un número o una letra entonces, moviliza el puntero hasta que lo
	//leido sea un
	//espacio o un operador
	while(isalnum(actual))
	{
	    printf("\n%c es alphanumerico\n", *(actual));
	    if(ultimo_leido_numero == true)
		return -1;

	    if(*(actual) == '^')
	    {
		if(!isdigit(actual+1))
		{
		    return -1;
		}
	    }
   
	    if(isalpha(actual) && variable == '\0')
	    {
		variable = *(actual);
	    }
	    else if(isalpha(actual) && (*(actual) != variable))
	    {
		return -1;
		    
	    }
	    	    
	    actual = actual+1;	
	    
	}
	
	ultimo_leido_numero = true;
	
	actual = actual +1;

    }
}

