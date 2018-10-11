/*p03ex03.c*/


#include<stdio.h>
#include<math.h>

int main(void)
{
	int a,b;
	char buff[256];

	fgets(buff,255,stdin);
	sscanf(buff,"%d %d",&a,&b);

	if(a>b)
	{
		printf("%d>%d\n",a,b);
	}
	else if(a<b)
	{
		printf("%d<%d\n",a,b);
	}
	else
	{
		printf("%d=%d\n",a,b);
	}

	return 0;
}
//////////////////////

//////////////////////
