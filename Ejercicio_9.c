#include "Ejercicio_9.h"

bool divpor7(int numavalid){
    int dig;
    if (numavalid<70){
        if (numavalid%7==0)
        {
            return true;
        }
        else{
            return false;
        }
    }
    dig=numavalid%10;
    numavalid=numavalid/10;
    numavalid-=dig*2;
    return divpor7(numavalid);
}