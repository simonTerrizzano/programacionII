#include <stdio.h>
#include <math.h>

float cocientes();

int main(){
    int m,n,valor;
    float cast;
    printf("Ingresar dos numeros enteros para obtener el cociente de ambos:\n");
    printf("Ingrese el primer numero:\n");
    scanf("%d",&m);
    printf("Ingrese el segundo numero:\n");
    scanf("%d",&n);
    valor=cocientes(m,n);
    cast=valor;
    printf("%.4f",cast);
}


float resta=0;
float cocientes(int m,int n){
    
    if (m<n){
        return m-n;
    }
    else{
        resta+=1;
        cocientes(m-n,n);
        return resta;
     }
}