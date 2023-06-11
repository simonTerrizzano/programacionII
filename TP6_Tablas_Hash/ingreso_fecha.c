#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>



//            FUNCIONES DE VALIDACION
//=================================================
bool validarLetrasYNumeros(char* cadena)
{

    int i;
    bool esValido = false;

    for (i = 0; i < strlen(cadena); i++)
    {

        int codigoAscii = cadena[i];
        if ((codigoAscii>= 48 && codigoAscii <= 57) || (codigoAscii>= 97 && codigoAscii <= 122) || (codigoAscii >= 65 && codigoAscii <= 90) || codigoAscii == 32)
        {
            esValido = true;
        }
        else
        {   
            //Si al menos 1 digito no es una letra retorna input invalido
            return false;
        }

    }

        return esValido;


}

bool validarLetras(char* cadena)
{

    int i;
    bool esValido = false;

    for (i = 0; i < strlen(cadena); i++)
    {

        int codigoAscii = cadena[i];
        if ((codigoAscii>= 65 && codigoAscii <= 90) || (codigoAscii>= 97 && codigoAscii <= 122) || codigoAscii == 32)
        {
            esValido = true;
        }
        else
        {   
            //Si al menos 1 digito no es una letra retorna input invalido
            return false;
        }

    }

        return esValido;


}

bool validarEntero(char* cadena)
{
    int i;
    bool esNumero = false;
    int longitud = strlen(cadena);

    if (cadena[0] == '-') i = 1;
    else i = 0;

    for (i; i < longitud; i++)
    {
        //Valido que el input sea un NUMERO
        if (cadena[i] >= 48 && cadena[i] <=57)
        {
            if (cadena[i] != ' ') esNumero = true;
            else return false;
            
        }
        else return false;
    }

    return esNumero;
}


//=================================================

/*Se desea poder implementar una solución para encontrar de forma rápida los datos de
las personas que a una fecha determinada se presentaron a vacunar contra el COVID.
Es decir dada una fecha determinada debería obtener quienes se vacunaron. De cada
persona se guarda básicamente el DNI, Apellido y Nombre. Se debe además hacer una
pantalla de carga donde se pueda especificar la fecha y los datos de las personas que
se vacunaron en esa fecha.  */

struct Fecha
{
    int dia,mes,anio;
};


int functionHash(int fecha)
{
    return fecha % 30003;
}

bool verificarFecha(struct Fecha fecha)
{

    if (fecha.dia > 31 || fecha.dia < 1) return false;

    if (fecha.mes > 12 || fecha.mes < 1) return false;

    //Calculo si el anio es bisiesto o no
    double x = fecha.anio % 4;
    double y = fecha.anio % 100;
    double z = fecha.anio % 400;
    if (((fecha.anio % 4 == 0 && fecha.anio % 100 != 0) || (fecha.anio % 400 == 0)))
    {
        //printf("ANIO BISIESTO\n");
        //el año es bisiesto
        if (fecha.dia <= 29 && fecha.mes == 2)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        //printf("ANIO NO BISIESTO\n");
        //No es bisiesto.
        //printf("El anio no es bisiesto.\n");

        //Como el año no es bisiesto el 29 de febrero no existe.
        if (fecha.dia > 28 && fecha.mes == 2){
            return false;
        }else{
            return true;
        }
    }

    //Ahora analizo el resto de las fechas
    //MESES CON 31 DIAS
    switch (fecha.mes)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:

        if (fecha.dia <= 31)
        {
            return true;
        }
        else
        {
            return false;
        }  
    default:
        break;
    }


    //MESES CON 30 DIAS
    switch (fecha.mes)
    {
    case 4:
    case 6:
    case 9:
    case 11:
        if (fecha.dia <= 30)
        {
            return true;
        }
        else
        {
            return false;
        }  
    default:
        break;
    }
}

int pedirFecha()
{
    char input[4];
    char f_ddmmyyyy[8];
    bool esvalido;
    int i = 0;
    struct Fecha fecha;
    int aux, fecha_int;

    f_ddmmyyyy[0] = 0;

    while (true)
    {
        printf("EL FORMATO DEBE SER DD/MM/YYYY.\nPor ejemplo:\ndia: 20\nmes: 03\nanio: 2023\n");
        //Pido dia
        while (true)
        {
            printf("Ingrese el dia: ");
            gets(input);

            if (validarEntero(input) && strlen(input) == 2 && input[0] != ' ')
            {
                aux = strtol(input,NULL,10);
                if (aux > 0 && aux < 32)
                {
                    fecha.dia = aux;
                    strcat(f_ddmmyyyy, input);
                    break;
                }    
            }
        }
    
        //pido mes
        while (true)
        {
            printf("Ingrese el mes: ");
            gets(input);

            if (validarEntero(input) && strlen(input) == 2 && input[0] != ' ')
            {
                aux = strtol(input,NULL,10);
                if (aux > 0 && aux < 13)
                {
                    fecha.mes = aux;
                    strcat(f_ddmmyyyy, input);
                    break;
                }    
            }
        }

        //pido anio
        while (!esvalido)
        {
            printf("Ingrese el anio: ");
            gets(input);

            if (validarEntero(input) && strlen(input) == 4 && input[0] != ' ')
            {
                aux = strtol(input,NULL,10);
                if (aux > 0 && aux <= 2023)
                {
                    fecha.anio = aux;
                    strcat(f_ddmmyyyy, input);
                    break;
                }    
            }
        }
        break;
    
    }

    if (verificarFecha(fecha))
    {
        //Si la fecha es valida la paso a entero
        fecha_int = strtol(f_ddmmyyyy, NULL, 10);
        return fecha_int;
    }

    return -1;

}