/*p03ex04.c*/


#include<stdio.h>
#include<math.h>

int main(void)
{
	int num,i;
	char buff[256];

	fgets(buff, 255, stdin);
	sscanf(buff, "%d", &num);

	for(i = 1;i <= num;i++)
	{
		if(i % 5 != 0)
		{
			printf("*");
		}
		else
		{
			printf("-");
		}
	}

	return 0;
}
//////////////////////

//////////////////////
