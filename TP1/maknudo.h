#ifndef maknudo
#define maknudo
#include "funciones_display.c"
#include "funciones_importantes.c"
#include "funciones_de_testeo.c"

// -- FUNCIONES DISPLAY -- 
// Pone un array de ints en 0
void clear_array(int *array, size_t size_of_array);
// Pone espacio en pantalla
void espacio_pantalla();




// Devuelve si la apertura del archivo fue correcta
int archive_ok(FILE * fp);
// X
void skip_lines(FILE * fp);
// Devuelve la diferencia desde un año hasta otro
unsigned int calcular_distancia_anio(int desde, int hasta);

// -- FUNCIONES DE MANEJO DE STRINGS -- 

//puntero_ultimo_char:Recibe el puntero a una cadena, lo recorre hasta encontrar el ultimo caracter de la cadena(notese que es el ultimo caracter y no la ultima letra lo que se busca)

char *puntero_ultimo_char(char *palabra);

// cantidad_caracteres: devuelve un entero que contiene el número de cantidad de caracteres, incluyendo el byte nulo.
unsigned int cantidad_de_caracteres(char *string);

// eliminar_ultimo_char: Crea copia del string pasado como argumento, lo modifica de manera tal que el ultimo caracter(anterior al nulo) es descartado.
//Devuelve puntero a char donde se almacena el string modificado.
char *eliminar_ultimo_char(char *palabra);
char *pointer_last_letter(char *string);


// Verifica si lo ingresado es un numero y luego el salto de linea. Retorna 1 de haber algun error. retorna 0 si todo es correcto.

int ingreso_numero(int *direccion_donde_se_guarda_la_entrada, char *guardado_de_espacio);
#endif
