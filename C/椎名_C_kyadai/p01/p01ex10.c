/*p01ex10.c*/


#include<stdio.h>
#include<math.h>

int main(void)
{
	int num=0;
	int keta[3];

	scanf("%d",&num);

	keta[0] = (num % 10); num /= 10;
	keta[1] = (num % 10); num /= 10;
	keta[2] = (num % 10); num /= 10;

	printf("100=>%d\n010=>%d\n001=>%d\n",keta[2],keta[1],keta[0]);

	return 0;
}
//////////////////////

//////////////////////
