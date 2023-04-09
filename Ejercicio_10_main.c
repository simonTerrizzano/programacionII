#include "Ejercicio_10.c"


int main(int argc, char const *argv[]) {
    int contador = 0,fin = 0;
    int bomba, num;
    while (fin!=1)
    {
        printf("Valor del numero");
        num = ingreso_normalizado_enteros(0,10000);
        printf("Valor de la bomba");
        bomba= ingreso_normalizado_enteros(0,10000);
        printf("Se mostrara la lista resultante: \n");
        explocion(num, bomba, &contador);
        int* lista = explocion(num, bomba, &contador);
            for (int i = 0; i < contador; i++) {
                if (i==0)
                {
                    printf("{");
                }
                printf("%i,", lista[i]);
                if (i==contador-1)
                {
                    printf("}");
                }
                
            }
        printf("\nIngrese 1 para terminar el programa: ");
        fin = ingreso_normalizado_enteros(0,1);
    }
    return 0;
}
