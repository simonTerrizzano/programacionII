#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ingreso_fecha.c"
#include "tabla_hash_lista_colisiones.c"


//            FUNCIONES DE VALIDACION
//=================================================

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

int functionHashFecha(int fecha)
{
    return fecha % 30003;
}

void Alta_Persona(TablaHash th)
{
    Lista persona = l_crear();
    char datos[4][20] = {"fecha","dni", "nombre", "apellido"};
    int i = 1;
    bool esValido;
    int fecha_i;

    printf("=======================\n");
    printf("ALTA DE PERSONA\n");
    printf("=======================\n");
    while (i <= 4)
    {
        esValido = false;
        while (esValido != true)
        {
            char* input = malloc(20*sizeof(char));
            printf("Ingrese %s de la persona: ", datos[i-1]);
            if (i==1)
            {
                fecha_i = pedirFecha();
            }
            else{
                gets(input);
            }
            
            
            //printf("%s , %d",input,convertirFechaAInt(input));
            
            switch (i)
            {
            case 1:
                l_agregar(persona,te_crearConValor(i,(void*)fecha_i));
                esValido = true;
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
    system("PAUSE");
    printf("\n\nFecha ingresada en int : %d\n\n",fecha_int);
    system("PAUSE");
    TipoElemento x = te_crearConValor(fecha_int,(void*)persona);
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

void imprimirListaPersonas(Lista personas)
{
    if (l_es_vacia(personas))
    {
        printf("La lista de personas está vacía.\n");
        return;
    }
    
    Iterador iter = iterador(personas);
    while (hay_siguiente(iter))
    {
        TipoElemento dato = siguiente(iter);
        printf("Fecha: %d\n", (int)dato->valor);
        printf("DNI: %s\n", (char*)dato->valor);
        printf("Nombre: %s\n", (char*)dato->valor);
        printf("Apellido: %s\n", (char*)dato->valor);
        printf("---------------------------\n");
    }
}

Lista Buscar_Personas(TablaHash th, int fecha)
{
    Lista personas = l_crear();
    TipoElemento datos = th_recuperar(th, fecha);
    
    if (datos != NULL)
    {
        personas = (Lista)datos->valor;
        imprimirListaPersonas(personas);
    }
    else
    {
        printf("No hay datos de personas atendidas en esa fecha.\n");
    }
    
    return personas;
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
                    fecha = pedirFecha();
                    printf("\n\nFecha ingresada en int : %d\n\n",fecha);
                    system("PAUSE");
                    Lista personas = Buscar_Personas(th,fecha);
                    system("PAUSE");
                    if (personas != NULL) {
                        imprimirListaPersonas(personas);
                    } else {
                        printf("No hay personas atendidas en esa fecha.\n");
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