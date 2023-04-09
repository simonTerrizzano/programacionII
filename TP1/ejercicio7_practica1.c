#include "Ejercicio_7.h"

/*Se tiene una cadena que representa una onda digital de señales L (Low) y H (High). Se
pide obtener recursivamente la onda que representa utilizando “_” y “|”.
Ejemplos:
ondaDigital (“LHLHL”) => “_ |¯ |_|¯ |_”
ondaDigital (“HHHHLLLLHHHHHLLHH”) => “¯ ¯ ¯ ¯ | _ _ _ _ |¯ ¯ ¯ ¯ ¯ | _ _ | ¯ ¯ */

void onda_digital(char *forma_de_onda)
{
    // Si el caracter no representara LOW o HIGH, o fuera el caracter nulo, entonces corta la funcion.
    // Si la forma de onda es LOW
    if((*forma_de_onda) == 'L' || *(forma_de_onda) == 'l')
    {
	// Y la siguiente es HIGH
	
	if((*(forma_de_onda+1)) == 'H' || *(forma_de_onda+1) == 'h')
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
else if((*forma_de_onda) == 'H' || *(forma_de_onda) == 'h')
    {
	if((*(forma_de_onda + 1)) == 'L' || *(forma_de_onda+1) == 'l')
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

