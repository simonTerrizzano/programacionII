#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// onda_digital(char *forma_onda):la funcion mostrara en pantalla el string apuntado por forma_onda representando los valores con guiones.
// La funcion solamente procesa los caracteres L/l y H/h, cualquier otro caracter  no pertenecen al dominio de la funcion. 
void
onda_digital(char *forma_de_onda);
int main()
{

    onda_digital("HHHHLLLLHHHHHLLHHLLLLLLLLLLLHHHHHHHHHLHLHLHLHLHLHLHLHLH");

}
  


void
onda_digital(char *forma_de_onda)
{
    // Si el caracter no representara LOW o HIGH, o fuera el caracter nulo, entonces corta la funcion.
    // Si la forma de onda es LOW
    if((*forma_de_onda) == 'L' || *forma_de_onda == 'l')
    {
	// Y la siguiente es HIGH
	
	if((*(forma_de_onda+1)) == 'H' || *(forma_de_onda+1)) == 'h')
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
    else if((*forma_de_onda) == 'H' || *(forma_de_onda+1)) == 'h')
    {
	if((*(forma_de_onda + 1)) == 'L' || (*(forma_de_onda + 1)) == 'l')
	{
	    printf("%c",238);printf("|");
	    onda_digital(forma_de_onda+1);
	}
	else
	{
	    printf("%c",238);
	    onda_digital(forma_de_onda+1);

	}
	
    }
}
