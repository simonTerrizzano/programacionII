#include "Ejercicio_6.c"

int main(void)
{
    Pila pila=p_crear();
    Cola cola=c_crear();
    Lista LR=l_crear();

    TipoElemento x;

    int arrPilas[TAMANIO_MAXIMO_PILAS];
    memset(arrPilas, 0, TAMANIO_MAXIMO_PILAS*sizeof(int));

    int arrColas[TAMANIO_MAXIMO_COLAS];
    memset(arrPilas, 0, TAMANIO_MAXIMO_COLAS*sizeof(int));

    int j=0;
    int cantingreso;
    int i;
    int intentos=3;

    bool salir=false;

    printf("Ingrese la cantidad de elementos de la Pila entre 0 y %i",TAMANIO_MAXIMO_PILAS);
    cantingreso = ingreso_normalizado_enteros(0,TAMANIO_MAXIMO_PILAS);


    if (cantingreso>0)
    {
        printf("Carga de la Pila (No se permiten valores repetidos)\n");
        for (i = 0; i < cantingreso; i++)
        {
            intentos=3;
            salir=false;
            while(salir!=true||intentos==0){
                printf("Quedan %i intentos.\n", intentos);
                printf("Ingrese el %iº elemento: ",i+1);
                x = te_crear(ingreso_normalizado_enteros(1,100));
                if (numeroyaencontrado(x->clave,arrPilas,j)!=true)
                {
                    p_apilar(pila,x);
                    arrPilas[j]=x->clave;
                    j++;
                    salir=true;
                }else{
                    printf("No se permite ingresar números repetidos.\n");
                    intentos--;
                }
            }
            
        }
    }

    printf("Ingrese la cantidad de elementos de la Cola entre 0 y %i",TAMANIO_MAXIMO_COLAS);
    cantingreso = ingreso_normalizado_enteros(0,TAMANIO_MAXIMO_COLAS);

    if (cantingreso>0)
    {
        printf("Carga de la Cola (No se permiten valores repetidos)\n");
        for (i = 0; i < cantingreso; i++)
        {
            salir=false;
            intentos=3;
            while(salir!=true||intentos==0){
                printf("Quedan %i intentos.\n", intentos);
                printf("Ingrese el %iº elemento: ",i+1);
                x = te_crear(ingreso_normalizado_enteros(1,100));
                if (numeroyaencontrado(x->clave,arrColas,j)!=true)
                {
                    c_encolar(cola,x);
                    arrColas[j]=x->clave;
                    j++;
                    salir=true;
                }else{
                    printf("No se permite ingresar números repetidos.\n");
                    intentos--;
                }
            }
            
        }
    }

    LR=comunPilaCola(cola,pila);
    printf("Elementos en común: \n");

    for (i = 1; i <= l_longitud(LR); i++)
    {
        x=l_recuperar(LR,i);

        printf(" %i:%s ",x->clave,(char*)x->valor);

    }
    
    return 0;
}
