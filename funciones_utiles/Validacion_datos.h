#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>


#ifndef Validacion_datos
#define Validacion_datos

//Prototipos de funciones
bool validarNumeroFloat(char* cadena);
bool validarEntero(char* cadena);
bool validarLetras(char* cadena);
char* pasarAMayuscula(char* cadena);
char* sacarEspacios(char* input);
char* invertirString(char* cadena);
bool validarLetrasYNumeros(char* cadena);
#endif

