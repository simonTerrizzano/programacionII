#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void
onda_digital(char *forma_de_onda);
int main()
{

    onda_digital("HHHHLLLLHHHHHLLHH");

}
  

// onda_digital(char *const_char): recibe una cadena de caracteres indicando los niveles de la <<digital_wave>>.
// imprime la señal represantada con guiones.

void
onda_digital(char *forma_de_onda)
{
    // Si el caracter no representara LOW o HIGH, o fuera el caracter nulo, entonces corta la funcion.
    // Si la forma de onda es LOW
    if((*forma_de_onda) == 'L')
    {
	// Y la siguiente es HIGH
	
	if((*(forma_de_onda+1)) == 'H')
	{
	   
	    // Imprimimos low y comienza a subir
	    printf("_|");
	    onda_digital(forma_de_onda+1);
	}
	else
	{
	    // imprimimos simplemente un LOW
	    printf("_");
	    onda_digital(forma_de_onda+1);
	}
	
    }
    // lo siguiente es analogo a lo expuesto anteriormente.
    else if((*forma_de_onda) == 'H')
    {
	if((*(forma_de_onda + 1)) == 'L')
	{
	    printf("¯|");
	    onda_digital(forma_de_onda+1);
	}
	else
	{
	    printf("¯");
	    onda_digital(forma_de_onda+1);

	}
	
    }
}
