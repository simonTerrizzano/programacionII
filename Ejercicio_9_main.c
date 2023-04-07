#include "Ejercicio_9.c"

int main(void){

    bool res;

    int ingreso_normalizado;
    ingreso_normalizado = ingreso_normalizado_enteros_positivos(0,99999999);
    
    res = divpor7(ingreso_normalizado);

    if (res==true)
    {
        printf("El número es divisible por 7");
    }
    else{
        printf("El número no es divisible por 7");
    }

    return 0;

}