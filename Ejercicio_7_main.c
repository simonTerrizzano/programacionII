#include "Ejercicio_7.c"
#define SIZE_BUFFER 1000
int main(void)
{
    char onda[SIZE_BUFFER];
    int ingreso_ok;
    printf("--Onda Digital--(Solo admite H y L para represental una onda digital alta o baja)\n");
    fgets(onda, SIZE_BUFFER, stdin);
    onda_digital(onda);
  
    

    printf("\n\n");

    //ssystem("PAUSE");

    return 0;
}
