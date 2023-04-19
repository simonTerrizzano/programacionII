#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "DataEntry.c"
#include "tipo_elemento.c"
#include "listas.h"
#define CANTIDAD_CAR 101
#define TERMINOS 5



typedef struct
{
   int  cota_inf; // cota inferior del intervalo
   int  cota_sup; // cota superior del intervalo

} t_intervalo;



/* comprobar_termino: se encarga de detectar que el termino a almacenar no contenga errores, esto es, detectar que:
> No haya espacios entre numeros/variables
> Que no se detecta mas de una variable o distinta a la ya establecida
> Al detectar el signo de exponente "^" que lo continue un digito y que esto ultimo signifique el fin del termino.

return: retorna 1 si se detectaron errores, 0 si no se detectaron errores.
 */
int comprobar_termino(char *ptr_termino, char *var, bool *VARSET);
void ingresar_termino(char *polinomio, char *letra_variable, bool *VARSET, bool *comando_salir_detectado);
bool operador_valido(char operador);


double calcular_monomio(int coeficiente, int exponente, double x);
double calcular_polinomio(Lista lista_exponentes, Lista lista_coeficientes, double x);
Lista calcular_outputs(Lista lista_exponentes, Lista lista_coeficientes, t_intervalo intervalo, double salto);
int main()
{
    double resultados_arr[100];
    double diferencia_inputs;
    char salto_linea;
    t_intervalo intervalo;
    int clave;
    int coeficiente, exponente;
    Lista lista_coeficientes; // lista con los coeficientes
    lista_coeficientes = l_crear();
    Lista lista_exponentes;
    lista_exponentes = l_crear();
    Lista lista_resultados;
    lista_resultados = l_crear();
    TipoElemento te;
    TipoElemento te_exp;
    Iterador iter;
    Iterador iter_exp;
    Iterador iter_resultados;
    TipoElemento te_result;
    char letra_variable; // guarda que letra sera la variable
    bool VARSET = false; // guarda si ya se detecto el ingreso de una variable
    bool comando_salir_detectado = false;
    bool encontrada_x;
    char polinomio[TERMINOS][CANTIDAD_CAR];
    int  coeficientes[TERMINOS] = {0};
    int exponentes[TERMINOS] = {0};
    int *ptr_coeficientes;
    int *ptr_exponentes;
    ptr_coeficientes = &coeficientes[0];
    ptr_exponentes = &exponentes[0];
	//char *ptr_polinomio = &polinomio[0];
	// mientras la cantidad de terminos no supere a 5 o no se haya llamado a exit
    // pedira ingreso de terminos y operandos
    printf("\nIngreso de terminos, porfavor ingrese los terminos del polinomio\n");
    for(int i = 0; i < TERMINOS && (comando_salir_detectado == false); i++)
    {

	printf("\nIngrese el termino(%d) (Indique explicitamente el exponente de la variable y el coeficiente)\n ", i+1);
	ingresar_termino(&polinomio[i][0], &letra_variable, &VARSET, &comando_salir_detectado);
	
	
    }
    //printf("monomio: %f", calcular_monomio(2, 2, 2));
    /*
     mostrar polinomio
    for(int i = 0; i < TERMINOS; i++)
    {
	for(int j = 0; polinomio[i][j] != '\0'; j++)
	{
	    
	    printf("%c", polinomio[i][j]);
	    
	}   
	
    }*/

    // guarda los exponentes
    for(int i = 0; i < TERMINOS; i++)
    {
	for(int j = 0; j < CANTIDAD_CAR; j++)
	{
	    if((polinomio[i][j] == '^'))
	    {
		exponente = polinomio[i][j+1] - '0';
		exponentes[i] = exponente;
		
	    }
	    
	}
    }

    
    // guarda los coeficientes
    for(int i = 0; i < TERMINOS; i++)
    {
	coeficiente = atoi(polinomio[i]);
	coeficientes[i] = coeficiente;
    }

    for(int i = 0; i < TERMINOS; i++)
    {
	clave = (random() % 500) + 1;
	te = te_crear_con_valor(clave, ptr_coeficientes);
	te_exp = te_crear_con_valor(clave, ptr_exponentes);
	ptr_coeficientes++;
	ptr_exponentes++;
	l_agregar(lista_coeficientes, te);
	l_agregar(lista_exponentes, te_exp);
    }

    //iter = iterador(lista_coeficientes);
    /*
    while(hay_siguiente(iter))
    {
	
	te = siguiente(iter);
	printf("\nClave: %d\tCoeficiente: %d", te->clave, *(int*)te->valor); 

    }

    iter_exp = iterador(lista_exponentes);
    while(hay_siguiente(iter_exp))
    {
	te_exp = siguiente(iter_exp);
	printf("\nClave: %d\tCoeficiente: %d", te_exp->clave, *(int*)te_exp->valor); 


	}*/
    
    int cota_sup, cota_inf;
    float dif_in;
    printf("\nPorfavor ingrese un intervalo, para calcular los valores en el polinomio\n");
    printf("\nCota inferior: ");
    scanf("%d", &cota_inf);
    printf("\nCota superior: ");
    scanf("%d", &cota_sup);
    printf("\nIngrese el salto entre valores de x en el intervalor: ");
    scanf("%f", &dif_in);
    printf("%d %f", cota_inf,dif_in);
    double epsilon;
    bool exceso = false;
    int rslt = 0;
    double *ptr_resultados;
    ptr_resultados = &resultados_arr[0];
    //double resultado;
    for(int i = 0; i < 100; i++)
    {
	epsilon = cota_inf + dif_in;
	//printf("\nepsilon %f", epsilon);
	clave = random() % 500 + 1;
	*(ptr_resultados+i) = calcular_polinomio(lista_exponentes, lista_coeficientes, epsilon+(dif_in*i));
	te_result = te_crear_con_valor(clave, ptr_resultados+i);
	l_agregar(lista_resultados, te_result);
    }

    iter_resultados = iterador(lista_resultados);
    while(hay_siguiente(iter_resultados))
    {
	te = siguiente(iter_resultados);
	printf("\nClave:%d\tResultado: %f", te->clave, *(double*)te->valor);
	
    }
    





    /* while(hay_siguiente(iter_resultados))
    {
	te_result = siguiente(iter_resultados);
	printf("\nclave: %d\tvalor: %f", te_result->clave, *(double*)te->valor);
	
	}*/
    
    free(lista_coeficientes);
    free(lista_exponentes);
    free(iter);
    free(iter_exp);
    free(lista_resultados);

    

  
    
}


