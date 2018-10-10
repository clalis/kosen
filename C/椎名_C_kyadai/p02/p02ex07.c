/*p02ex07.c*/


#include<stdio.h>
#include<math.h>

int main(void)
{
	int num,x,y;

	printf("n=");
	scanf("%d",&num);

	for(y=0;y<num;y++)
	{
		for(x=0;x<num-y;x++)
		{
			printf("*");
		}
		printf("\n");
	}

	return 0;
}
//////////////////////

//////////////////////
