/*p03ex01.c*/


#include<stdio.h>
#include<math.h>

int main(void)
{
	int num;
	char buff[10];

	fgets(buff,2,stdin);
	sscanf(buff,"%d",&num);

	if(num%2==0)
	{
		printf("even number\n");
	}

	return 0;
}
//////////////////////

//////////////////////
