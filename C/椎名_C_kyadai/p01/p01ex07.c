/*p01ex07.c*/


#include<stdio.h>
#include<math.h>

int main(void)
{
	int x,y;

	printf("2êîÇì¸óÕ--> ");

	scanf("%d%d",&x,&y);

	printf("%dÅÄ%d=%d...%d\n",x,y,x/y,x%y);

	return 0;
}
//////////////////////
//2êîÇì¸óÕ--> 17 7	//
//17ÅÄ7=2...3		//
//					//
//2êîÇì¸óÕ--> 23 7	//
//23ÅÄ7=3...2		//
//////////////////////
