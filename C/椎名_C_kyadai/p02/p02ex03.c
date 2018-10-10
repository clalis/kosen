/*p02ex03.c*/


#include<stdio.h>
#include<math.h>

int main(void)
{
	int x,y1,y2,y3,y4;

	printf("   x   y1   y2   y3     y4\n");

	for(x=1;x<=100;x++)
	{
		y1=101-x;
		y2=x*3;
		y3=x*4-3;
		y4=pow(x,2)*5;

		printf("%4d %4d %4d %4d %6d\n",x,y1,y2,y3,y4);
	}

	return 0;
}
//////////////////////

//////////////////////
