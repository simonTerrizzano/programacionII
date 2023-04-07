#include "DataEntry.h"


int ingreso_normalizado_enteros_positivos(int limite_inferior, int limite_superior){
    /*Esta función recibe un limite inferior y un limite superior 
    y devuelve el ingreso realizado solo si está entre esos limites*/
    char ingreso[11];
    int ingreso_normalizado;
    bool fin = false;
    char * ptr;
    while (!fin)
    {
        printf("\nIngrese un número (Número entero positivo entre %i y %i):\n",limite_inferior,limite_superior);
        fgets(ingreso,10,stdin);
        fflush(stdin);
        quitasalto(ingreso);

        ingreso_normalizado=strtol(ingreso, &ptr, 10);//Convierte el ingreso en char a un int en base 10


        if (cadenatododigito(ingreso)!=1){//Comprueba si el ingreso es un digito
            printf("\nError: Por favor solo ingrese números enteros positivos.\n");
        }
        else if (ingreso_normalizado>limite_superior)//Comprueba limite superior
        {
            printf("\nError: Ingrese un numero menor que %i.\n",limite_superior);

        }
        else if (ingreso_normalizado<limite_inferior){//Comprueba limite inferior
            printf("\nError: Ingrese un numero mayor que %i.\n",limite_inferior);
        }
        else//Si el ingreso está dentro del rango sale del bucle
        {
            fin=true;
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

int cadenatododigito(char* cadena){
    int res;
    for (int i = 0; cadena[i]; i++){
        if (isdigit(cadena[i])!=1)
        {
            return 0;
        } 
    }
    return 1;
}