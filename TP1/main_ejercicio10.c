#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "ejercicio10_practica1.h"
#include "maknudo.h"
int es_cero(int numero);
int main()
{
    int todo_ok;
    int *ptr_array_fragmentos;
    bool executing;
    unsigned int numero_explosivo, bomba;
    char salto_linea;
    printf("\nBienvenido al punto 10 ;)\nSe debera ingresar un numero explosivo (entero positivo) y un numero bomba (tambien entero positivo). Si desea salir del programa escriba 0 en cualquiera de las casillas de entrada\n\n");
    executing = true;
    while(executing)
    {
	printf("\nIngrese el numero explosivo: ");
	while(!(todo_ok = ingreso_numero(&numero_explosivo, &salto_linea)))
	{
	    printf("\nPorfavor. El numero explosivo deber ser un entero positivo");
	     
	    
	}

	if(es_cero(numero_explosivo))
	{
	    executing = false;
	    continue;
	}

	
	else
	{
	    printf("\nIngrese el Bomba: ");
	    todo_ok = ingreso_numero(&bomba, &salto_linea);
	    if(es_cero(bomba))
	    {
		executing = false;
		continue;
	    }
	    
	    while(!todo_ok)
	    {
		printf("\nPorfavor. La bomba deber ser un entero positivo");
		todo_ok = ingreso_numero(&bomba, &salto_linea);
	    }

	    
	    if(es_cero(bomba))
	    {
		executing = false;
		continue;
	    }
	    else
	    {
		ptr_array_fragmentos = (int*) calloc(numero_explosivo, sizeof(int));
		punto_10(numero_explosivo, bomba, ptr_array_fragmentos);
		printf("[");
		for(int i = 0; i < numero_explosivo; i++)
		{
		    if((*(ptr_array_fragmentos+i)) == 0)
			i = numero_explosivo;
		    else
			printf("%d", *(ptr_array_fragmentos+i));
		    

		}
		printf("]");
		free(ptr_array_fragmentos);
		
	    }
	
	}
  
    }
      
   


}

int es_cero(int numero)
{
    if(numero == 0)
	return 1;
    else
	return 0;

}
