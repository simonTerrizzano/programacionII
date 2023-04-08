#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// onda_digital(char *forma_onda):la funcion mostrara en pantalla el string apuntado por forma_onda representado los valores con guiones.
// La funcion solamente procesa los caracteres L y H mayusculas, cualquier otro caracter (incluso l y h(minusculas)) no pertenecen al dominio de la funcion. 
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