void ingresar_termino(char *polinomio, char *letra_variable, bool *VARSET, bool *comando_salir_detectado)
{
    bool quit = false;
    char operador;
    bool operador_esvalido = false;
    int todo_ok;
    char termino[100];
    ingreso_normalizado_string(termino, 100, comando_salir_detectado);
    todo_ok = comprobar_termino(termino, letra_variable, VARSET);
    while(*(comando_salir_detectado) == false && todo_ok == 1 )
    {
	printf("\nEl termino que usted está ingresando es invalido, porfavor ingrese un termino de manera correcta\n");
	ingreso_normalizado_string(termino,100,comando_salir_detectado);
	if(*(comando_salir_detectado) == false)
	{
	    todo_ok = comprobar_termino(termino, letra_variable, VARSET);
	}
    }

    if(*(comando_salir_detectado) == false)
    {
	printf("\nPorfavor ingrese operador o ingrese (q o Q) para finalizar: ");
	operador = getchar();
	getchar();
	if(operador == 'q' || operador == 'Q')
	{
	    quit = true;
	    termino[strlen(termino)+1] = '\0';

	}
	else
	{
	    operador_esvalido = operador_valido(operador);
	    while(operador_esvalido == false)
	    {
		printf("\nPorfavor ingrese un operador valido: ");
		operador = getchar();
		getchar();
		operador_esvalido = operador_valido(operador);
		
	    
	    }

	    for(int i = 0; i < 100; i++)
	    {
		if(termino[i] == '\0')
		{
		    termino[i] = operador;
		    termino[i+1] = '\0';
		    i = 100;
		}
	    }
	    
	}
    }

    if(*comando_salir_detectado == false)
    {
	//printf("\nse copiara %s", termino);
	strcpy(polinomio, termino);
	if(quit)
	{
	    *comando_salir_detectado = true;
	}
    }
}


