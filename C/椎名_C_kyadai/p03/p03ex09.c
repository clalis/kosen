/*p03ex09.c*/


#include<stdio.h>
#include<math.h>

int main(void)
{
	int num, i, j;
	char buff[64];

	fgets(buff, 12, stdin);
	sscanf(buff, "%d", &num);

	for (i = 0; i < num; i++)
	{
		if ((i<2) || (i>num - 3))
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
				if ((j<2) || (j>num - 3))
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
