#include "Ejercicio_1.c"

int main(void)
{
    bool res;
    char stringAevaluar[100];

    int largo;

    ingreso_normalizado_string(stringAevaluar,20);
    
    largo=strlen(stringAevaluar);

    res=palindromo(stringAevaluar,0,largo-1);

    if (res==true)
    {
        printf("El string ingresado es palindromo");
    }
    else{
        printf("El string ingresado no es palindromo");
    }

    printf("\n\n");

    system("PAUSE");

    return 0;
}
