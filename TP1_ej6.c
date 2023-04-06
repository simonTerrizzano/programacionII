#include <stdio.h>
#include <string.h>

int mafia();

int main(){
    int numero, acu=0;
    printf("Ingrese el nivel de seguridad que pretende para la reunion:\n");
    scanf("%d",&numero);
    mafia(numero, acu);
}


int reunion;
int i;
int mafia(int numero,int acu){
    if (numero==0){
        return 1;
    }else{   
            if (acu==0){
                printf("(-.-)\n");
            }else{
                for (i=0;i<acu;++i){
                    printf("(-.");
                }printf("(-.-)");
                for (i=0;i<acu;++i){
                    printf(".-)");
                }printf("\n");
                
            }
            mafia(numero-1,acu+1);
    }


}