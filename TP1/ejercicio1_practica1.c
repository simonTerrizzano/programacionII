#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "maknudo.h"
#define buffer_size 256
bool palindromo(char *ptr_palabra);

int main()
{
    bool executing = 1;

    char *palabra;
    char buff[buffer_size];
    while(executing)
    {
	printf("\nIngrese una palabra: ");
	scanf("%s", &buff);
	printf("-> %s es palindromo", ((palindromo(buff)) ? "si":"no"));
	printf("\nQuiere continuar? [1/0]: ");
	scanf("%d", &executing);
    }

}

bool palindromo(char *ptr_palabra)
{
    size_t tamanio = strlen(ptr_palabra);
    // se crea un array donde se almacenará la nueva palabra modificada
    char palabra_reducida[tamanio+1];
    char *ptr_inferior = ptr_palabra;
    // se apunta al extremo superior de la palabra, o sea ultima letra
    char *ptr_superior = puntero_ultimo_char(ptr_palabra);
    printf("\nPrime letra: %c\tUltima letra: %c\n", *ptr_inferior, *ptr_superior);
    // si los dos puntero a extremo se encuentra en la misma ubicacion entonces es igual
    if(ptr_inferior == ptr_superior)
	return true;
    // si los dos extremos son distintos, ya no se trata de un palindromo
    else if(*ptr_inferior != *ptr_superior)
	return false;
    // si ambos tienen el mismo contenido
    else if (*ptr_inferior == *ptr_superior)
    {
	// y si ambos tuvieran 1 solo desplazamiento de diferencia
	ptr_inferior = ptr_inferior+1;
	if(ptr_inferior == ptr_superior)
	    return true;
	else
	    ptr_inferior = ptr_inferior - 1;
    }
    // se copia la palabra original en el nuevo vector que almacenara la palabra modificada
    strcpy(palabra_reducida, ptr_inferior);
    // se apunta a la ultima letra del vector, y se la pone como nuevo nulo
    ptr_superior = puntero_ultimo_char(palabra_reducida);
    printf("\nUltima letra de palabra reducida: %c", *ptr_superior);
    *ptr_superior = '\0';
    ptr_inferior = palabra_reducida;
    
    return palindromo(ptr_inferior+1);
}
