#include "punto4.c"

int main()
{
    unsigned int base;
    int numero_a_convertir;
    bool salida = false;
    while(!salida)
    {
	printf("\nIngrese un numero a convertir");
	numero_a_convertir = ingreso_normalizado_enteros(-1000, 1000, &salida);
	printf("\nPorfavor ingrese base");
	base = ingreso_normalizado_enteros(2, 16, &salida);
	p_numero_a_base(numero_a_convertir, base);
	

    }
}
