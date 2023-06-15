#include "conjuntos_listas.c"
#include "listas_apuntadores.c"
#include "tipo_elemento.c"
#include "funciones_conjuntos.c"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


bool transitividadConjuntos(Conjunto conjunto1, Conjunto conjunto2, Conjunto conjunto3){
    if(cto_cantidad_elementos(cto_interseccion(conjunto1, conjunto2)) == cto_cantidad_elementos(conjunto1)){
        if (cto_cantidad_elementos(cto_interseccion(conjunto2, conjunto3)) == cto_cantidad_elementos(conjunto2))
        {
            return true;
        }
    }
    return false;
}

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    TipoElemento X;
    Conjunto conj1 = cto_crear();
    Conjunto conj2 = cto_crear();
    Conjunto conj3 = cto_crear();
    randomizarConjunto(&conj1,5,5,0);
    randomizarConjunto(&conj2,10,10,0);
    randomizarConjunto(&conj3,15,15,0);
    printf("====================================\n");
    printf("CONTENIDO DE LOS CONJUNTOS: \n");
    cto_mostrar(conj1);
    printf("-------------------------------\n");
    cto_mostrar(conj2);
    printf("-------------------------------\n");
    cto_mostrar(conj3);
    printf("====================================\n");
    
    if (transitividadConjuntos(conj1,conj2,conj3))
    {
        printf("EL CONJUNTO 1 ES SUB CONJUNTO DEL CONJUNTO 3 \n");
    }
    else{
        printf("EL CONJUNTO 1 NO ES SUB CONJUNTO DEL CONJUNTO 3 \n");
    }
    system("PAUSE");
    return 0;


}
