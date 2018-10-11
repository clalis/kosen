/*p02ex01.c*/


#include<stdio.h>
#include<math.h>

int main(void)
{
	int x,x2,x3,i;
	
	printf("  x   x^2     x^3\n");
	for(x=1;x<=100;x++)
	{
		x++;
		x2=pow(x,2);
		x3=pow(x,3);
		
		printf("%3d %5d %7d\n",x,x2,x3);
	}

	return 0;
}
//////////////////////

//////////////////////
