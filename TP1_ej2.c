#include <stdio.h>
#include <math.h>

int calcular_producto();
int main(){

    int primer_numero, segundo_numero,valor;
    printf("Ingrese dos numeros enteros para calcular el producto de ambos\n ");
    printf("Ingrese el primer numero: \n");
    scanf("%d",&primer_numero);
    printf("Ingrese el segundo numero\n");
    scanf("%d",&segundo_numero);
    valor=(calcular_producto(primer_numero,segundo_numero));
    printf("El valor de calcular el producto de los numeros es: ");printf("%d",valor);

}
int n;
int calcular_producto(int primer_numero, int segundo_numero){
    
    if (segundo_numero==0){
        return 1;
    }else{
        n+=primer_numero;
        (calcular_producto(primer_numero,segundo_numero-1));

        return n;
    } 
    
}