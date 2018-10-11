/*p02ex05.c*/


#include<stdio.h>
#include<math.h>

int main(void)
{
	int x,y1,y2,y3;

	printf("     x    y1    y2    y3\n");

	for(x=0;x<=100;x++)
	{
		y1=x/2;
		y2=x/3;
		y3=x/4;
		printf("%6d%6d%6d%6d\n",x,y1,y2,y3);
	}

	return 0;
}
//////////////////////

//////////////////////
