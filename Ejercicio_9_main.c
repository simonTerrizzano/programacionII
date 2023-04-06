#include "Ejercicio_9.c"

int main(void){

    bool res;

    char* ingreso;
    char* ptr;

    int check=0;
    int ingresonum;

    while (check!=1){
        printf("Ingrese un número entero positivo para sabes si es divisible por 7: ");
        fflush(stdin);
        fgets(ingreso,100,stdin);
        ingresonum=strtol(ingreso, &ptr, 10);
        
        quitasalto(ingreso);

        if (cadenatododigito(ingreso)!=1){
            printf("\nPor favor solo ingrese números enteros positivos\n");
        }
        else if (ingresonum>1000000000){
            printf("\nPor favor ingrese un número menor o igual a 999999999\n");
        }
        else if (ingresonum<=999999999){
            check=1;
        }
        
    }
    
    res = divpor7(ingresonum);

    if (res==true)
    {
        printf("El número es divisible por 7");
    }
    else{
        printf("El número no es divisible por 7");
    }

return 0;

}