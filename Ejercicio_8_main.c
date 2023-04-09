#include "Ejercicio_8.c"

int main(void)
{
    
    int dimension,suma;

    printf("--Cantidad de elementos del conjunto--");
    dimension=ingreso_normalizado_enteros(0,10);

    int conjunto[dimension];
    int subconjuntos[dimension];
    int cont=0;
    printf("--Elementos del conjunto--");
    while (cont!=dimension)
    {
        printf("\n%iº número\n",cont+1);
        conjunto[cont]=ingreso_normalizado_enteros(-100,100);
        cont++;
    }

    printf("--Cantidad que se querra que sumen los subconjuntos--");

    suma=ingreso_normalizado_enteros(-1000,1000);

    encontrarSubconjuntosQueSumanN(conjunto,dimension,suma,subconjuntos,0,0,suma,0);


    printf("\n\n");

    system("PAUSE");

    return 0;
}
