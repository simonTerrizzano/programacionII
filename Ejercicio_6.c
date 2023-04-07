#include "Ejercicio_6.h"

void mafiachina(int num1,int num2,int num1copia){
    if (num1!=1)
    {
        if (num2==0)
        {
            printf("(-.");
            return mafiachina(num1-1,num2,num1copia);
        }
        if (num2=1)
        {
            printf(".-)");
            return mafiachina(num1-1,num2,num1copia);
        }
    }
    else{
        if (num2==0)
        {
            printf("(-.-)");
            return mafiachina(num1copia,1,num1copia);
        }
    }
}