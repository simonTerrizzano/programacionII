#include "Ejercicio_7.c"

int main(void)
{
    char onda[100];

    printf("--Onda Digital--(Solo admite H y L para represental una onda digital alta o baja)\n");

    while (ingreso_normalizado_onda_digital(onda)!=true)
    {
    ingreso_normalizado_string(onda,80);
    if (ingreso_normalizado_onda_digital(onda)!=true)
    {
        printf("\nPor favor solo ingrese letras H o L\n");
    }
    
    }
    
    onda_digital(onda);

    printf("\n\n");

    system("PAUSE");

    return 0;
}
