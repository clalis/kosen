/*p02ex08.c*/


#include<stdio.h>
#include<math.h>

int main(void)
{
	int row,col,x,y;

	printf("row,column=");
	scanf("%d%d",&row,&col);

	for(y=0;y<row;y++)
	{
		for(x=0;x<col;x++)
		{
			printf("*");
		}
		printf("\n");
	}

	return 0;
}
//////////////////////

//////////////////////
