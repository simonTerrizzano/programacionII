#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "listas.h"
#include "tabla_hash.h"


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








/*Desarrollar un algoritmo que dado un archivo que contendrá los datos de alumnos 
(legajo, apellido, nombres, domicilio, TE) genere una tabla hash donde la clave será el 
legajo y se guardará como dato la posición física del registro para realizar accesos 
directos. Hacer un ABM para poder cargar manualmente el archivo. El “legajo" es un 
valor de 6 dígitos. */

//Creo un struct con los datos pedidos

struct alumnoStruct
{
    int legajo;
    char nombre[50];
    char apellido[50];
    char domicilio[50];
    char telefono[50];
};


typedef struct alumnoStruct * alumno;





int functionHash(int legajo)
{
    return legajo % 2003;
}

void Alta_Alumno(TablaHash th, char nombre_archivo[], char modo[])
{


    alumno nuevo_alumno = (alumno) malloc(sizeof(struct alumnoStruct));

    char datos[5][10] = {"legajo", "nombre", "apellido", "domicilio", "telefono"};
    int i = 1;
    int j, legajo;
    bool esValido;

    printf("=======================\n");
    printf("ALTA DE ALUMNO\n");
    printf("=======================\n");
    
    //En este bucle while se piden los datos, se guardan en la estructura Alumnos
    //y luego se escribe en el archivo binario 
    while (i <= 5)
    {
        esValido = false;
        while (esValido != true)
        {
            char* input = malloc(10*sizeof(char));
            printf("Ingrese %s del alumno: ", datos[i-1]);
            gets(input);

            switch (i)
            {
            case 1:
                if (validarEntero(input) && strlen(input) == 6 && strtol(input,NULL,10) > 0) 
                {
                    legajo = strtol(input,NULL,10);
                    nuevo_alumno->legajo = legajo;
                    esValido = true;
                }
                break;
            case 2:
                if (validarLetras(input) && input[0] != ' ')
                {
                    for (j = 0; j < strlen(input); j++)
                    {
                        nuevo_alumno->nombre[j] = input[j];
                    }
                    nuevo_alumno->nombre[j] = 0; //Le indico que termina el string
                    esValido = true;
                }
                break;
            case 3:
                if (validarLetras(input) && input[0] != ' ')
                {
                    int c = strlen(input);
                    for (j = 0; j < strlen(input); j++)
                    {
                        nuevo_alumno->apellido[j] = input[j];
                    }
                    nuevo_alumno->apellido[j] = 0;
                    esValido = true;
                }
                break;
            case 4:
                if (validarLetrasYNumeros(input) && input[0] != ' ')
                {
                    for (j = 0; j < strlen(input); j++)
                    {
                        nuevo_alumno->domicilio[j] = input[j];
                    }
                    nuevo_alumno->domicilio[j] = 0;
                    esValido = true;
                }
                break;
            case 5:
                if (validarEntero(input) && input[0] != ' ' && strtol(input,NULL,10) > 0)
                {
                    for (j = 0; j < strlen(input); j++)
                    {
                        nuevo_alumno->telefono[j] = input[j];
                    }
                    nuevo_alumno->telefono[j] = 0;
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


    //Cargo la struct al archivo binario
    FILE* archivo;
    archivo = fopen(nombre_archivo, modo);
    //Valido que el archivo exista
    if (archivo == NULL)
    {
        printf("Hubo un error al cargar el alumno al sistema. Vuelva a intentarlo\n");
        return;
    }


    fseek(archivo, sizeof(alumno)*legajo, SEEK_SET);
    //Escribo en el archivo binario
    fwrite(&nuevo_alumno, sizeof(struct alumnoStruct), 1, archivo);
    fclose(archivo);

    //Creo un tipoElemento con el LEGAJO en la clave y la DIRECCION DE MEMORIA en el valor
    TipoElemento x = te_crearConValor(nuevo_alumno->legajo, nuevo_alumno);
    th_insertar(th,x); //Guardo el TipoElemento en la tabla hash

    printf("Alumno cargado con exito\n");

}

void Baja_Alumno (TablaHash th, int legajo)
{
    //Borro el alumno de la tabla hash. No se elimina del archivo binario (es un bardo borrarlo de ahi)
    if (th_recuperar(th,legajo) != NULL)
    {
        th_eliminar(th,legajo);
        printf("Alumno dado de baja con exito.\n");
    }
    else
    {
        printf("El legajo no esta registrado en el sistema.\n");
    }
    
}

//NO FUNCIONA CON LA STRUCT. Sigue funcionando con listas no la actualice 
void Modificar_Alumno(TablaHash th, alumno datos_alumno, char nombre_archivo[], char modo[])
{

    
    if (datos_alumno == NULL)
    {
        printf("El legajo no esta registrado en el sistema.\n");
    }
    else
    {

        char textos[5][10] = {"nombre", "apellido", "domicilio", "telefono"};
        char* opcion = malloc(sizeof(char));
        int i = 0;
        int j;
        int legajo = datos_alumno->legajo;
        bool Esvalido;
        

        printf("Datos actuales del legajo %d:\n", datos_alumno->legajo);
        printf("=============================================\n");
        printf("- Nombre: %s\n", datos_alumno->nombre);
        printf("- Apellido: %s\n", datos_alumno->apellido);
        printf("- Domicilio: %s\n", datos_alumno->domicilio);
        printf("- Telefono: %s\n", datos_alumno->telefono);
        printf("=============================================\n");

        printf("DEJAR EN BLANCO LOS QUE NO SE QUIEREN MODIFICAR\n");

        while (i < 4)
        {
            Esvalido = false;
            
            while (Esvalido != true)
            {
                
                printf("Ingrese nuevo %s: ", textos[i]);
                gets(opcion); 

                switch (i)
                {
                case 0:
                    if (validarLetras(opcion) && strlen(opcion) > 0 && opcion[0] != ' ')
                    {
                        //borro lo que haya antes para poner el nuevo dato
                        datos_alumno->nombre[0] = 0;
                        for (j = 0; j < strlen(opcion); j++)
                        {
                            datos_alumno->nombre[j] = opcion[j];
                        }
                        datos_alumno->nombre[j] = 0;
                        Esvalido = true;
                    }
                    break;
                case 1:
                    if (validarLetras(opcion) && strlen(opcion) > 0 && opcion[0] != ' ')
                    {
                        //borro lo que haya antes para poner el nuevo dato
                        datos_alumno->apellido[0] = 0;
                        for (j = 0; j < strlen(opcion); j++)
                        {
                            datos_alumno->apellido[j] = opcion[j];
                        }
                        datos_alumno->apellido[j] = 0;
                        Esvalido = true;
                    }
                    break;
                case 2:
                    if (validarLetrasYNumeros(opcion) && strlen(opcion) > 0 && opcion[0] != ' ')
                    {
                        //borro lo que haya antes para poner el nuevo dato
                        datos_alumno->domicilio[0] = 0;
                        for (j = 0; j < strlen(opcion); j++)
                        {
                            datos_alumno->domicilio[j] = opcion[j];
                        }
                        datos_alumno->domicilio[j] = 0;
                        Esvalido = true;
                    }
                    break;
                case 3:
                    if (validarEntero(opcion) && strlen(opcion) > 0 && opcion[0] != ' ')
                    {
                        //borro lo que haya antes para poner el nuevo dato
                        datos_alumno->telefono[0] = 0;
                        for (j = 0; j < strlen(opcion); j++)
                        {
                            datos_alumno->telefono[j] = opcion[j];
                        }
                        datos_alumno->telefono[j] = 0;
                        Esvalido = true;
                    }
                    break;
                default:
                    break;
                }

                //Si no ingresan nada se considera que no quieren modificar ese dato
                //y se pasa al siguiente
                if (opcion[0] == 0) Esvalido = true; 
            }
            opcion[0] = 0;
            i++;
        }

        FILE* archivo = fopen(nombre_archivo,modo);
        if (archivo == NULL)
        {
            printf("Hubo un error al actualizar los datos del alumno. Vuelva a intentarlo.\n");
            return;
        }

        fseek(archivo, sizeof(alumno)*legajo, SEEK_SET);
        //Escribo en el archivo binario
        fwrite(&datos_alumno, sizeof(struct alumnoStruct), 1, archivo);
        fclose(archivo);
    }
}


alumno Buscar_Alumno(TablaHash th, int legajo, char nombre_archivo[], char modo[])
{

    TipoElemento x;
    //Corroboro que el alumno exista en la tabla hash
    x = th_recuperar(th,legajo);
    if (x == NULL)
    {
        printf("El alumno no existe en el sistema.\n");
        return NULL;
    }

    FILE* archivo;
    archivo = fopen(nombre_archivo,modo);
    alumno datos_alumno = (alumno) malloc(sizeof(struct alumnoStruct));

    //Me posiciono en el archivo
    fseek(archivo, sizeof(alumno)*legajo, SEEK_SET);
    fread(&datos_alumno, sizeof(alumno), 1, archivo);
    fclose(archivo);   
    return datos_alumno; 
}


void Mostrar_Alumno(alumno datos_alumno)
{
    if (datos_alumno == NULL) printf("EL ALUMNO NO EXISTE EN LA BASE DE DATOS\n");
    else
    {
        printf("\nLEGAJO: %d:\n", datos_alumno->legajo);
        printf("=============================================\n");
        printf("- Nombre: %s\n", datos_alumno->nombre);
        printf("- Apellido: %s\n", datos_alumno->apellido);
        printf("- Domicilio: %s\n", datos_alumno->domicilio);
        printf("- Telefono: %s\n", datos_alumno->telefono);
        printf("=============================================\n\n");
    }

}

int main()
{
    char nombre_archivo[] = "datos.dat";
    char m_lectura[] = "rb";
    char m_escritura[] = "wb";
    char m_agregar[] = "r+b";
    FILE* archivo;
    TablaHash th = th_crear(2003, &functionHash);
    char* opcion = malloc(sizeof(char));
    bool salir = false;
    int legajo;

    //Creo el archivo binario
    archivo = fopen(nombre_archivo,m_escritura);
    fclose(archivo);

    salir = false;
    while (!salir)
    {
        printf("=============================\n");
        printf("Ingrese alguna opcion:\n");
        printf("1. Alta alumno\n");
        printf("2. Baja alumno\n");
        printf("3. Modificar Alumno\n");
        printf("4. Buscar alumno\n");
        printf("5. Salir\n");

        printf("Ingrese una de las opciones: ");
        gets(opcion);

        if (strlen(opcion) != 1) printf("No se ingreso ninguna opcion valida\n");
        else
        {
            switch (opcion[0])
            {
                case '1':
                    Alta_Alumno(th,nombre_archivo,m_agregar);
                    break;
                case '2':
                    printf("Ingrese el legajo del alumno a dar de baja\n");
                    printf("Legajo:");
                    gets(opcion);
                    if (validarEntero(opcion) && strlen(opcion) == 6) 
                    {
                        legajo = strtol(opcion,NULL,10);
                        Baja_Alumno(th,legajo);
                    }
                    else printf("El dato ingresado no es valido.\n");
                    
                    break;
                case '3':
                    printf("Ingrese el legajo del alumno a modificar\n");
                    printf("Legajo:");
                    gets(opcion);
                    if (validarEntero(opcion) && strlen(opcion) == 6) 
                    {
                        legajo = strtol(opcion,NULL,10);
                        alumno datos_alumno = Buscar_Alumno(th,legajo,nombre_archivo,m_lectura);
                        Modificar_Alumno(th,datos_alumno,nombre_archivo,m_agregar);
                    }
                    else printf("El dato ingresado no es valido.\n");
                    break;
                case '4':
                    printf("Ingrese el legajo del alumno a buscar\n");
                    printf("Legajo:");
                    gets(opcion);
                    if (validarEntero(opcion) && strlen(opcion) == 6) 
                    {
                        legajo = strtol(opcion,NULL,10);
                        alumno datos_alumno = Buscar_Alumno(th,legajo,nombre_archivo,m_lectura);
                        Mostrar_Alumno(datos_alumno);
                    }
                    break;
                case '5':
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

