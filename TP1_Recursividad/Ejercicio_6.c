#include "Ejercicio_6.h"

/*Se conoce que la mafia china es muy organizada y protege mucho a sus miembros,
cuando deciden asistir a una reunión se dispone de una cantidad de chinos que
asisten, y ellos se ubican de forma que al mirarlos frontalmente generan cierto respeto
y temor. A continuación, se tiene una serie de posibles reuniones y su nivel y la
apariencia que se tiene del grupo que va a la reunión vistos frontalmente:
Nivel reunión Vista frontal de la delegación:
---------------------------------------------
|                1 (-.-)                    |
|             2 (-.(-.-).-)                 |
|          3 (-.(-.(-.-).-).-)              |
|       4 (-.(-.(-.(-.-).-).-).-)           |
---------------------------------------------
Considerando esta descripción, diseñar los procesos recursivos que permitan mostrar
la apariencia del grupo de chinos que asisten a una reunión de nivel n. 
*/

void mafiachina(int num1,int num2,int num1copia){
    if (num1>1)
    {
        if (num2==0)//Si es 0 realiza los de la izquierda
        {
            printf("(-.");
            return mafiachina(num1-1,num2,num1copia);
        }
        if (num2==1)//Si es 1 realiza los de la derecha
        {
            printf(".-)");
            return mafiachina(num1-1,num2,num1copia);
        }
    }
    else{
        if (num2==0)
        {
            printf("(-.-)");
            return mafiachina(num1copia,1,num1);
        }
    }
}