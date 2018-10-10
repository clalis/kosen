/*p02ex02.c*/


#include<stdio.h>
#include<math.h>

int main(void)
{
	int x,y,y2,y3,y4;

	printf("  x   y    y^2       y^3          y^4\n");

	for(x=1;x<=100;x++)
	{
		y=x*5;
		y2=pow(y,2);
		y3=pow(y,3);
		y4=pow(y,4);

		printf("%3d %3d %6d %9d %12d\n",x,y,y2,y3,y4);
	}

	return 0;
}
//////////////////////

//////////////////////
