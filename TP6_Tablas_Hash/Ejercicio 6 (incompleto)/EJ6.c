#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tabla_hash_lista_colisiones.c"


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

int convertirFechaAInt(const char* fechaI) {
    char fecha[9];  // Considera el tamaño adecuado para la cadena de fecha
    strncpy(fecha, fechaI, sizeof(fecha)-1);
    fecha[sizeof(fecha)-1] = '\0';

    char *dia_str, *mes_str, *anio_str;
    int dia, mes, anio, fecha_num;

    dia_str = strtok(fecha, "/");
    mes_str = strtok(NULL, "/");
    anio_str = strtok(NULL, "/");

    dia = strtol(dia_str, NULL, 10);
    mes = strtol(mes_str, NULL, 10);
    anio = strtol(anio_str, NULL, 10);

    fecha_num = anio * 10000 + mes * 100 + dia;

    return fecha_num;
}

//=================================================

/*Se desea poder implementar una solución para encontrar de forma rápida los datos de
las personas que a una fecha determinada se presentaron a vacunar contra el COVID.
Es decir dada una fecha determinada debería obtener quienes se vacunaron. De cada
persona se guarda básicamente el DNI, Apellido y Nombre. Se debe además hacer una
pantalla de carga donde se pueda especificar la fecha y los datos de las personas que
se vacunaron en esa fecha.  */



int functionHash(int fecha)
{
    return fecha % 30003;
}

void Alta_Persona(TablaHash th)
{
    Lista persona = l_crear();
    char datos[4][10] = {"fecha","dni", "nombre", "apellido"};
    int i = 1;
    bool esValido;

    printf("=======================\n");
    printf("ALTA DE PERSONA\n");
    printf("FORMATO DE FECHA AA/MM/DD\n");
    printf("=======================\n");
    while (i <= 4)
    {
        esValido = false;
        while (esValido != true)
        {
            char* input = malloc(20*sizeof(char));
            printf("Ingrese %s de la persona: ", datos[i-1]);
            gets(input);
            //printf("%s , %d",input,convertirFechaAInt(input));
            
            switch (i)
            {
            case 1:
                if (strlen(input) == 8 && convertirFechaAInt(input) != -1) 
                {
                    l_agregar(persona,te_crearConValor(i,convertirFechaAInt(input)));
                    esValido = true;
                }
                break;
            case 2:
                if (validarEntero(input) && input[0] != ' ')
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
            case 4:
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
            free(input);
        }
        i++;
    }

    
    //Cargo la persona a la tabla hash
    int fecha_int = (int) l_recuperar(persona,1)->valor;
    printf("\n\nFecha ingresada en int : %d\n\n",fecha_int);
    TipoElemento x = te_crearConValor(fecha_int,persona);
    th_insertar(th,x);

    printf("Persona cargada con exito\n");
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

Lista Buscar_Personas(TablaHash th, int fecha)
{
    Lista personas = l_crear();
    TipoElemento datos = th_recuperar(th,fecha);
    if (datos != NULL)
    {
        personas = (Lista) datos->valor;  
    }
    else{
        printf("No hay datos de personas atendidas esa fecha\n");
    }
    return personas;
}

void Mostrar_Alumno(Lista personas)
{
    if (l_es_vacia(personas)) printf("NO EXISTE REGISTROS DE PERSONAS DENTRO DE LA FECHA DADA EN LA BASE DE DATOS\n");
    else
    {
        printf("\nFECHA: %s:\n", l_recuperar(personas,1)->valor);
        printf("=============================================\n");
        printf("- Nombre: %s\n", l_recuperar(personas,2)->valor);
        printf("- Apellido: %s\n", l_recuperar(personas,3)->valor);
        printf("=============================================\n\n");
    }

}

int main()
{

    TablaHash th = th_crear(3003, &functionHash);
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
                    printf("fecha (formato AA/MM/DD):");
                    gets(opcion);
                    if (strlen(opcion) == 8) 
                    {
                        fecha = convertirFechaAInt(opcion);
                        printf("\n\nFecha ingresada en int : %d\n\n",fecha);
                        Lista personas = Buscar_Personas(th,fecha);
                        if (personas != NULL) {
                            l_mostrarLista(personas);
                        } else {
                            printf("No hay personas atendidas en esa fecha.\n");
                        }
                    }
                    else{
                        printf("FECHA INCORRECTA\n");
                    }
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
