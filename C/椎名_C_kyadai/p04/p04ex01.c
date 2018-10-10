/*p04ex01.c*/


#include<stdio.h>
#include<math.h>

int main(void)
{
	int i,j,score[10]={15,8,12,18,20,20,9,16,20,17};
	char buff[256];

//	fgets(buff,12,stdin);
//	sscanf(buff,"%d",&buff);

	for(i=0;i<sizeof(score)/4;i++)
	{
		printf("%d\t%d\t:",i+1,score[i]);
		for(j=1;j<=score[i];j++)
		{
			if(j%5==0)
			putchar('|');
			else
			putchar('*');
		}
		putchar('\n');
	}

RETURN:
	return 0;
}
//////////////////////

//////////////////////
