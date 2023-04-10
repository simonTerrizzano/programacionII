#include "Ejercicio_8.c"

int main(void)
{
    
    int dimension,suma;

    printf("--Cantidad de elementos del conjunto--");
    dimension=ingreso_normalizado_enteros(0,20);

    int conjunto[dimension];
    int subconjuntos[dimension];
    int cont=0;
    int check=0;
    printf("--Elementos del conjunto--");
    while (cont!=dimension)
    {
        printf("\n%iº número\n",cont+1);
        conjunto[cont]=ingreso_normalizado_enteros(-100000,100000);
        cont++;
    }

    printf("--Cantidad que se querra que sumen los subconjuntos--");
    while (check!=1)
    {
    if (suma=ingreso_normalizado_enteros(-100000,100000)==0)
    {
        printf("La suma no puede ser 0");
        suma=ingreso_normalizado_enteros(-100000,100000);
        
    }else{
        check=1;
    }

    }
    
    
    

    encontrarSubconjuntosQueSumanN(conjunto,dimension,suma,subconjuntos,0,0,suma,0);


    printf("\n\n");

    //system("PAUSE");
    exit(EXIT_SUCCESS);
    return 0;
}
