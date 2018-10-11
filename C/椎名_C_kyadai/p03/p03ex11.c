/*p03ex11.c*/


#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(void)
{
	int a, b, c, i = 0;
	char buff[256];

	for (a = 500; a < 999; a++)
	{
		for (b = a + 1; b < 1000; b++)
		{
			for (c = b + 1; c <= 1000; c++)
			{
				if (pow(a, 2) + pow(b, 2) == pow(c, 2))
				{
					i++;
					printf("\t%3d:\t%3d\t%3d\t%3d\n", i, a, b, c);
				}
			}
		}
	}
	printf("’¼ŠpŽOŠpŒ`‚Ì‘” = %d\n", i);

	RETURN:
	return 0;
}
//////////////////////

//////////////////////
