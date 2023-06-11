#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tabla_hash.h"
#include "listas.h"

//            FUNCIONES DE VALIDACION
//=================================================
struct Fecha
{
    int dia,mes,anio;
};
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

static const int TAMANIO_TH = 30003;

int functionHash(int fecha)
{
    return fecha % TAMANIO_TH;
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
    



        break;
    
    }

    if (verificarFecha(fecha))
    {
        //Si la fecha es valida la paso a entero
        fecha_int = strtol(f_ddmmyyyy, NULL, 10);
        return fecha_int;
    }

    //Si la fecha es incorrecta retorna -1
    return -1;

}



void Alta_Persona(TablaHash th)
{
    Lista persona = l_crear();
    char datos[4][20] = {"dni", "nombre", "apellido"};
    int i = 1;
    bool esValido, fecha_existe;
    int fecha_i;


    printf("=======================\n");
    printf("ALTA DE PERSONA\n");
    printf("=======================\n");


    //Pido la fecha
    fecha_i = pedirFecha();
    
    //Me fijo si la fecha ya existe en la tabla hash
    if (th_recuperar(th,fecha_i) != NULL) fecha_existe = true;
    else fecha_existe = false;

    while (i <= 3)
    {
        esValido = false;
        while (esValido != true)
        {
            char* input = malloc(20*sizeof(char));
            printf("Ingrese %s de la persona: ", datos[i-1]);
            gets(input);
            

            switch (i)
            {
            case 1:
                if (validarEntero(input) && input[0] != ' ')
                {
                    l_agregar(persona,te_crearConValor(i,input));
                    esValido = true;
                }
                break;
            case 2:
                if (validarLetras(input) && input[0] != ' ')
                {
                    l_agregar(persona,te_crearConValor(i,input));
                    esValido = true;
                }
                break;
            case 3:
                if (validarLetras(input) && input[0] != ' ')
                {
                    l_agregar(persona,te_crearConValor(i,input));
                    esValido = true;
                }
                break;
            default:
                break;
            }
            if (!esValido) printf("[ERROR] El dato ingresado no es valido.\n");
            
        }
        i++;
    }

    if (fecha_existe == false)
    {
        Lista l_general = l_crear();
        //Cargo la persona a la tabla hash
        TipoElemento x = te_crearConValor(fecha_i,persona);
        l_agregar(l_general,x);
        x = te_crearConValor(fecha_i,l_general);
        th_insertar(th,x);
        printf("Persona cargada con exito\n");
        return;
    }
    else
    {
        TipoElemento x = th_recuperar(th,fecha_i);

        Lista l_general = (Lista) x->valor;
        
        x = te_crearConValor(fecha_i,persona);
        l_agregar(l_general,x);
        x = te_crearConValor(fecha_i,l_general);
        th_eliminar(th,fecha_i);
        th_insertar(th,x);
        printf("Persona cargada con exito\n");
        return;
    }



}

void Baja_PersonasEnFecha (TablaHash th, int fecha)
{

    if (th_recuperar(th,fecha) != NULL)
    {
        th_eliminar(th,fecha);
        printf("Persona dada de baja con exito.\n");
    }
    else
    {
        printf("La fecha no esta registrada en el sistema.\n");
    }
    
}

void imprimirListaPersonas(TablaHash th, int fecha)
{
    int i;
    //Busco la lista
    TipoElemento x = th_recuperar(th,fecha);

    if (x == NULL)
    {
        printf("No hay datos de vacunacion en esa fecha.\n");
        return;
    }

    //Lista general (lista de listas)
    Lista personas = (Lista) x->valor;

   
    int longitud = l_longitud(personas);

    for (i = 1; i <= longitud; i++)
    {
        printf("\n");
        //Lista con datos de cada persona en particular
        Lista temp = (Lista) l_recuperar(personas,i)->valor;
        printf("DNI: %s\n", l_recuperar(temp,1)->valor);
        printf("Nombre: %s\n", l_recuperar(temp,2)->valor);
        printf("Apellido: %s\n", l_recuperar(temp,3)->valor);
        printf("==============================\n");
    }
    


}


int main()
{

    TablaHash th = th_crear(TAMANIO_TH, &functionHash);
    char* opcion = malloc(sizeof(char));
    bool salir = false;
    int fecha;

    salir = false;
    while (!salir)
    {
        printf("=============================\n");
        printf("Ingrese alguna opcion:\n");
        printf("1. Alta persona\n");
        printf("2. Buscar personas de determinada fecha\n");
        printf("3. Salir\n");

        printf("Ingrese una de las opciones: ");
        gets(opcion);

        if (strlen(opcion) != 1) printf("No se ingreso ninguna opcion valida\n");
        else
        {
            switch (opcion[0])
            {
                case '1':
                    Alta_Persona(th);
                    break;
                case '2':
                    printf("Ingrese la fecha de las personas atendidas a buscar\n");
                    fecha = pedirFecha();
                    imprimirListaPersonas(th,fecha);
                    
                    break;
                case '3':
                    salir = true;
                    break;
                default:
                    printf("No se ingreso ninguna opcion valida\n");
                    break;
            }
            opcion[0] = '\0';
        }
    }
    system("pause");
    return 0;
}
