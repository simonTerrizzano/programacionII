#include <stdio.h>
#include <math.h>

int fibonacci();

int main(){
    int serie1=1,serie2=0;
    int numero,valor;
    printf("Ingrese un numero para obtener la serie de fibonacci:\n");
    scanf("%d",&numero);
    valor=(fibonacci(numero,serie1,serie2));
    printf("El numero que ha ingresado corresponde al valor: ");printf("%d",valor);
}


int resultado;
int fibonacci(int numero,int serie1,int serie2){
    

    if (numero==0){
        return 1;
    }else {
        
        resultado=serie1+serie2;
        serie1=serie2;
        serie2=resultado;
        fibonacci(numero-1,serie1,serie2);
        return resultado;

    }


}