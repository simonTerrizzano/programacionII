#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "listas.c"
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
//=================================================








/*Desarrollar un algoritmo que dado un archivo que contendrá los datos de alumnos 
(legajo, apellido, nombres, domicilio, TE) genere una tabla hash donde la clave será el 
legajo y se guardará como dato la posición física del registro para realizar accesos 
directos. Hacer un ABM para poder cargar manualmente el archivo. El “legajo" es un 
valor de 6 dígitos. */




int functionHash(int legajo)
{
    return legajo % 2003;
}

void Alta_Alumno(TablaHash th)
{
    Lista alumno = l_crear();
    char datos[5][10] = {"legajo", "nombre", "apellido", "domicilio", "telefono"};
    int i = 1;
    bool esValido;

    printf("=======================\n");
    printf("ALTA DE ALUMNO\n");
    printf("=======================\n");
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
                    l_agregar(alumno,te_crearConValor(i,input));
                    esValido = true;
                }
                break;
            case 2:
                if (validarLetras(input) && input[0] != ' ')
                {
                    l_agregar(alumno,te_crearConValor(i,input));
                    esValido = true;
                }
                break;
            case 3:
                if (validarLetras(input) && input[0] != ' ')
                {
                    l_agregar(alumno,te_crearConValor(i,input));
                    esValido = true;
                }
                break;
            case 4:
                if (validarLetrasYNumeros(input) && input[0] != ' ')
                {
                    l_agregar(alumno,te_crearConValor(i,input));
                    esValido = true;
                }
                break;
            case 5:
                if (validarEntero(input) && input[0] != ' ' && strtol(input,NULL,10) > 0)
                {
                    l_agregar(alumno,te_crearConValor(i,input));
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

    
    //Cargo el alumno a la tabla hash
    char* legajo_char = (char*) l_recuperar(alumno,1)->valor;
    int legajo = strtol(legajo_char,NULL,10);
    TipoElemento x = te_crearConValor(legajo,alumno);
    th_insertar(th,x);

    printf("Alumno cargado con exito\n");
}

void Baja_Alumno (TablaHash th, int legajo)
{

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

void Modificar_Alumno(TablaHash th, int legajo)
{

    
    if (th_recuperar(th,legajo) == NULL)
    {
        printf("El legajo no esta registrado en el sistema.\n");
    }
    else
    {
        Lista alumno_mod = l_crear();
        TipoElemento datos = th_recuperar(th,legajo);
        Lista alumno = (Lista) datos->valor;
        char textos[5][10] = {"legajo", "nombre", "apellido", "domicilio", "telefono"};
        int i = 1;
        bool Esvalido;
        
        l_agregar(alumno_mod,te_crearConValor(0,l_recuperar(alumno,1)->valor));
        l_agregar(alumno_mod,te_crearConValor(0,l_recuperar(alumno,2)->valor));
        l_agregar(alumno_mod,te_crearConValor(0,l_recuperar(alumno,3)->valor));
        l_agregar(alumno_mod,te_crearConValor(0,l_recuperar(alumno,4)->valor));
        l_agregar(alumno_mod,te_crearConValor(0,l_recuperar(alumno,5)->valor));

        printf("Datos actuales del legajo %s:\n", l_recuperar(alumno,1)->valor);
        printf("=============================================\n");
        printf("1. Nombre: %s\n", l_recuperar(alumno,2)->valor);
        printf("2. Apellido: %s\n", l_recuperar(alumno,3)->valor);
        printf("3. Domicilio: %s\n", l_recuperar(alumno,4)->valor);
        printf("4. Telefono: %s\n", l_recuperar(alumno,5)->valor);
        printf("=============================================\n");

        printf("DEJAR EN BLANCO LOS QUE NO SE QUIEREN MODIFICAR\n");

        while (i < l_longitud(alumno))
        {
            Esvalido = false;
            
            while (Esvalido != true)
            {
                char* opcion = malloc(sizeof(char));
                printf("Ingrese nuevo %s: ", textos[i]);
                gets(opcion); 

                if ((validarLetras(opcion) && i < 3 || (validarEntero(opcion) && i == 4 && strtol(opcion,NULL,10) > 0) || (validarLetrasYNumeros(opcion) && i == 3)))
                {
                    l_eliminar(alumno_mod,i+1);
                    l_insertar(alumno_mod,te_crearConValor(0,opcion),i+1);
                    Esvalido = true;
                }
                else 
                {
                    if (opcion[0] == 0) Esvalido = true;
                    else printf("Dato incorrecto.\n");
                }
                
            }

            i++;
        }

        datos = te_crearConValor(legajo,alumno_mod);
        th_eliminar(th,legajo);
        th_insertar(th,datos);
        printf("ALUMNO MODIFICADO CON EXITO.\n");
        
    }
}

Lista Buscar_Alumno(TablaHash th, int legajo)
{
    Lista alumno = l_crear();
    TipoElemento datos = th_recuperar(th,legajo);
    if (datos != NULL)
    {
        alumno = (Lista) datos->valor;  
    }
    
    return alumno;
}

void Mostrar_Alumno(Lista alumno)
{
    if (l_es_vacia(alumno)) printf("EL ALUMNO NO EXISTE EN LA BASE DE DATOS\n");
    else
    {
        printf("\nLEGAJO: %s:\n", l_recuperar(alumno,1)->valor);
        printf("=============================================\n");
        printf("- Nombre: %s\n", l_recuperar(alumno,2)->valor);
        printf("- Apellido: %s\n", l_recuperar(alumno,3)->valor);
        printf("- Domicilio: %s\n", l_recuperar(alumno,4)->valor);
        printf("- Telefono: %s\n", l_recuperar(alumno,5)->valor);
        printf("=============================================\n\n");
    }

}

int main()
{

    TablaHash th = th_crear(2003, &functionHash);
    char* opcion = malloc(sizeof(char));
    bool salir = false;
    int legajo;

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
                    Alta_Alumno(th);
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
                        Modificar_Alumno(th,legajo);
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
                        Lista alumno = Buscar_Alumno(th,legajo);
                        Mostrar_Alumno(alumno);
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

