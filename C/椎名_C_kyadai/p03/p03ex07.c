/*p03ex07.c*/


#include<stdio.h>
#include<math.h>

int main(void)
{
	unsigned int x, y1 = 0, y2 = 0, y3 = 0, y4 = 0;

	printf("\tx\ty1\t y2\ty3\t y4\n");
	for (x = 1; x <= 100; x++)
	{
		y1 = x % 2 == 0 ? 10 : 5;
		if (x % 4 == 0)
		{
			y2 = x - 1;
		}
		else if (x % 4 == 3)
		{
			y2 = x + 1;
		}
		else
		{
			y2 = x;
		}
		y3 = x % 4 == 0 ? 2 : x % 4;
		y4 = x % 2 == 0 ? 0 : x * 5;

		printf("%9d", x);
		printf("\t%2d", y1);
		printf("\t%3d", y2);
		printf("\t%2d", y3);
		printf("\t%3d", y4);

		puts("");
	}

RETURN:
	return 0;
}
//////////////////////

//////////////////////
