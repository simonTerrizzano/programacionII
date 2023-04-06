#include "Ejercicio_10.c"


int main(void)
{
    int check=0;
    char ingreso[15];
    int num_a_explotar;
    char* ptr;
    int bomba;

    while (check!=1){
        printf("Ingrese un número entero positivo a explotar entre 1 y 1000: ");
        fflush(stdin);
        fgets(ingreso,10,stdin);
        num_a_explotar=strtol(ingreso, &ptr, 10);
        
        quitasalto(ingreso);

        if (cadenatododigito(ingreso)!=1){
            printf("\nPor favor solo ingrese números enteros positivos\n");
        }
        else if (num_a_explotar>1000 || num_a_explotar<1){
            printf("\nPor favor ingrese un número menor o igual a 1000\n");
        }
        else if (num_a_explotar<=1000){
            check=1;
        }
    }
    check=0;
        while (check!=1){
        printf("Ingrese la bomba (números enteros positivos entre 2 y 999999999): ");
        fflush(stdin);
        fgets(ingreso,10,stdin);
        bomba=strtol(ingreso, &ptr, 10);
        
        quitasalto(ingreso);

        if (cadenatododigito(ingreso)!=1){
            printf("\nPor favor solo ingrese números enteros positivos\n");
        }
        else if (bomba>999999999){
            printf("\nPor favor ingrese un número menor o igual a 999999999\n");
        }
        else if (bomba<2)
        {
            printf("\nPor favor ingrese un número mayor a 2\n");
        }
        
        else if (bomba<=1000){
            check=1;
        }
    }
    explosivo(num_a_explotar,bomba);

    return 0;
}
