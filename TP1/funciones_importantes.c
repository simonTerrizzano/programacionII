#include <stdlib.h>
#include <stdio.h>
 
// Se encarga de establecer en 0 a todos los items del array.
void clear_array(int *array, size_t size_of_array);
//void skip_lines(FILE *fp);

// Calculará la distancia desde cierto año, hasta otro año.
unsigned int calcular_distancia_anio(int desde, int hasta);

unsigned int calcular_distancia_anio(int d, int h)
{
    
    return h - d; 

}


void clear_array(int *array, size_t size_of_array)
{
    for(size_t i = 0; i < size_of_array; i++, array++)
    {
	*(array)=0;
    }
}

// salta una linea del archivo
/* void skip_lines(FILE *fp) */
/* { */
/*     fgets(fp, "%*[^\n]\n"); */

/* } */




// FUNCIONES DE MANEJO DE STRINGS

//Recibe el puntero a una cadena, lo recorre hasta encontrar el ultimo caracter de la cadena(notese que es el ultimo caracter y no la ultima letra lo que se busca)

char *puntero_ultimo_char(char *palabra)
{

    if((*palabra) != '\0')
    {
	//printf("\n%c\n", *palabra);
	puntero_ultimo_char(palabra+1);
	
    }
    else
    {
	return (palabra-1);
    }
    
}

char *pointer_last_letter(char *string)
{
    while((*string) != '\0')
    {
	string++;
    }

    return string-1;
}

unsigned int cantidad_de_caracteres(char *string)
{
    unsigned int contador_car = 0;
    while( (*string) != '\0')
    {
	contador_car++;
	string++;
    }

    return contador_car+1;
}
 
char *eliminar_ultimo_char(char *palabra)
{
    size_t caracteres = strlen(palabra);
    char *palabra_truncada = (char*) malloc(sizeof(char) * caracteres);
    return strncpy(palabra_truncada, palabra, caracteres-1);
}

