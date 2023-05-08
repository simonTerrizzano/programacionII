#include "ejercicio_4.h"
#define MAX 100
void p_numero_a_base(int n, unsigned int b)
{
    //bool exit;
    int dividendo = abs(n);
    size_t cx;
    char string_num[MAX*2];
    char *ptr_string_num = &string_num[0];
    size_t offset = 0;
    Pila piladelphia = p_crear(); // donde se guardara el numero convertido
    int resto;
    TipoElemento numero;

    printf("\n(%d)[b:10] a ---> (x)[b:%d]", n, b);
    // se apilan todos los restos 
    while(dividendo > 0)
    {
	resto = dividendo % b;
        dividendo = dividendo / b;
	numero = te_crear(resto);
	p_apilar(piladelphia, numero);
    }

    if(n<0)
    {
	*(ptr_string_num) = '-';
	offset++;
    }
	
    //se muetra en pantalla el numero
    while(!p_es_vacia(piladelphia))
    {
	numero = p_desapilar(piladelphia);
	if(b==16 && numero->clave >= 10)
	{   
	    cx = snprintf(ptr_string_num+offset, MAX*2, "%c", (numero->clave+55));
	    offset += cx;
	}
	else
	{
	    cx = snprintf((ptr_string_num+offset), MAX*2, "%d", numero->clave);
	    offset += cx;
	}
    }
   
    printf("%d ----> %s", n, ((n==0) ? "0":string_num));
    
}