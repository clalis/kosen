/*p01ex06.c*/


#include<stdio.h>
#include<math.h>

int main(void)
{
	int x,y;

	printf("2数を入力--> ");

	scanf("%d %d",&x,&y);

	printf("%d+%d=%d\n",x,y,x+y);
	printf("%d-%d=%d\n",x,y,x-y);
	printf("%d*%d=%d\n",x,y,x*y);
	printf("%d/%d=%d\n",x,y,x/y);
	printf("%d%%%d=%d\n",x,y,x%y);

	return 0;
}
//////////////////////
//2数を入力--> 12 5	//
//12+5=17			//
//12-5=7			//
//12*5=60			//
//12/5=2			//
//12%5=2			//
//					//
//2数を入力--> 17 7	//
//17+7=24			//
//17-7=10			//
//17*7=119			//
//17/7=2			//
//17%7=3			//
//////////////////////
