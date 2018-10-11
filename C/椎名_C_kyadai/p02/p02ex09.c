/*p02ex09.c*/


#include "stdafx.h"

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

int main(void)
{
	int n, x, y;

	printf("n=");
	scanf("%d", &n);//fgets sscanf scanf_s?îVà»ç~égÇ§éñ

	for (y = 1; y <= (n + 1) / 2; y++)
	{
		for (x = 0; x < (n + 1) / 2 - y; x++) printf("-");
		for (x = 0; x < 2 * y - 1; x++) printf("*");
		for (x = 0; x < (n + 1) / 2 - y; x++) printf("-");

		printf("\n");
	}

	return 0;
}
