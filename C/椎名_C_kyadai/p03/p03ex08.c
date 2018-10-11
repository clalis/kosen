/*p03ex08.c*/


#include<stdio.h>
#include<math.h>

int main(void)
{
	int num, i, j;
	char buff[256];

	fgets(buff, 255, stdin);
	sscanf(buff, "%d", &num);

	for (i = 0; i < num; i++)
	{
		if ((i == 0) || (i == num - 1))
		{
			for (j = 0; j < num; j++)
			{
				putchar('*');
			}
			putchar('\n');
		}
		else
		{
			for (j = 0; j < num; j++)
			{
				if ((j == 0) || (j == num - 1))
				{
					putchar('*');
				}
				else
				{
					putchar('-');
				}
			}
			putchar('\n');
		}
	}

RETURN:
	return 0;
}
//////////////////////

//////////////////////
