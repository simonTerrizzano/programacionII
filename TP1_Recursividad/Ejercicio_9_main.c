#include "Ejercicio_9.c"

int main(void){

    bool res;

    int ingreso_normalizado;
    ingreso_normalizado = ingreso_normalizado_enteros(0,99999999);
    
    res = divpor7(ingreso_normalizado);

    if (res==true)
    {
        printf("El número es divisible por 7");
    }
    else{
        printf("El número no es divisible por 7");
    }

    printf("\n\n");

    //system("PAUSE");
    exit(EXIT_SUCCESS);
    return 0;

}
