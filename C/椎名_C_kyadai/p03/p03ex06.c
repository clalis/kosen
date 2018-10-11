/*p03ex06.c*/


#include<stdio.h>
#include<math.h>

int main(void)
{
	int num;
	char buff[256];

	fgets(buff, 255, stdin);
	sscanf(buff, "%d", &num);

	if(num % 2 == 0 && num % 3 == 0)
	{
		printf("2x en 3x\n");
	}
	else if(num % 2 == 0 || num % 3 == 0)
	{
		if(num % 2 == 0)
		{
			printf("2x\n");
		}
		else
		{
			printf("3x\n");
		}
	}
	else
	{
		printf("not2xnot3x\n");
	}

RETURN:
	return 0;
}
//////////////////////

//////////////////////
