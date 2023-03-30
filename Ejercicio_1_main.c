#include "Ejercicio_1.c"

int main(void)
{
    bool res;
    char stringAevaluar[100];
    char stringNormalizado[20];

    int i,j,largo;
    int check=1;

    while (check!=0)
    {
        printf("Ingrese un string:");
        fgets(stringAevaluar,100,stdin);
        printf("%s",stringAevaluar);

        if (strlen(stringAevaluar)>20)
        {
            printf("El string debe tener menos de 20 caracteres\n");
        }
        else{
            check=0;
        } 
    }
    
    quitaespacios(stringAevaluar,stringNormalizado);
    quitasalto(stringAevaluar,stringNormalizado);
    toupper(stringNormalizado);

    res=palindromo(stringNormalizado,0,largo-1);

    if (res==true)
    {
        printf("El string ingresado es palindromo");
    }
    else{
        printf("El string ingresado no es palindromo");
    }
    return 0;
}