int comprobar_termino(char *ptr_termino, char *var, bool *VARSET)
{
    const int ERROR = 1;
    bool digit = false; // se guarda si ya se ha leido por primera vez un digito
    bool variable_detected = false; // detecta si ya ha detectado el ingreso de una variable
    while(*(ptr_termino) != '\0')
    {
	 
	// si se lee un digito por primera vez
	if((isdigit(*(ptr_termino)) > 0) && digit==false)
	    digit=true; // establece que se ha leido ya uno.
	
	//si se lee un espacio luego de haber escrito el primer digito/variable
	if(isblank(*(ptr_termino)) > 0 && (digit == true || variable_detected == true))
	{
	    printf("\nError no se permiten espacios entre numeros o variables");
	    return ERROR;
	}  

	// si se detecta una letra(variable) y no se habia leido todavia ninguna  
	if(isalpha(*(ptr_termino)) && variable_detected == false)
	{
	 
	    // si ya se ha asignado una letra como variable y la nueva letra detectada
	    // es distinta de letra como variable entonces ERROR.
	    if(*(VARSET) == true && (*(ptr_termino)) != *(var))
	    {
		printf("\nError la letra como variable ya se ha escogido anteriormente(%c)", *var);
		return ERROR;
	    }
	    
	    // si no se ha asignado todavia una variable y se detecta una letra, entonces
	    // asigna a esa letra como una variable
	    else if(*(VARSET) == false)
	    {
		
		*(var) = *(ptr_termino);
		*(VARSET) = true; // se establece entonces la letra que actuara como
		//variable
	    }
	    
	    variable_detected=true; // se establece que ya se ha detectado variable
	    
	}

	// si se detecta un signo para elevar y no es un digito, entonces error.
	if(*(ptr_termino) == '^' && !(isdigit(*(ptr_termino+1))) && (*(ptr_termino+2) != '\0'))
	{
	    printf("\nError, luego del signo de exponente debe ir natural entre el 0 y 9");
		return ERROR;
	}
	
	
	   ptr_termino++; // siguiente caracter
    
	   }

    return 0;
}

bool operador_valido(char operador)
{
    if((operador == '+') || (operador == '-') || (operador == '*') || (operador == '/'))
    {
	return true;
    }

    return false;
    
}

/*Lista calcular_outputs(Lista lista_exponentes, Lista lista_coeficientes, t_intervalo intervalo, double salto)
{

    int contador = 0;
    int clave;
    double *resultados = (double*) calloc(100, sizeof(double));
    Lista lista_resultados;
    lista_resultados = l_crear();
    bool detener;
    detener = false;
    double cota_inf;
    cota_inf = (double)intervalo.cota_inf;
    TipoElemento nodo_resultado;
    Iterador iter_coeficientes = iterador(lista_coeficientes);
    while(((int) cota_inf < intervalo.cota_sup) && contador < 100)
    {
	clave = (random() % 500) + 1;
	*(resultados+contador) = calcular_polinomio(lista_exponentes, lista_coeficientes,cota_inf);
	printf("\nCota inf: %f", cota_inf);
	printf("\nResultado: %f", *(resultados+contador));
	nodo_resultado = te_crear_con_valor(clave, resultados+contador);
	printf("\nAgregando resultado...");
	l_agregar(lista_resultados, nodo_resultado);
	printf("\nIncrementando x...");
	cota_inf= cota_inf + salto;
	contador++;
	    
    }
    
    return lista_resultados;

    }*/

double calcular_polinomio(Lista lista_exponentes, Lista lista_coeficientes, double x)
{
    double aux;
    double resultado = 0;
    Iterador iter_exp;
    TipoElemento te_coef;
    TipoElemento te_exp;
    Iterador iter_coef;
    iter_coef = iterador(lista_coeficientes);
    while(hay_siguiente(iter_coef))
    {
	//printf("\nCalculando polinomio...");
	te_coef = siguiente(iter_coef);
	//printf("\nClave:%d \tcoeficiente: %d", te_coef->clave, *(int*)te_coef->valor);
	te_exp  = l_buscar(lista_exponentes, te_coef->clave);
	//printf("\nClave:%d \tExponente: %d", te_exp->clave, *(int*)te_exp->valor);
	aux=calcular_monomio(*(int*)te_coef->valor, *(int*)te_exp->valor, x);
	resultado += aux;
    }

    
    return resultado;

}

double calcular_monomio(int coeficiente, int exponente, double x)
{
    double resultado = coeficiente * pow(x, exponente);
    // printf("\nEn monomio\nCoeficiente:%d\nExponente:%d\nx: %f", coeficiente,coeficiente, x);
    return resultado;
    
}
