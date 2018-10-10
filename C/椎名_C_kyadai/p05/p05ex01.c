/*p05ex01.c*/

#define _USE_MATH_DEFINES

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(void)
{
	int i;
//	char buff[256];

//	fgets(buff,12,stdin);
//	sscanf(buff,"%d",&buff);	

	for(i=0;i<=90;i++)
	{
		printf("%d\t%1.8lf\t%1.8lf\n",i,sin((double)i/180*M_PI),cos((double)i/180*M_PI));
	}

RETURN:
	return 0;
}
//////////////////////

//////////////////////
