#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void hochimin_right(int n);
void hochimin(int n, int bkp);
int main()
{
    int x = 3;
    hochimin(x,x);
    return 0;
}

void hochimin(int n, int bkp)
{    
    if(n == 1)
    {
	//center
	printf("(-.-)");
	// right
	hochimin_right(bkp);

    }
    // left side
    else
    {

	printf("(-.");
	hochimin(n-1, bkp);
    }
	
    
}

void hochimin_right(int n)
{
    if(n==1)
	printf("");
    else
    {
	printf(".-)");
	hochimin_right(n-1);
    }
    
}
