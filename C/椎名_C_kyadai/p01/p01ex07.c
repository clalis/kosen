/*p01ex07.c*/


#include<stdio.h>
#include<math.h>

int main(void)
{
	int x,y;

	printf("2数を入力--> ");

	scanf("%d%d",&x,&y);

	printf("%d÷%d=%d...%d\n",x,y,x/y,x%y);

	return 0;
}
//////////////////////
//2数を入力--> 17 7	//
//17÷7=2...3		//
//					//
//2数を入力--> 23 7	//
//23÷7=3...2		//
//////////////////////
