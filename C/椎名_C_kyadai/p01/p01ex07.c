/*p01ex07.c*/


#include<stdio.h>
#include<math.h>

int main(void)
{
	int x,y;

	printf("2�������--> ");

	scanf("%d%d",&x,&y);

	printf("%d��%d=%d...%d\n",x,y,x/y,x%y);

	return 0;
}
//////////////////////
//2�������--> 17 7	//
//17��7=2...3		//
//					//
//2�������--> 23 7	//
//23��7=3...2		//
//////////////////////
